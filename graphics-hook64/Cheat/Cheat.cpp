#include "Cheat.h"
#include "../BoneFNames.h"
#include <fstream>
void drawbone(PlayerController* pcontroller, Entity* EnemyEnt, AHud* hud, int bone1, int bone2) {
	FVector2D BoneStart;
	FVector2D BoneEnd;
	FVector	postargt;
	FVector	postargt2;
	Mesh* mesh = EnemyEnt->PawnPrivate->mesh;
	if (!mesh) return;
	mesh->get_bone_location( &postargt, bone1);
	mesh->get_bone_location( &postargt2, bone2);
	if (pcontroller->WorldToScreen( postargt, &BoneStart))
	{
		if (pcontroller->WorldToScreen( postargt2, &BoneEnd))
		{
			hud->DrawLine( BoneStart, BoneEnd, 2, Cheat::skeletoncolor);	
		}				
	}
}
//void ChangeWeaponParametrs(UWeaponComponent* WeaponComponent,bool issprinting)
//{
//	auto currentweapon = WeaponComponent->CurrentWeapon;
//	if (!currentweapon) return;
//	WeaponComponent->bWeaponIsDown = 0;
//	currentweapon->WeaponShootingType = EWeaponShootingType::AUTO;
//	currentweapon->AccuracyHip = 100000;
//	currentweapon->AccuracySight = 100000;
//	currentweapon->DamageMultiplierHead = 100000;
//	currentweapon->WeaponDamage = 100000;
//	currentweapon->WeaponBackwardRecoil = 0;
//	currentweapon->WeaponRecoilLift = 0;
//	currentweapon->WeaponUpRecoil = 0;
//	currentweapon->SpreadShot = 0;
//	currentweapon->CurrentSpread = 0;
//	if (Cheat::firerate)
//		currentweapon->TimeBetweenShots = 0.07;
//	else
//	{
//		currentweapon->TimeBetweenShots = 0.1;
//	}
//
//	if (Cheat::isworldgeyspeedactive)
//	{
//		if (issprinting)
//			currentweapon->Mobility = Cheat::worldgeyspeed;
//		else
//		{
//			currentweapon->Mobility = 1;
//		}
//	}
//	else
//	{
//		currentweapon->Mobility = 1;
//	}
//
//	currentweapon->SpreadShot =0;
//}
void DumpLobbyName(TArray<Entity*> players)
{
	std::ofstream newfile2;
	newfile2.open("D:/names2.txt");
	if (newfile2.is_open()) { //checking whether the file is open
		for (int i = 0; i < players.Num(); ++i) {
			auto player = players[i];
			std::wstring ws(player->playername);
			std::string str(ws.begin(), ws.end());
			newfile2 << str << "\n";
		}
	}
	newfile2.close();
}
int timed = 500;
void Cheat::Update(AHud* hud, GEngine* gEngine) {
	FVector2D Screen;
	UWorld* World = gEngine->GameViewPort->World;
	if (!World) return;
	if (dumpplayername)
	{
		DumpLobbyName(World->GameState->player);
		dumpplayername = !dumpplayername;
	}
	auto Localplayer = World->OwningGameInstance->LocalPlayers->LocalPlayer;
	if (!Localplayer) return;
	auto playercontroller = Localplayer->PlayerController;
	if (!playercontroller) return;
	if(!sizescreenx || !sizescreeny)
		playercontroller->GetViewportSize( &sizescreenx, &sizescreeny);
	if (sizescreenx && sizescreeny)
		hud->DrawCircle( { (float)sizescreenx / 2 ,(float)sizescreeny / 2 }, aimfov, 60, FLinearColor{ 1,1,1,1 });
	auto localplayerpawn = playercontroller->pawn;
	if (!localplayerpawn) return;
	auto localmesh = localplayerpawn->mesh;
	if (!localmesh) return;
	auto HealthStateComponent = localplayerpawn->HealthStateComponent;
	if (!HealthStateComponent) return;
	HealthStateComponent->Stamina = 100;
	auto camera = playercontroller->camera;
	if (!camera) return;
	auto localplayerstate = playercontroller->state;
	if (!localplayerstate) return;
	if (setnametext)
	{
		int checkforskip = 0;
		std::fstream newfile;
		newfile.open("D:/POLYGONNAME.txt", std::ios::in); //open a file to perform read operation using file object
		std::string tp;
		std::string file_contents;
		if (newfile.is_open()) { //checking whether the file is open
			while (std::getline(newfile, tp)) {
				if (checkforskip > 0)
					file_contents.push_back('\n');
				file_contents += tp;
				checkforskip++;
			}
		}
		newfile.close(); //close the file object.
		std::wstring widestr = std::wstring(file_contents.begin(), file_contents.end());
		const wchar_t* widecstr = widestr.c_str();
		FString playername(widecstr);
		(*(__int64(__fastcall**)(__int64, __int64*))(*(__int64*)playercontroller + 0xB58))((__int64)playercontroller, (__int64*)&playername);
		(*(__int64(__fastcall**)(Entity * state, FString name))(*(__int64*)localplayerstate + 0x6F8))(localplayerstate, playername);
		(*(__int64(__fastcall**)(PlayerController * pc, FString name))(*(__int64*)playercontroller + 0xB58))(playercontroller, playername);
		setnametext = !setnametext;
	}
	for (int i = 0; i < World->GameState->player.Num(); ++i) {
		auto player = World->GameState->player[i];
		if (!player) continue;
		auto playerPawn = player->PawnPrivate;
		if (!playerPawn) continue;
		auto HealthStateComponent = playerPawn->HealthStateComponent;
		if (!HealthStateComponent) continue;

		if (!HealthStateComponent->bIsAlive) continue;
		//if (localplayerstate->Team == player->Team) continue;
		Mesh* mesh = playerPawn->mesh;
		if (!mesh) continue;
		FVector headloc;
		FVector2D headlocscr;
		mesh->get_bone_location(&headloc, BoneFNames::neck_01);
		if (playercontroller->WorldToScreen(headloc, &headlocscr))
		{
			std::cout << "WorldToScreen: " << headlocscr.X << std::endl;
			if (nameesp)
			{
				hud->HDrawText(FString(player->playername), { 0,1,0,1 }, headlocscr.X, headlocscr.Y, gEngine->MediumFont, 1, false);
			}

			if (geyskeletonactive)
			{
				for (int i = 0; i < 192; i++)
				{
					const wchar_t* widecstr = std::to_wstring(i).c_str();
					hud->HDrawText(FString(widecstr), { 0,1,0,1 }, headlocscr.X, headlocscr.Y, gEngine->MediumFont, 1, true);
				}
			}
		}
	}
}
