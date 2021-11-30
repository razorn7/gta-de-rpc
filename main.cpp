#pragma once

#include "SDK.h" // GTA TDE UE4 SDK
#include "includes/core.hpp" // Include the core
#include "includes/discord.hpp" // Include Discord RPC core

// #define CONSOLE_IN_RELEASE

#define MOD_STRING "Discord RPC for GTA TDE"

using namespace CG;

Core* g_Core;
Discord* g_Discord;


static bool gThread = false;
static AGTAGameMode* gGameMode = nullptr;
static UGameterface* gInterface = nullptr;

static void Thread() {
    printf("[>] Thread started!\n");

    Sleep(90 * 1000); //1 min and 30 sec. delay to ensure the engine is brought up before we run our code.

    while (gThread) {
        if (!gGameMode) {
            for (const auto& gameMode : UObject::FindObjects<AGTAGameMode>())
                gGameMode = gameMode;
        }
        if (gGameMode && !gInterface) {
            if (gGameMode->GetGameterface()) 
                gInterface = gGameMode->GetGameterface();
            
        }
        if (gInterface) {
            if (gInterface->IsPlayingGame() == false) {
                g_Discord->SetState(4);
            }
            else if (gInterface->IsPlayingGame() == true) {
                if (!gInterface->CurrentMenu) {
                    g_Discord->SetState(3);
                }
                else if (gInterface->CurrentMenu) {
                    g_Discord->SetState(2);
                }
            }
        }
        Sleep(5 * 1000); // Update the state every 5 sec.
    }
}

void Attach() {
    Sleep(2 * 1000); // 2sec. delay to ensure the engine is brought up before we run our code.
  
#if defined(CONSOLE_IN_RELEASE)
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    SetConsoleTitleA(MOD_STRING);
    printf("[>] Allocated console\n");
#endif

    if (!InitSdk()) {
        printf("[x] SDK couldn't be initialized!\n");
        gThread = false;
        return;
    }
    else {
        printf("[>] SDK initialized\n");

        g_Core->DetectGameVersion();

        g_Discord->Initialize();
        g_Discord->Update();

        printf("[i] Discord module initialized\n");
        gThread = true;
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Thread, NULL, 0, NULL);
    }
}

void Detach() {
    gThread = false;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
        Attach();
        break;
    case DLL_PROCESS_DETACH:
        Detach();
        break;
    }
    return TRUE;
}