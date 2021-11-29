#pragma once

#include "SDK.h"
#include "discord.hpp"

Discord* g_Discord;

#define MOD_STRING "Discord RPC for GTA Trilogy"

using namespace CG;

static bool gThread = false;

static AGTAGameMode* gGameMode = nullptr;
static UGameterface* gInterface = nullptr;

static void Thread()
{
    printf("Thread started!");

    Sleep(60 * 1000);

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
            if (gInterface->CurrentMenu) {
                printf("Current Menu: %s\n", gInterface->CurrentMenu->Name.GetName().c_str());

                printf("Current Cutscene = %s", gInterface->CurrentCutscene.GetName().c_str());
                //Sleep(5 * 1000);
            }
            if (gInterface->IsPlayingGame() == false) {
                setDiscordState(4);
                printf("nao esta jogando");
                //Sleep(5 * 1000);
            }
            else if (gInterface->IsPlayingGame() == true) {
                if (!gInterface->CurrentMenu) {
                    setDiscordState(3);
                    //Sleep(5 * 1000);
                }
                else if (gInterface->CurrentMenu) {
                    setDiscordState(1);
                    //Sleep(5 * 1000);
                }
            }
        }
        Sleep(5 * 1000);
    }
}

void Attach()
{

    setGameVersion();

    g_Discord->Initialize();
    g_Discord->Update();

    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    SetConsoleTitleA(MOD_STRING);
    printf("Allocated console\n");

    if (!InitSdk()) {
        gThread = false;
        return;
    }

    printf("SDK initialized\n");

    gThread = true;

    Sleep(2000);
    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Thread, NULL, 0, NULL);
}

void Detach()
{
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