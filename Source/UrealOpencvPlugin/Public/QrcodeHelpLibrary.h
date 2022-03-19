// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "QrcodeHelpLibrary.generated.h"

/**
 * 二维码
 */
UCLASS()
class UREALOPENCVPLUGIN_API UQrcodeHelpLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		static FString DecodeQrcode(FString InImagePath);
	
};
