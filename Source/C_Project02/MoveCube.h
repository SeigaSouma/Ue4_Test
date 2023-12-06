// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveCube.generated.h"

UCLASS()
class C_PROJECT02_API AMoveCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveCube();

	// StaticMeshコンポーネントを宣言
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
