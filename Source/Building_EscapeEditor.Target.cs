// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Building_EscapeEditorTarget : TargetRules
{
	public Building_EscapeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new[] {"Building_Escape"});
	}
}