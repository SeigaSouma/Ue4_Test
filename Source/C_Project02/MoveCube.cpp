// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveCube.h"

// Sets default values
AMoveCube::AMoveCube()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	//アセットの設定
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	// 作成に成功したか判定
	if (CubeVisualAsset.Succeeded())
	{
		//パラメータ設定
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AMoveCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// アクタの位置を取得
	FVector NewLocation = GetActorLocation();

	FTransform transform = GetActorTransform();
	transform.GetLocation;

	FVector NewScale = GetActorScale();

	// 現在の高さを算出
	float RunnningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunnningTime + DeltaTime) - FMath::Sin(RunnningTime));

	// 高さを設定
	NewLocation.Z += DeltaHeight * 20.0f;

	// スケール
	NewScale.X += DeltaHeight * 1.0f;
	NewScale.Y += DeltaHeight * 1.0f;
	NewScale.Z += DeltaHeight * 1.0f;

	// 位置を設定
	SetActorLocation(NewLocation);
	SetActorScale3D(NewScale);

}

