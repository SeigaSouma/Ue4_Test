// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveCube.h"

// Sets default values
AMoveCube::AMoveCube()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	//�A�Z�b�g�̐ݒ�
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	// �쐬�ɐ�������������
	if (CubeVisualAsset.Succeeded())
	{
		//�p�����[�^�ݒ�
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

	// �A�N�^�̈ʒu���擾
	FVector NewLocation = GetActorLocation();

	FTransform transform = GetActorTransform();
	transform.GetLocation;

	FVector NewScale = GetActorScale();

	// ���݂̍������Z�o
	float RunnningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunnningTime + DeltaTime) - FMath::Sin(RunnningTime));

	// ������ݒ�
	NewLocation.Z += DeltaHeight * 20.0f;

	// �X�P�[��
	NewScale.X += DeltaHeight * 1.0f;
	NewScale.Y += DeltaHeight * 1.0f;
	NewScale.Z += DeltaHeight * 1.0f;

	// �ʒu��ݒ�
	SetActorLocation(NewLocation);
	SetActorScale3D(NewScale);

}

