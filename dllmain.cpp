#include "pch.h"
#include <windows.h>
#include "E:/sourcecody/fivemExec/exec/CustomAPI.h"
#include <iostream>
#include <thread>

using LoadFile_call = __int64(*)(__int64 state, const std::string& filename);
using LoadSystemFileInternal_t = int(*)(uint64_t, const char*);
char LSFIShell[] = { 0x55, 0x56, 0x57, 0x53, 0x48, 0x83, 0xEC, 0x38, 0xFF, 0x25, 0x00, 0x00, 0x00, 0x00, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69 };

void sokin() {

	LoadFile_call LoadFile = (LoadFile_call)(CustomAPI::GetModuleA("citizen-resources-metadata-lua.dll" + 0x50910));

	//(Byte*)(CustomAPI::GetModuleA("Adhesive") + 0x49288C ) +1;

	//Loadluastate_lua

	while (true) {
		if (GetAsyncKeyState(VK_F5)) {

			LoadFile(0x0, "C:\\menu.lua");
		}
	}
	//load_luastate

}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sokin, 0, 0, 0);

	return TRUE;
}
