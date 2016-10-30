// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "WhiteFilesBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

UENUM(BlueprintType)
enum class UnrealPaths : uint8
{
	GameRoot	UMETA(DisplayName = "GameRoot"),
	GameContent UMETA(DisplayName = "GameContent"),
	GameMovies	UMETA(DisplayName = "GameMovies"),
	GameConfig	UMETA(DisplayName = "GameConfig"),
	GameLog		UMETA(DisplayName = "GameLog"),
	GameSave	UMETA(DisplayName = "GameSave"),
	GameUser	UMETA(DisplayName = "GameUser")
};

UCLASS()
class UWhiteFilesBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Remove invalid Characters", Keywords = "WhiteFiles Invalid char text"), Category = "WhiteFiles")
	static FString RemoveInvalidCharacters(FString Text);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get path to location", Keywords = "WhiteFiles Path dir"), Category = "WhiteFiles")
	static FString GetPathToDirectory(UnrealPaths Path);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get All files/Folders in a path", Keywords = "WhiteFiles Path dir files find"), Category = "WhiteFiles")
	static TArray<FString> GetAllFilesInDirectory(FString Path,bool filterDirectories = true);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Filter extentions", Keywords = "WhiteFiles Path has extentions file"), Category = "WhiteFiles")
		static TArray<FString> HasExtentions(TArray<FString> Paths,TArray<FString> Extentions);
};
