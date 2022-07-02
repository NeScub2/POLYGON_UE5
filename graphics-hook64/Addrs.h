#pragma once
#include <Windows.h>

class Addrs
{
public:
	static void init_addrs();
	static inline uintptr_t addrsworldtoscreen, GetActorBounds, LineOfSign, K2DrawLine, K2DrawText,HUDDrawLine, HUDDrawText, GetViewportSize, AddressOfpostrender;
};