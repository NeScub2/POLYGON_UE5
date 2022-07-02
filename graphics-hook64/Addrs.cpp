#include "Addrs.h"
#include "sigScaner.h"

void Addrs::init_addrs()
{	
	AddressOfpostrender = sigScaner::find(NULL, "40 55 53 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B D9 E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 48 83 BB");
	addrsworldtoscreen = sigScaner::GetAbsoluteAddress(sigScaner::find(0, "E8 ? ? ? ? 48 83 C4 28 C3 CC CC 40 55"), 1, 5);	
	GetActorBounds = sigScaner::GetAbsoluteAddress(sigScaner::find(0, "E8 ? ? ? ? F3 0F 10 6D ? 48 8B CB"), 1, 5);

	LineOfSign = sigScaner::find(0, "40 ? 53 56 57 48 8D ? ? ? 48 81 EC ? ? ? ? 48 8B ? ? ? ? ? 48 33 ? 48 89 ? ? 49 8B ? 48 8B ? 48 8B ? 48 85");
	if(!LineOfSign)
		LineOfSign = sigScaner::find(0, "40 55 53 56 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 E0 49 8B F8");

	K2DrawLine = sigScaner::find(0, "4C 8B DC 48 81 EC ? ? ? ? 4C 89 44 24 ? 66 48 0F 6E D2 F3 0F 10 64 24 ? F3 0F 10 6C 24 ? 0F 28 C4");
	if(!K2DrawLine)
		K2DrawLine = sigScaner::find(0, "4C 8B DC 48 81 EC ? ? ? ? 4C 89 44 24");
	if (!K2DrawLine)
		K2DrawLine = sigScaner::find(0, "E8 ? ? ? ? 48 8B 5C 24 ? 48 83 C4 60 5F C3 CC CC CC CC CC CC CC 48 89 5C 24 ? 48 89 74 24 ? 57"); // + xz nado dumat

	K2DrawText = sigScaner::find(0, "40 53 55 56 41 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 41 83 78 ? ? 48 8B DA 48 8B AC 24");
	if(!K2DrawText)
		K2DrawText = sigScaner::GetAbsoluteAddress(sigScaner::find(0, "E8 ? ? ? ? 48 8B 4D 80 48 85 C9 74 05 E8 ? ? ? ? 4C 8D 9C 24"), 1, 5); // 66 0F 7F 4D ? E8 ? ? ? ? 48 8B 4D 80 

	HUDDrawLine = sigScaner::find(0, "48 8B C4 53 48 81 EC ? ? ? ? 0F 29 70 E8 48 8B D9 0F 29 78 D8 0F 28 F3");
	HUDDrawText = sigScaner::find(0, "40 55 56 57 48 81 EC ? ? ? ? 44 0F 29 84 24");

	GetViewportSize = sigScaner::find(NULL, "48 89 ? ? ? 48 89 ? ? ? 57 48 83 EC ? 33 C0 49 8B ? 89 02");
}