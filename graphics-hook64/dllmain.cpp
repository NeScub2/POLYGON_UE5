#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "detours.h"
#include "sigScaner.h"
#include "ZeroGUI.h"
#include "Cheat/Cheat.h"
#include "Addrs.h"
#pragma comment(lib, "detours.lib")
typedef __int64(*postrender)(AHud* hud);

uintptr_t AddressOfEngine = sigScaner::find(NULL, "48 8B ? ? ? ? ? 48 8B ? E8 ? ? ? ? 84 C0 75 ? 48 8B ? E8 ? ? ? ? 84 C0 74");
GEngine* gEngine = (GEngine*)(*(uintptr_t*)sigScaner::GetAbsoluteAddress(AddressOfEngine, 3, 7));

int test_number;
FVector2D pos;
void Tick(AHud* hud)
{
	ZeroGUI::Input::Handle();

	static bool menu_opened = false;
	Cheat::Update(hud, gEngine);
	if (GetAsyncKeyState(VK_INSERT) & 1) menu_opened = !menu_opened; //Our menu key
	if (ZeroGUI::Window(gEngine, (char*)"NONAME HACK", &pos, FVector2D{ 500.0f, 400.0f }, menu_opened))
	{
		ZeroGUI::Checkbox(gEngine, (char*)"Skeleton Gey", &Cheat::geyskeletonactive);
		ZeroGUI::Checkbox(gEngine, (char*)"Aim Bot", &Cheat::aimbotactive);
		ZeroGUI::Checkbox(gEngine, (char*)"NameEsp", &Cheat::nameesp);
		ZeroGUI::SliderInt(gEngine, (char*)"Aim Bot fov", &Cheat::aimfov, 0, 360);
		ZeroGUI::Checkbox(gEngine, (char*)"Firerate", &Cheat::firerate);
		ZeroGUI::ColorPicker(gEngine, (char*)"Skeleton COLLOR", &Cheat::skeletoncolor);
		if (ZeroGUI::Button(gEngine, (char*)"SetNameByTxt", { 120,25 }))
			Cheat::setnametext = !Cheat::setnametext;
	}
	ZeroGUI::Render(gEngine);//Custom Render. I use it for drawing Combobox and ColorPicker over the menu
	ZeroGUI::Draw_Cursor(hud, menu_opened);
}

__int64 Hookpostrender(AHud* hud)
{
	if (!hud)
	{
		postrender originalpostrender = (postrender)Addrs::AddressOfpostrender;
		return originalpostrender(hud);
	}
	ZeroGUI::SetupCanvas(hud);
	Tick(hud);
	postrender originalpostrender = (postrender)Addrs::AddressOfpostrender;
	return originalpostrender(hud);
}

void inithook()
{

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)Addrs::AddressOfpostrender, &Hookpostrender);
	DetourTransactionCommit();
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		Addrs::init_addrs();
		inithook();
	}
	return TRUE;
}
