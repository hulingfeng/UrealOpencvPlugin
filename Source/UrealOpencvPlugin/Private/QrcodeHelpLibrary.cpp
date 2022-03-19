// Fill out your copyright notice in the Description page of Project Settings.


#include "QrcodeHelpLibrary.h"
#include "opencv2/opencv.hpp"

FString UQrcodeHelpLibrary::DecodeQrcode(FString InImagePath)
{
	FString StrConent = "";
	std::string imagepath = std::string(TCHAR_TO_UTF8(*InImagePath));
	cv::Mat inputimage = cv::imread(imagepath);
	if (inputimage.data != nullptr)
	{
		cv::QRCodeDetector qrDecoder = cv::QRCodeDetector::QRCodeDetector();
		std::string DecodeStr = "";
		DecodeStr = qrDecoder.detectAndDecode(inputimage);
		//StrConent = FString::Printf(TEXT("%s"), UTF8_TO_TCHAR(tmpConent.c_str()));
	}
	return StrConent;
}