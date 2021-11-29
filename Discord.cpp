#include "Discord.hpp"
#include "versionmanager.hpp"
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std;

#pragma once
/*
*   0: No version recognized
    1: III
    2: VC
    3: SA
*/
int gameVersion = 3;
int gameImage = 3;
int currentState = 4;
time_t t_time;

/*
*   0: Rich Presence IDs
    1: Large Image Key
    3: Events - State
*/
char const* setAttributes(int attValue, int attID) {
    if (attID == 0) {
        switch (attValue) {
        case 1:
            return "913153009444327466";
            break;
        case 2:
            return "912710432899362866";
            break;
        case 3:
            return "912513971267969064";
            break;
        }
    }
    else if (attID == 1) {
        switch (attValue) {
        case 1:
            return "iii-discord";
            break;
        case 2:
            return "vc-discord";
            break;
        case 3:
            return "sa-discord";
            break;
        }
    }
    else if (attID == 2) {
        switch (attValue) {
            currentState = attValue;
        case 1:
            return "In Menu";
            break;
        case 2:
            return "Viewing The Map";
            break;
        case 3:
            return "Playing";
            break;
        case 4:
            return "Just started the game";
            break;
        }

        std::cout << currentState << endl;
        update();
    }
}

void Discord::Initialize()
{
    DiscordEventHandlers Handle;
    memset(&Handle, 0, sizeof(Handle));
    Discord_Initialize(setAttributes(gameVersion, 0), &Handle, 1, NULL);

    t_time = std::time(0);
}

void Discord::Update()
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));

    discordPresence.largeImageKey = setAttributes(gameImage, 1);
    discordPresence.details = setAttributes(currentState, 2);
    discordPresence.state = "The Definitive Editon";
    discordPresence.startTimestamp = t_time;

    Discord_UpdatePresence(&discordPresence);
}

void update() {
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));

    discordPresence.largeImageKey = setAttributes(gameImage, 1);
    discordPresence.details = setAttributes(currentState, 2);
    discordPresence.state = "The Definitive Editon";
    discordPresence.startTimestamp = t_time;

    Discord_UpdatePresence(&discordPresence);
}

void setGameVersion() {
    Version version = getGameVersion();

    if (version == Version::III_V01_00 || version == Version::III_V01_01) gameVersion = 1;
    if (version == Version::VC_V01_00 || version == Version::VC_V01_01) gameVersion = 2;
    if (version == Version::SA_V01_00 || version == Version::SA_V01_01) gameVersion = 3;

    gameImage = gameVersion;
}

void setDiscordState(int stateID) {
    // setAttributes(stateID, 2);
    currentState = stateID;

    update();
}