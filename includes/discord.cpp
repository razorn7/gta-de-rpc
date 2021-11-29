#include "Discord.hpp"

#include "core.hpp"
#include <time.h>
#include <chrono>
#include <iostream>
#include <string>
using namespace std;

int gameImage;
int gameVersion;
int currentState = 4;
time_t t_time;
#pragma once

string Discord::ReturnAttribute(int attValue, int attID) {
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
        default:
            return "913153009444327466";
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

        this->Update();
    }
}

void Discord::Initialize() {
    DiscordEventHandlers Handle;

    std::cout << "State: " << gameImage << std::endl;
    memset(&Handle, 0, sizeof(Handle));
    Discord_Initialize(this->ReturnAttribute(currentState, 0).c_str(), &Handle, 1, NULL);
    t_time = std::time(0);
}

void Discord::Update() {
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));

    discordPresence.largeImageKey = this->ReturnAttribute(gameImage, 1).c_str();
    discordPresence.details = this->ReturnAttribute(currentState, 2).c_str();
    discordPresence.state = "The Definitive Editon";
    discordPresence.startTimestamp = t_time;

    Discord_UpdatePresence(&discordPresence);
}

void Discord::SetState(int stateID) {
    currentState = stateID;

    this->Update();
}