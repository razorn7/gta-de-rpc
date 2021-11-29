#pragma once
#include <discord_register.h> //sdk
#include <discord_rpc.h> // sdk
#include <Windows.h> //windows general header

class Discord {
public:
	void Initialize();
	void Update();
};

void setDiscordState(int stateID);
void setGameVersion();
void update();