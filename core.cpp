#include "versionmanager.hpp"
#include "Discord.hpp"
#include "core.hpp"

void Core::DetectGameVersion() {
    Version version = getGameVersion();
    Discord discord;

    if (version == Version::III_V01_00 || version == Version::III_V01_01) {
        discord.gameVersion = 1;
    }
    if (version == Version::VC_V01_00 || version == Version::VC_V01_01) {
        discord.gameVersion = 2;
    }
    if (version == Version::SA_V01_00 || version == Version::SA_V01_01) {
        discord.gameVersion = 3;
    }

    discord.gameImage = discord.gameVersion;
}