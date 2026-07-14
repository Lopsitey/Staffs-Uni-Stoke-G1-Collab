using UnrealBuildTool;

public class G1CollabEditor : ModuleRules
{
	public G1CollabEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Blutility",
			"Core",
			"CoreUObject",
			"Engine",
			"Slate",
			"SlateCore",
			"ToolMenus",
			"UMG",
			"UnrealEd"
		});
	}
}
