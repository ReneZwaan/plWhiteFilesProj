// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "WhiteFilesPrivatePCH.h"
#include "WhiteFilesBPLibrary.h"

UWhiteFilesBPLibrary::UWhiteFilesBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


FString UWhiteFilesBPLibrary::RemoveInvalidCharacters(FString input)
{
	TCHAR chars[8] = { '/','<','>',':','\\','|','?','*' };
	
	input = input.Replace(TEXT("/"),TEXT(""),ESearchCase::IgnoreCase);
	input = input.Replace(TEXT("<"), TEXT(""), ESearchCase::IgnoreCase);
	input = input.Replace(TEXT(">"), TEXT(""), ESearchCase::IgnoreCase);
	input = input.Replace(TEXT(":"), TEXT(""), ESearchCase::IgnoreCase);
	input = input.Replace(TEXT("\\"), TEXT(""), ESearchCase::IgnoreCase);
	input = input.Replace(TEXT("|"), TEXT(""), ESearchCase::IgnoreCase);
	input = input.Replace(TEXT("?"), TEXT(""), ESearchCase::IgnoreCase);
	input = input.Replace(TEXT("*"), TEXT(""), ESearchCase::IgnoreCase);
	input = input.Replace(TEXT("\""), TEXT(""), ESearchCase::IgnoreCase);
	return input;
}

FString UWhiteFilesBPLibrary::GetPathToDirectory(UnrealPaths Param)
{
	FString path = TEXT("");
	switch(Param)
	{
	case UnrealPaths::GameRoot :
	{
		path = FPaths::GameDir();
		break;
	}
	case UnrealPaths::GameContent:
	{
		path = FPaths::GameContentDir();
		break;
	}
	case UnrealPaths::GameMovies :
	{
		path = FPaths::GameContentDir();
		path.Append(TEXT("/Movies"));
		break;
	}
	case UnrealPaths::GameConfig:
	{
		path = FPaths::GameConfigDir();
		break;
	}
	case UnrealPaths::GameLog:
	{
		path = FPaths::GameLogDir();
		break;
	}
	case UnrealPaths::GameSave:
	{
		path = FPaths::GameSavedDir();
		break;
	}
	case UnrealPaths::GameUser:
	{
		path = FPaths::GameUserDir();
		break;
	}
	
	}
	return path;
}

TArray<FString> UWhiteFilesBPLibrary::GetAllFilesInDirectory(FString Path, bool filterDirectories)
{
	IFileManager& Filemanager = IFileManager::Get();
	TArray<FString> FoundFiles;
	Path = Path.Append(TEXT("\\*"));
	Filemanager.FindFiles(FoundFiles, *Path,true, filterDirectories);
	return  FoundFiles;
}

TArray<FString> UWhiteFilesBPLibrary::HasExtentions(TArray<FString> Paths, TArray<FString> Extentions)
{
	TArray<FString> Result = Paths;
	//Filter true files to see if they contain the extention
	for (FString path : Result)
	{
		bool ContainsExtention = false;
		for (FString extention : Extentions)
		{
			if (path.Contains(extention))
				ContainsExtention = true;
		}
		if (!ContainsExtention)
			Result.Remove(path);
	}
	//loop true the extentions
	return Result;
}

