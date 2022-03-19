// Copyright Epic Games, Inc. All Rights Reserved.

#include "UrealOpencvPlugin.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FUrealOpencvPluginModule"

void FUrealOpencvPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FString BaseDir = IPluginManager::Get().FindPlugin("UrealOpencvPlugin")->GetBaseDir();

	FString DllPath;
#if PLATFORM_WINDOWS
	DllPath = FPaths::Combine(*BaseDir, TEXT("ThirdParty/x64/vc15/bin/opencv_world454.dll"));
#endif

	OpencvPluginDllHandle = !DllPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*DllPath) : nullptr;
	if (!OpencvPluginDllHandle)
	{
		checkf(false, TEXT("load OpenCV Third Dll fail!"));
	}
}

void FUrealOpencvPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	if (OpencvPluginDllHandle)
	{
		FPlatformProcess::FreeDllHandle(OpencvPluginDllHandle);
		OpencvPluginDllHandle = nullptr;
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUrealOpencvPluginModule, UrealOpencvPlugin)