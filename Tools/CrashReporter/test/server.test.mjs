import assert from 'node:assert/strict';
import test from 'node:test';
import { deflateSync } from 'node:zlib';
import { createCrashIssue, issueFromCrash } from '../src/worker.mjs';

function int(value) {
  const data = Buffer.alloc(4);
  data.writeInt32LE(value);
  return data;
}

function string(value) {
  const encoded = Buffer.from(value, 'latin1');
  const size = Math.max(encoded.length + 1, 260);
  return Buffer.concat([int(size), encoded, Buffer.alloc(size - encoded.length)]);
}

function crashArchive(files) {
  const entries = [...files].map(([name, data], index) =>
    Buffer.concat([int(index), string(name), int(data.length), data]));
  const directory = 'UECC-test';
  const prefixSize = 3 + string(directory).length + string(`${directory}.uecrash`).length + 8;
  const size = prefixSize + entries.reduce((sum, entry) => sum + entry.length, 0);
  return deflateSync(Buffer.concat([
    Buffer.from('CR1'), string(directory), string(`${directory}.uecrash`),
    int(size), int(entries.length), ...entries,
  ]));
}

const xml = Buffer.from(`<FGenericCrashContext>
<GameName>UE-StepsToTheStars</GameName><PlatformName>Windows</PlatformName>
<BuildConfiguration>Shipping</BuildConfiguration><EngineVersion>5.6.1</EngineVersion>
<UserDescription>Please help @maintainer &amp; thanks</UserDescription>
<ErrorMessage>Fatal test</ErrorMessage><CallStack>Game!Crash()</CallStack>
<CPUInfo>AMD Ryzen 7 7700X</CPUInfo>
<NumberOfCores>8</NumberOfCores>
<NumberOfCoresIncludingHyperthreads>16</NumberOfCoresIncludingHyperthreads>
<PrimaryGPUBrand>NVIDIA GeForce RTX 4070</PrimaryGPUBrand>
<DriverVersion>560.81</DriverVersion>
<RHIName>D3D12</RHIName>
<TotalPhysicalRAM>34282835968</TotalPhysicalRAM>
<AvailablePhysicalRAM>17141417984</AvailablePhysicalRAM>
<OSVersionBuild>10.0.19045.6466</OSVersionBuild>
</FGenericCrashContext>`);
const archive = crashArchive(new Map([
  ['CrashContext.runtime-xml', xml],
  ['StepsToTheStars.log', Buffer.from('C:\\Users\\Jake\\Saved token=github_pat_not-a-real-token-1234567890 player@example.com')],
]));

test('turns Unreal comment, error, stack and log into safe issue text', () => {
  const issue = issueFromCrash(archive);
  assert.equal(issue.title, '[Crash] Fatal test');
  assert.match(issue.body, /Please help @\u200bmaintainer &amp; thanks/);
  assert.match(issue.body, /Game!Crash\(\)/);
  assert.match(issue.body, /CPU: AMD Ryzen 7 7700X \(8 cores, 16 threads\)/);
  assert.match(issue.body, /GPU: NVIDIA GeForce RTX 4070 \(RHI: D3D12, Driver: 560\.81\)/);
  assert.match(issue.body, /RAM: 31\.9 GB \(Available: 16\.0 GB\)/);
  assert.match(issue.body, /OS: 10\.0\.19045\.6466/);
  assert.match(issue.body, /Users\\\[redacted\]/);
  assert.match(issue.body, /token=\[redacted\]/);
  assert.match(issue.body, /\[redacted-email\]/);
  assert.doesNotMatch(issue.body, /player@example.com|github_pat_not-a-real-token/);
});

test('posts one issue with the supplied server-side token', async () => {
  let request;
  const result = await createCrashIssue(archive, 'secret-token', async (url, options) => {
    request = { url, options };
    return { ok: true, json: async () => ({ html_url: 'https://github.test/issues/1' }) };
  });
  assert.equal(result.html_url, 'https://github.test/issues/1');
  assert.equal(request.url, 'https://api.github.com/repos/Lopsitey/Staffs-Uni-Stoke-G1-Collab/issues');
  assert.equal(request.options.headers.Authorization, 'Bearer secret-token');
  assert.equal(JSON.parse(request.options.body).labels[0], 'player-crash');
});

test('rejects anything that is not an Unreal CR1 archive', () => {
  assert.throws(() => issueFromCrash(Buffer.from('plain text')), /valid Unreal crash archive/);
});
