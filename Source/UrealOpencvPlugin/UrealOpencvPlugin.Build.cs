// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class UrealOpencvPlugin : ModuleRules
{
	public UrealOpencvPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		string ThirdPartyInclude = Path.Combine(PluginDirectory, "ThirdParty/include");
		System.Console.WriteLine(string.Format("ThirdPartyInclude = {0}", ThirdPartyInclude));

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				ThirdPartyInclude,
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Projects",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {

            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "ThirdParty", "x64", "vc15", "lib", "opencv_world454.lib"));

            PublicDelayLoadDLLs.Add("opencv_world454.dll");
           
            RuntimeDependencies.Add(Path.Combine(PluginDirectory, "ThirdParty", "x64", "vc15", "bin", "opencv_world454.dll"));

        }
    }
}
