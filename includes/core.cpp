#include "discord.hpp"
#include "core.hpp"
#include "..\versionmanager.hpp"

extern int gameImage, gameVersion;

void Core::DetectGameVersion() {
    Version version = getGameVersion();

    if (version == Version::III_V01_00 || version == Version::III_V01_01) {
       gameVersion = 1;
    }
    if (version == Version::VC_V01_00 || version == Version::VC_V01_01) {
        gameVersion = 2;
    }
    if (version == Version::SA_V01_00 || version == Version::SA_V01_01) {
        gameVersion = 3;
    }

    gameImage = gameVersion;
}