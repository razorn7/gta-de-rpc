#pragma once

#include "discord.hpp"
#include "core.hpp"
#include <time.h>
#include <chrono>
#include <iostream>
#include <string>

using namespace std;

int gameImage = 1, gameVersion = 1, currentState = 1, smallImageText = 1;
time_t t_time;

string Discord::ReturnAttribute(int attValue, int attID) {
    /*
    * Application ID
    */
    if (attID == 0) {
        switch (attValue) {
            case 1:
                return "913153009444327466"; // GTA III - Application
            break;
            case 2:
                return "912710432899362866"; // GTA VC - Application
            break;
            case 3:
                return "912513971267969064"; // GTA SA - Application
            break;
        }
    }
    /*
    * Icons
    */
    else if (attID == 1) {
        switch (attValue) {
            case 1:
                return "iii-discord"; // GTA III - Icon
            break;
            case 2:
                return "vc-discord"; // GTA VC - Icon
            break;
            case 3:
                return "sa-discord"; // GTA SA - Icon
            break;
        }
    }
    /*
    * States
    */
    else if (attID == 2) {
        currentState = attValue;
        switch (attValue) {
            case 1:
                return "Just started the game";
            break;
            case 2:
                return "In Menu";
            break;
            case 3:
                return "Playing";
            break;
            case 4:
                return "Just started the game";
            break;
        }
    }
    /*
    * Small icon states
    */
    else if (attID == 3) {
        switch (attValue) {
            case 1: case 3: case 4:
                return "play";
            break;
            case 2:
                return "paused";
            break;
        }
    }


    // Update after changes
    this->Update();
}

void Discord::Initialize() {
    DiscordEventHandlers Handle;

    memset(&Handle, 0, sizeof(Handle));
    Discord_Initialize(this->ReturnAttribute(gameVersion, 0).c_str(), &Handle, 1, NULL);
    t_time = std::time(0);
}

void Discord::Update() {
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));

    discordPresence.largeImageKey = this->ReturnAttribute(gameImage, 1).c_str();
    discordPresence.details = this->ReturnAttribute(currentState, 2).c_str();
    discordPresence.smallImageKey = this->ReturnAttribute(currentState, 3).c_str();
    discordPresence.startTimestamp = t_time;

    Discord_UpdatePresence(&discordPresence);
}

void Discord::SetState(int stateID) {
    currentState = stateID;
    smallImageText = currentState;

    this->Update();
}