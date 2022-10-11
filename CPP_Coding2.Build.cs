// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPP_Coding2 : ModuleRules
{
	public CPP_Coding2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
