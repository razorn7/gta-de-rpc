#pragma once

#include "SDK.h"
#include "includes/core.hpp"
#include "includes/discord.hpp"

#define CONSOLE_IN_RELEASE

Core* g_Core;
Discord* g_Discord;

#define MOD_STRING "Discord RPC for GTA TDE"

using namespace CG;

static bool gThread = false;

static AGTAGameMode* gGameMode = nullptr;
static UGameterface* gInterface = nullptr;

static void Thread() {
<<<<<<< HEAD
    printf("[>] Thread started!\n");
=======
    printf("[>] Thread started!");
>>>>>>> 674376e97d83eda4746d67acccf47e68255e798a

    Sleep(60 * 2000); //2 min. to ensure if engine is running (for now).

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
            printf("%s\n", gInterface->IsPlayingGame() ? "Playing game" : "Not playing game");
            if (gInterface->IsPlayingGame() == false) {
                g_Discord->SetState(4);
            }
            else if (gInterface->IsPlayingGame() == true) {
                if (!gInterface->CurrentMenu) {
                    g_Discord->SetState(3);
                }
                else if (gInterface->CurrentMenu) {
                    g_Discord->SetState(1);
                }
            }
        }
        Sleep(5 * 1000);
    }
}

void Attach() {
    Sleep(2 * 1000);   // 2sec. delay to ensure the engine is brought up before we run our code.
  
#   //if defined(_DEBUG) || defined(CONSOLE_IN_RELEASE)
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    SetConsoleTitleA(MOD_STRING);
    printf("[>] Allocated console\n");
#  // endif

    if (!InitSdk()) {
        printf("[x] SDK couldn't be initialized!\n");
        gThread = false;
        return;
    }
    else {
<<<<<<< HEAD
        printf("[>] SDK initialized\n");
=======
        printf("[>] SDK initialized");
>>>>>>> 674376e97d83eda4746d67acccf47e68255e798a

        g_Core->DetectGameVersion();

        g_Discord->Initialize();
        g_Discord->Update();

<<<<<<< HEAD
        printf("[i] Discord module initialized\n");
=======
        printf("Done");
>>>>>>> 674376e97d83eda4746d67acccf47e68255e798a
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