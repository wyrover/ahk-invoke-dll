/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include "Junction.h"
#include <windows.h>
#include <stdio.h>

/* --- DLL Èë¿Ú ---*/

BOOL APIENTRY DllMain(HINSTANCE hInst     /* Library instance handle. */ ,
                      DWORD reason        /* Reason this function is being called. */ ,
                      LPVOID reserved     /* Not used. */)
{
    switch (reason) {
    case DLL_PROCESS_ATTACH:
        break;

    case DLL_PROCESS_DETACH:
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}

/* -------------------------------------------------------------------------- */

DllClass::DllClass()
{
}


DllClass::~DllClass()
{
}


extern "C" DLLIMPORT void WINAPI Hello1()
{
    ::MessageBoxA(NULL, "hello world!", "from dll", MB_OK);
}

extern "C" DLLIMPORT bool IsJunction(const wchar_t* Path)
{
    return libntfslinks::IsJunction(Path);
}

extern "C" DLLIMPORT DWORD GetJunctionTarget(const wchar_t* Path, wchar_t* TargetPath, DWORD TargetSize)
{
    return libntfslinks::GetJunctionTarget(Path, TargetPath, TargetSize);
}