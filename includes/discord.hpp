#pragma once
#include <discord_register.h> //sdk
#include <discord_rpc.h> // sdk
#include <Windows.h> //windows general header
#include <string>

using namespace std;

class Discord {
public:

	void Initialize();
	void Update();
	void SetState(int stateID);
	string ReturnAttribute(int attValue, int attID);
};