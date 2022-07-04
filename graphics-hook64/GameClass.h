#pragma once
#include <Windows.h>
#include "UnrealEngineClasses.h"
#include "sigScaner.h"
#include "Addrs.h"
#include <cmath>
#include <algorithm> 
class ClassType
{
public:
	char pad_00010[0x10]; //0x0008
	class ClassType* ClType; //0x0010
	int32_t FnameIndex; //0x0018
};
class UObject
{
public:
	void* Vtable; //0x0000
	char pad_0008[4]; //0x0008
	int32_t ObjectIndex; //0x000C
	ClassType* Info; //0x0010
	char pad_0018[8]; //0x0018
	__int64 Outer; // 0x20
};//Size: 0x0028
class GEngine {
public:
	char pad_0000[0x70];
	uintptr_t* MediumFont;
	char pad_0078[0x748]; //0x0078
	class GameViewPort* GameViewPort; //0x7c0
};
// Enum POLYGON.ETeam
enum class ETeam : __int8 {
	NONE = 0,
	NOBODY = 1,
	ALPHA = 2,
	BRAVO = 3,
	ETeam_MAX = 4
};

class GameViewPort {
public:
	char pad_0000[0x78];
	class UWorld* World;
};
class UPlayerCoreComponent
{
public:
	char pad_0000[0xd0]; //0x0000
	int32_t PremiumScore; // 0xd0(0x04)
	int32_t TotalProgress; // 0xd4(0x04)
	int32_t Currency; // 0xd8(0x04)
	char pad_DC[0x4]; // 0xdc(0x04)
	bool bHasPremiumAccount; // 0xe0(0x01)


};
class USquadComponent
{
public:

};

class UChatSystemComponent
{
public:

};
// Enum POLYGON.EWeaponShootingType
enum class EWeaponShootingType : __int8 {
	BOLT = 0,
	SEMI_AUTO = 1,
	AUTO = 2,
	EWeaponShootingType_MAX = 3
};
// Enum POLYGON.EWeaponSlot
enum class EWeaponSlot : __int8 {
	PRIMARY = 0,
	SECONDARY = 1,
	EWeaponSlot_MAX = 2
};
// Enum POLYGON.EWeaponType
enum class EWeaponType : __int8 {
	NONE = 0,
	ASSAULT = 1,
	SMG = 2,
	MARKSMAN = 3,
	LMG = 4,
	SHOTGUN = 5,
	SNIPER = 6,
	PISTOL = 7,
	REVOLVER = 8,
	EWeaponClass_MAX = 9,
};
enum class ECollisionChannel : __int8
{
	ECC_WorldStatic = 0,
	ECC_WorldDynamic = 1,
	ECC_Pawn = 2,
	ECC_Visibility = 3,
	ECC_Camera = 4,
	ECC_PhysicsBody = 5,
	ECC_Vehicle = 6,
	ECC_Destructible = 7,
	ECC_EngineTraceChannel1 = 8,
	ECC_EngineTraceChannel2 = 9,
	ECC_EngineTraceChannel3 = 10,
	ECC_EngineTraceChannel4 = 11,
	ECC_EngineTraceChannel5 = 12,
	ECC_EngineTraceChannel6 = 13,
	ECC_GameTraceChannel1 = 14,
	ECC_GameTraceChannel2 = 15,
	ECC_GameTraceChannel3 = 16,
	ECC_GameTraceChannel4 = 17,
	ECC_GameTraceChannel5 = 18,
	ECC_GameTraceChannel6 = 19,
	ECC_GameTraceChannel7 = 20,
	ECC_GameTraceChannel8 = 21,
	ECC_GameTraceChannel9 = 22,
	ECC_GameTraceChannel10 = 23,
	ECC_GameTraceChannel11 = 24,
	ECC_GameTraceChannel12 = 25,
	ECC_GameTraceChannel13 = 26,
	ECC_GameTraceChannel14 = 27,
	ECC_GameTraceChannel15 = 28,
	ECC_GameTraceChannel16 = 29,
	ECC_GameTraceChannel17 = 30,
	ECC_GameTraceChannel18 = 31,
	ECC_OverlapAll_Deprecated = 32,
	ECC_MAX = 33,
};
class RootComponent {
public:
	char pad_0000[0x270];
	FVector Location;
};
class ATraceProjectile
{
public:
	char pad_0000[0x190]; //0x0000
	RootComponent* root; //0x0190
	char pad_0198[224]; //0x0198
	FVector Velocity; //0x0278
	char pad_0284[132]; //0x0284
	bool DebugEnabled; //0x0308
	char pad_0309[3]; //0x0309
	float DebugTrailTime; //0x030C
	float DebugTrailWidth; //0x0310
	uint64_t DebugTrailColorFast; //0x0314
	char pad_031C[8]; //0x031C
	uint64_t DebugTrailColorSlow; //0x0324
	char pad_032C[8]; //0x032C
	bool DebugPooling; //0x0334
	char pad_0335[131]; //0x0335
	FVector Gravity; //0x03B8
	char pad_03C4[16]; //0x03C4
	float SafeDelay; //0x03D4
	char pad_03D8[24]; //0x03D8
	float Spread; //0x03F0
	float Mass; //0x03F4
	float Diameter; //0x03F8
	float FormFactor; //0x03FC
	char pad_0400[120]; //0x0400
	bool Retrace; //0x0478
	bool RetraceOnAnotherChannel; //0x0479
	char pad_047A[2]; //0x047A
	ECollisionChannel N000004BC; //0x047C

};
class AItem_Weapon_General
{
public:
	char pad_2B0[0x320];
	enum class EWeaponType WeaponType; // 0x320(0x01)
	enum class EWeaponSlot WeaponSlot; // 0x321(0x01)
	enum class EWeaponShootingType WeaponShootingType; // 0x2ca(0x01)
	char pad_2CB[0x1]; // 0x2cb(0x01)
	int32_t WeaponDamage; // 0x2cc(0x04)
	float DamageMultiplierHead; // 0x2d0(0x04)
	char pad_02D4[0xC]; //0x02D4
	int32_t MaxMagazineAmmo; // 0x2e0(0x04)
	int32_t MaxStockAmmo; // 0x2e4(0x04)
	float TimeBetweenShots; // 0x2e8(0x04)
	float WeaponUpRecoil; // 0x2ec(0x04)
	float WeaponBackwardRecoil; // 0x2f0(0x04)
	float WeaponRecoilAlphaPerShot; // 0x2f4(0x04)
	float WeaponRecoilLift; // 0x2f8(0x04)
	float AccuracyHip; // 0x2fc(0x04)
	float AccuracySight; // 0x300(0x04)
	float SpreadShot; // 0x304(0x04)
	float Mobility; // 0x308(0x04)
	ATraceProjectile* ProjectileClass;
};
class UInventoryComponent_Game
{
public:
	char pad_0000[0xf0]; //0x0000
	AItem_Weapon_General* currentweapon;
};
class Entity
{
public:
	char pad_0000[0x2F0]; //0x0000
	class PawnPrivate* PawnPrivate; //0x2F0
	char pad_02F8[120]; //0x02F8
	wchar_t* playername; //0x0370	
	char pad_0378[136]; //0x0378
	ETeam Team; //0x400
	char NumberKills; // 0x401(0x01)
	char NumberDeaths; // 0x402(0x01)
	char NumberKillsByMe; // 0x403(0x01)
	char NumberKillsOfMe; // 0x404(0x01)
	bool bIsAdmin; // 0x405(0x01)
	bool bIsPatron; // 0x406(0x01)
	char pad_0407[17]; //0x0407
	UInventoryComponent_Game* InventoryComponent_Game; //0x0418

}; //Size: 0x1848
enum class EMessageType : __int8 {
	ALL = 0,
	TEAM = 1,
	SQUAD = 2,
	PRIVATE = 3,
	SYSTEM = 4,
	EMessageType_MAX = 5
};
struct FGameChatMessage {
	Entity* Sender; // 0x00(0x08)
	enum class EMessageType MessageType; // 0x08(0x01)
	char pad_9[0x7]; // 0x09(0x07)
	struct FString Message; // 0x10(0x10)
};
class GameState
{
public:
	char pad_0000[0x290]; //0x0000
	TArray<Entity*>(player);
}; //Size: 0x0848
class WorldSettings {
public:
	char pad_0000[0x2E8];
	float TimeDilation;
};

class PersistentLevel
{
public:
	char pad_0000[0x258];
	class WorldSettings* WorldSettings;
};
class UWorld {
public:
char pad_0000[48]; //0x0000
	class PersistentLevel* PersistentLevel; //0x0030
	char pad_0038[248]; 
	class GameState* GameState; //0x0130
	char pad_0128[88];
	class OwningGameInstance* OwningGameInstance; //0x0190
};




class UHealthStatsComponent {
public:
	char pad_0000[0xE0];    // 0x000
	int8_t Health;         // 0x0E0
	bool bIsAlive;          // 0x0E1
	bool bHealthProtection; // 0x0E2
	char pad_00E3[5]; //0x00E3
	float Stamina;          // 0x0E8
};
class Mesh
{
public:
	inline FMatrix* get_bone_matrix(Mesh* mesh, FMatrix* matrix, int bone_id)
	{
		static uintptr_t addr = 0;
		if (!addr)
			addr = sigScaner::GetAbsoluteAddress(sigScaner::find(NULL, "E8 ? ? ? ? 0F 10 40 68"), 1, 5);			
		return reinterpret_cast<FMatrix*(__fastcall*)(Mesh * _this, FMatrix* matrix, int bone_id)>(addr)(this, matrix, bone_id);
	}

	 inline  void get_bone_location(FVector* vec, int bone_id)
	{
		FMatrix v_matrix;
		FMatrix* v_temp_matrix = get_bone_matrix(this, &v_matrix, bone_id);
		*vec = v_matrix.WPlane;
	}
};
class USkeletalMeshComponent
{
public:
};
class UWeaponComponent
{
public:
	char pad_0000[0xDD]; //0x0000
	bool isAiming; //0x0DD
	char pad_011E[1]; //0x011E
	bool bWeaponIsDown; // 0xde
//	AItem_Weapon_General* CurrentWeapon; // 0x120(0x08) xz
};
class PawnPrivate {
public:
	char pad_0000[400]; //0x0000
	RootComponent* root; //0x0190
	char pad_0198[352]; //0x0198
	class Mesh* mesh; //0x2f8
	char pad_0300[1016]; //0x0300
	UHealthStatsComponent* HealthStateComponent; ///0x6fda
	UWeaponComponent* WeaponComponent; // 0x700

	 inline  void GetActorBounds( bool bOnlyCollidingComponents, FVector* Origin, FVector* BoxExtent, bool bIncludeFromChildActors)
	 {
		 return reinterpret_cast<void(__fastcall*)(PawnPrivate * _this, bool bOnlyCollidingComponents, FVector * Origin, FVector* BoxExtent, bool bIncludeFromChildActors)>(Addrs::GetActorBounds)(this, bOnlyCollidingComponents, Origin, BoxExtent, bIncludeFromChildActors);
	 }
};
class OwningGameInstance {
public:
	char pad_0000[0x38];
	class LocalPlayers* LocalPlayers;
};
class LocalPlayers {
public:
	class LocalPlayer* LocalPlayer;
};
class LocalPlayer {
public:
	char pad_0000[0x30];
	class PlayerController* PlayerController;
};
class PlayerCameraManager
{
public:
	char pad_0000[0x1AB0]; //0x0000
	FVector location1;
	FRotator rotation;
};
class ACharacter
{
public:
	char pad_0000[0x63c]; //0x0000
	float ControllerRotationX; // 0x63c(0x04)
	float ControllerRotationY; 
};
class PlayerController {
public:
	char pad_0000[640]; //0x0000
	class Entity* state; //0x0280
	char pad_0288[48]; //0x0288
	class PawnPrivate* pawn; //0x02b8
	char pad_0258[8]; //0x0258
	ACharacter* character; //0x002C8
	char pad_02D0[96]; //0x02D0
	PlayerCameraManager* camera; 


	inline bool WorldToScreen(FVector WorldPos, FVector2D* ScreenPos)
	{
		return reinterpret_cast<bool(__fastcall*)(PlayerController* _this, FVector WorldPos, FVector2D* ScreenPos, bool)>(Addrs::addrsworldtoscreen)(this, WorldPos, ScreenPos, false);
	}
	inline bool LineOfSign(PawnPrivate* actor)
	{
		FVector rot = { 0,0,0 }; // LineOfSign
		return reinterpret_cast<bool(__fastcall*)(PlayerController * _this, PawnPrivate * actor, FVector*)>(Addrs::LineOfSign)(this, actor,&rot);
	}
	inline void GetViewportSize(int32_t* SizeX, int32_t* SizeY)
	{
		return reinterpret_cast<void(__fastcall*)(PlayerController * _this, int32_t * SizeX, int32_t* SizeY)>(Addrs::GetViewportSize)(this, SizeX, SizeY);
	}
};
