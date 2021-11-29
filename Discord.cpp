#include "Discord.hpp"
#include "versionmanager.hpp"
#include "core.hpp"
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std;

#pragma once

char const* Discord::ReturnAttribute(int attValue, int attID) {
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
            this->currentState = attValue;
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

        this->Update();
    }
}

void Discord::Initialize() {
    DiscordEventHandlers Handle;
    memset(&Handle, 0, sizeof(Handle));
    Discord_Initialize(this->ReturnAttribute(this->gameVersion, 0), &Handle, 1, NULL);

    t_time = std::time(0);
}

void Discord::Update() {
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));

    discordPresence.largeImageKey = this->ReturnAttribute(this->gameImage, 1);
    discordPresence.details = this->ReturnAttribute(this->currentState, 2);
    discordPresence.state = "The Definitive Editon";
    discordPresence.startTimestamp = t_time;

    Discord_UpdatePresence(&discordPresence);
}

void Discord::SetState(int stateID) {
    this->currentState = stateID;

    this->Update();
}