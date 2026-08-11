using UnrealBuildTool;
using System.Collections.Generic;

public class StepsToTheStarsTarget : TargetRules
{
	public StepsToTheStarsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;

		ExtraModuleNames.AddRange(new string[] { "G1Collab" });
	}
}
