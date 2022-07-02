#pragma once
#include "../GameClass.h"
#include "../UnrealEngineClasses.h"
#include "../functions.h"
#include <string>

class Cheat {
public:
	static void Update(AHud* hud, GEngine* gEngine);
	static void MagicBullet(__int64 PROJECTale, GEngine* gEngine);
public:
	inline static bool geyskeletonactive, aimbotactive, isworldgeyspeedactive, magicbullet, drawbox,firerate, setnametext,namesteal,nameesp, dumpplayername;
	inline static int worldgeyspeed = 1,sizescreenx, sizescreeny,aimfov;
	inline static FLinearColor boxcollor = {255,0,0,255}, skeletoncolor;
};