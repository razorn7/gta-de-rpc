#pragma once
#include <discord_register.h> //sdk
#include <discord_rpc.h> // sdk
#include <Windows.h> //windows general header

class Discord {
public:
	int gameImage = 0;
	int gameVersion = 0;
	int currentState = 0;
	time_t t_time;

	void Initialize();
	void Update();
	void SetState(int stateID);
	char const* ReturnAttribute(int attValue, int attID);
};