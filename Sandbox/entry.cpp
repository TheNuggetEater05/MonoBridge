#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <iostream>

#include <MonoBridge.h>

void MakeConsole()
{
	AllocConsole();

	FILE* fDummy{};
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
}

DWORD WINAPI MainThread(LPVOID lpParam)
{
	auto hInstance = reinterpret_cast<HINSTANCE>(lpParam);

	MakeConsole();

	MB::MBG_STATUS status = MB::Initialize(hInstance);

	printf("%s\n", MB::StatusToString(status));

	status = MB::Initialize(hInstance);

	printf("%s\n", MB::StatusToString(status));

	FreeConsole();
	FreeLibraryAndExitThread(hInstance, 0);

	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpvReserved)
{
	HANDLE thread = nullptr;

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hInstance);
		thread = CreateThread(nullptr, 0, &MainThread, hInstance, 0, nullptr);
		break;
	default:
		break;
	}

	if (thread)
		CloseHandle(thread);

	return true;
}