#pragma once
#include <Windows.h>
class sigScaner
{
public:
	static uintptr_t find(const char* module, const char* pattern);
	static uintptr_t GetAbsoluteAddress(uintptr_t address, int offset, int size);
};


