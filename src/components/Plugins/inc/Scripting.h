#ifndef _components_plugins_scripting_h
#define _components_plugins_scripting_h

#include "../../../common.h"
#include "../../../hooks/Hooks.h"
#include "../../../hooks/GameEvents.h"
#include "../../../player/Player.h"
#include "../../../player/PlayerManager.h"
#include "PluginsComponent.h"
#include "Plugin.h"

typedef bool (*Plugin_OnClientConnect)(uint32);
typedef void (*Plugin_OnClientDisconnect)(uint32);
typedef void (*Plugin_OnPlayerSpawn)(uint32);
typedef void (*Plugin_OnRoundPrestart)();
typedef void (*Plugin_OnRoundStart)(long, long, const char *);
typedef void (*Plugin_OnRoundEnd)(unsigned char, unsigned char, const char *, unsigned char, short, unsigned char);
typedef void (*Plugin_BombBeginPlant)(uint32, uint16);
typedef void (*Plugin_BombAbortPlant)(uint32, uint16);
typedef void (*Plugin_BombPlanted)(uint32, uint16);
typedef void (*Plugin_BombBeginDefuse)(uint32, uint16);
typedef void (*Plugin_BombAbortDefuse)(uint32, uint16);
typedef void (*Plugin_BombDefused)(uint32, uint16);
typedef void (*Plugin_BombExploded)(uint32, uint16);
typedef void (*Plugin_BombDropped)(uint32);
typedef void (*Plugin_BombPickup)(uint32);
typedef void (*Plugin_OnGameTick)(bool, bool, bool);
typedef bool (*Plugin_OnPlayerChat)(uint32, const char *, bool);
typedef void (*Plugin_OnMapLoad)(const char *);
typedef void (*Plugin_OnMapUnload)(const char *);
typedef bool (*Plugin_OnClientGameMessage)(uint32, int, const char *);
typedef void (*Plugin_OnPlayerDeath)(int, int, int, bool, const char *, bool, short, short, short, short, bool, bool, bool, bool, float, short, short, short);
typedef void (*Plugin_OnPlayerHurt)(int, int, short, short, short, const char *);
typedef bool (*Plugin_ShouldHearVoice)(uint32);

bool scripting_OnClientChat(CBasePlayerController *controller, const char *text, bool teamonly);
bool scripting_OnClientGameMessage(CBasePlayerController *controller, int destination, const char *text);
bool scripting_ShouldHearVoice(Player *player);

enum PlayerStat : int
{
    KILLS = 0,
    DEATHS = 1,
    ASSISTS = 2,
    DAMAGE = 3
};

#endif