#ifndef _components_plugins_scripting_h
#define _components_plugins_scripting_h

#include "../../../common.h"
#include "../../../hooks/Hooks.h"
#include "../../../hooks/GameEvents.h"
#include "../../../player/Player.h"
#include "../../../player/PlayerManager.h"
#include "PluginsComponent.h"
#include "Plugin.h"

typedef bool (*Plugin_OnClientConnected)(uint32);
typedef bool (*Plugin_OnClientConnect)(uint32);
typedef void (*Plugin_OnPlayerSpawn)(uint32);
typedef void (*Plugin_OnPlayerRegister)(uint32, bool);
typedef void (*Plugin_OnPlayerUnregister)(uint32);
typedef void (*Plugin_OnGameTick)(bool, bool, bool);
typedef bool (*Plugin_OnPlayerChat)(uint32, const char *, bool);

bool scripting_OnClientChat(CBasePlayerController *controller, const char *text, bool teamonly);

#endif