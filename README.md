# Discord RPC for GTA TDE

A feature created to show your status/timestamp of any game in the GTA The Definitive Edition trilogy.

This plugin was created in C++ based on the [GTA TDE UE4 SDK](https://github.com/LemonHaze420/GTA-TDE-UE4-SDK) and [TutDiscord](https://github.com/dhanax26/C---Discord-RPC/tree/master/TutDiscord), credits: [LemonHaze420](https://github.com/LemonHaze420)

## Documentation

The plugin was designed for the three games of the GTA Trilogy: The Definitive Edition (III, VC & SA), that is, just do the same installation process and run your game, the plugin will automatically detect your game's version.

This feature is under development, therefore there are likely to be bugs or any other instabilities, all reports/suggestions are welcome.

## Review:
![](https://i.imgur.com/8Jpu1v5.png)

## Setup/Installation
* Download the latest version from our repository.
* Extract the files to the `Gameface\Binaries\Win64` folder, as example: `C:\Games\GTA San Andreas - Definitive Edition\Gameface\Binaries\Win64`.
* Run it and have fun.

## Discord Rich Presence
Below is some resource information:

### States
Events will be updated according to what the player is doing in the game.
| Event name | Description |
| :---: | --- |
| `Just started the game` | It will be shown when the game starts and will update after 1 minute and 30 seconds |
| `In Menu` | It will be shown when the player pause/acess the game main menu |
| `Playing` | It will be shown when the player resume/is playing the game |

### Small Key Images
The RPC small icons will update according to the player's actions in the game, whether it is paused or playing.
| Icon | Name | Description |
| :---: | :---: | --- |
| <img src="https://i.imgur.com/1ILvjxn.png" width="30"> | Playing | It will be shown when the game is being played |
| <img src="https://i.imgur.com/r4Shvg0.png" width="30"> | Paused | It will be shown when the game is paused|

