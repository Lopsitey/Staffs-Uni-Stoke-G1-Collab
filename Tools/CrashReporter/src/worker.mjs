import { Buffer } from 'node:buffer';
import { inflateSync } from 'node:zlib';

const GITHUB_REPOSITORY = 'Lopsitey/Staffs-Uni-Stoke-G1-Collab';
const MAX_UPLOAD = 16 * 1024 * 1024;

export class UeCrashFormatError extends Error {}

class Cursor {
  constructor(buffer) {
    this.buffer = buffer;
    this.offset = 0;
  }

  take(length, name) {
    if (!Number.isInteger(length) || length < 0 || this.offset + length > this.buffer.length) {
      throw new UeCrashFormatError(`Truncated ${name}`);
    }
    const value = this.buffer.subarray(this.offset, this.offset + length);
    this.offset += length;
    return value;
  }

  int(name) {
    return this.take(4, name).readInt32LE();
  }

  string(name) {
    const length = this.int(`${name} length`);
    if (length < 0 || length > 4096) throw new UeCrashFormatError(`Invalid ${name} length`);
    const bytes = this.take(length, name);
    const nul = bytes.indexOf(0);
    return bytes.subarray(0, nul < 0 ? bytes.length : nul).toString('latin1');
  }
}

function decodeUeCrash(compressed) {
  let payload;
  try {
    payload = inflateSync(compressed, { maxOutputLength: 32 * 1024 * 1024 });
  } catch {
    throw new UeCrashFormatError('The upload is not a valid Unreal crash archive');
  }

  const cursor = new Cursor(payload);
  if (cursor.take(3, 'header').toString('ascii') !== 'CR1') {
    throw new UeCrashFormatError('Unsupported Unreal crash archive');
  }
  cursor.string('directory');
  cursor.string('archive');
  const declaredSize = cursor.int('archive size');
  const fileCount = cursor.int('file count');
  if (declaredSize !== payload.length || fileCount < 1 || fileCount > 32) {
    throw new UeCrashFormatError('Invalid Unreal crash archive header');
  }

  const files = new Map();
  for (let expected = 0; expected < fileCount; expected += 1) {
    if (cursor.int('file index') !== expected) throw new UeCrashFormatError('Invalid file index');
    const filename = cursor.string('filename');
    if (!filename || filename.includes('/') || filename.includes('\\')) {
      throw new UeCrashFormatError('Invalid filename');
    }
    const size = cursor.int('file size');
    if (size < 0 || size > 24 * 1024 * 1024) throw new UeCrashFormatError('Invalid file size');
    files.set(filename.toLowerCase(), Buffer.from(cursor.take(size, filename)));
  }
  if (cursor.offset !== payload.length) throw new UeCrashFormatError('Trailing archive data');
  return files;
}

function xmlValue(xml, name) {
  const escaped = name.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
  const match = new RegExp(`<${escaped}(?:\\s[^>]*)?>([\\s\\S]*?)<\\/${escaped}>`).exec(xml);
  if (!match) return '';
  return match[1]
    .replace(/^<!\[CDATA\[([\s\S]*)\]\]>$/, '$1')
    .replace(/&#x([0-9a-f]+);/gi, (_, value) => String.fromCodePoint(Number.parseInt(value, 16)))
    .replace(/&#([0-9]+);/g, (_, value) => String.fromCodePoint(Number.parseInt(value, 10)))
    .replace(/&lt;/g, '<').replace(/&gt;/g, '>')
    .replace(/&quot;/g, '"').replace(/&apos;/g, "'").replace(/&amp;/g, '&')
    .trim();
}

function plainText(value, limit) {
  let text = String(value ?? '')
    .replace(/\r\n?/g, '\n')
    .replace(/[\u0000-\u0008\u000b\u000c\u000e-\u001f\u007f]/g, '')
    .replace(/([A-Za-z]:[\\/])Users[\\/][^\\/\s]+/gi, '$1Users\\[redacted]')
    .replace(/\/(Users|home)\/[^/\s]+/g, '/$1/[redacted]')
    .replace(/\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}\b/gi, '[redacted-email]')
    .replace(/\b(?:github_pat_|gh[pousr]_)[A-Za-z0-9_]{16,}\b/g, '[redacted-token]')
    .replace(/\b(authorization|password|passwd|secret|token|api[_-]?key)\s*[:=]\s*[^\s,;]+/gi, '$1=[redacted]')
    .replace(/@/g, '@\u200b');
  if (text.length > limit) text = `${text.slice(0, limit)}\n…[truncated]`;
  return text;
}

function html(value, limit) {
  return plainText(value, limit)
    .replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
}

function formatMemoryBytes(value) {
  const bytes = Number(value);
  if (!Number.isFinite(bytes) || bytes <= 0) return value || 'Unknown';
  const gb = (bytes / (1024 * 1024 * 1024)).toFixed(1);
  return `${gb} GB`;
}

export function issueFromCrash(compressed) {
  const files = decodeUeCrash(compressed);
  const contextFile = files.get('crashcontext.runtime-xml');
  if (!contextFile) throw new UeCrashFormatError('CrashContext.runtime-xml is missing');

  const xml = contextFile.toString('utf8').replace(/^\uFEFF/, '');
  if (!xml.includes('<FGenericCrashContext>')) throw new UeCrashFormatError('Invalid crash context');

  const error = xmlValue(xml, 'ErrorMessage') || 'No error message captured';
  const comment = xmlValue(xml, 'UserDescription') || 'No player comment supplied';
  const stack = xmlValue(xml, 'CallStack') || xmlValue(xml, 'PCallStack') || 'No call stack captured';
  const log = [...files.entries()].find(([name]) => name.endsWith('.log'))?.[1]?.toString('utf8')
    || 'The player did not include a log.';
  const game = xmlValue(xml, 'GameName').replace(/^UE-/, '') || 'StepsToTheStars';
  const platform = xmlValue(xml, 'PlatformName') || xmlValue(xml, 'PlatformFullName') || 'Unknown';
  const version = xmlValue(xml, 'EngineVersion') || 'Unknown';
  const configuration = xmlValue(xml, 'BuildConfiguration') || 'Unknown';

  const cpu = xmlValue(xml, 'CPUInfo') || xmlValue(xml, 'CPUBrand') || xmlValue(xml, 'Processor') || 'Unknown';
  const cpuCores = xmlValue(xml, 'NumberOfCores') || '';
  const cpuThreads = xmlValue(xml, 'NumberOfCoresIncludingHyperthreads') || '';
  let cpuDetails = cpu;
  if (cpuCores || cpuThreads) {
    const coreDetails = [
      cpuCores ? `${cpuCores} cores` : '',
      cpuThreads ? `${cpuThreads} threads` : '',
    ].filter(Boolean).join(', ');
    if (coreDetails && !cpuDetails.includes(cpuCores)) {
      cpuDetails = `${cpuDetails} (${coreDetails})`;
    }
  }

  const gpu = xmlValue(xml, 'PrimaryGPUBrand') || xmlValue(xml, 'GPUAdapter') || 'Unknown';
  const gpuDriver = xmlValue(xml, 'DriverVersion') || '';
  const rhi = xmlValue(xml, 'RHIName') || '';
  let gpuDetails = gpu;
  if (gpuDriver || rhi) {
    const extra = [rhi ? `RHI: ${rhi}` : '', gpuDriver ? `Driver: ${gpuDriver}` : ''].filter(Boolean).join(', ');
    if (extra) gpuDetails = `${gpuDetails} (${extra})`;
  }

  const totalRamRaw = xmlValue(xml, 'TotalPhysicalRAM');
  const availRamRaw = xmlValue(xml, 'AvailablePhysicalRAM');
  let ramDetails = totalRamRaw ? formatMemoryBytes(totalRamRaw) : 'Unknown';
  if (totalRamRaw && availRamRaw) {
    ramDetails = `${formatMemoryBytes(totalRamRaw)} (Available: ${formatMemoryBytes(availRamRaw)})`;
  }

  const osVersion = xmlValue(xml, 'OSVersionBuild') || xmlValue(xml, 'OSVersion') || xmlValue(xml, 'PlatformFullName') || platform;
  const summary = plainText(error.split('\n').find(Boolean), 120);

  return {
    title: `[Crash] ${summary}`,
    body: [
      'Automatically submitted by Unreal CrashReportClient after the player pressed Send.',
      '', '### Player comment', `<pre>${html(comment, 2000)}</pre>`,
      '', '### Error', `<pre>${html(error, 4000)}</pre>`,
      '', '### Call stack', `<pre>${html(stack, 12000)}</pre>`,
      '', '### System & Hardware Specs',
      `<pre>OS: ${html(osVersion, 120)}\nCPU: ${html(cpuDetails, 150)}\nGPU: ${html(gpuDetails, 150)}\nRAM: ${html(ramDetails, 100)}</pre>`,
      '', '### Build',
      `<pre>Game: ${html(game, 100)}\nPlatform: ${html(platform, 100)}\nConfiguration: ${html(configuration, 40)}\nEngine: ${html(version, 100)}</pre>`,
      '', '### Sanitised log (last 20,000 characters)', `<pre>${html(log.slice(-20000), 20000)}</pre>`,
    ].join('\n'),
  };
}

export async function createCrashIssue(compressed, token, fetchImpl = fetch) {
  const issue = issueFromCrash(compressed);
  const response = await fetchImpl(`https://api.github.com/repos/${GITHUB_REPOSITORY}/issues`, {
    method: 'POST',
    headers: {
      Accept: 'application/vnd.github+json',
      Authorization: `Bearer ${token}`,
      'Content-Type': 'application/json',
      'User-Agent': 'stts-crash-reporter',
      'X-GitHub-Api-Version': '2022-11-28',
    },
    body: JSON.stringify({ ...issue, labels: ['player-crash'] }),
    signal: AbortSignal.timeout(10_000),
  });
  if (!response.ok) throw new Error(`GitHub rejected the issue (${response.status})`);
  return response.json();
}

export default {
  async fetch(request, env) {
    const url = new URL(request.url);
    if (request.method === 'GET' && url.pathname === '/healthz') return new Response('ok');
    if (request.method !== 'POST' || url.pathname !== '/v1/crashes') {
      return new Response('not found', { status: 404 });
    }
    try {
      const declaredLength = Number(request.headers.get('content-length') || 0);
      if (declaredLength > MAX_UPLOAD) throw new UeCrashFormatError('Crash upload is too large');
      const compressed = Buffer.from(await request.arrayBuffer());
      if (compressed.length > MAX_UPLOAD) throw new UeCrashFormatError('Crash upload is too large');
      const created = await createCrashIssue(compressed, env.GITHUB_TOKEN);
      return Response.json({ issue: created.html_url });
    } catch (error) {
      const clientError = error instanceof UeCrashFormatError;
      console.error(error.message);
      return new Response(clientError ? error.message : 'issue creation failed', {
        status: clientError ? 400 : 502,
      });
    }
  },
};
