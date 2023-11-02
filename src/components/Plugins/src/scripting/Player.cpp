#include "../../../../common.h"
#include "../../../../player/PlayerManager.h"

SMM_API const char *scripting_Player_GetName(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "";

    return player->GetName();
}

SMM_API uint64 scripting_Player_GetSteamID(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    return player->GetSteamID();
}

SMM_API void scripting_Player_Drop(uint32 playerId, ENetworkDisconnectionReason reason)
{
    if (reason < 0 || reason > 69)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    if (!engine)
        return;

    engine->DisconnectClient(*player->GetSlot(), reason);
}

SMM_API bool scripting_Player_IsAuthenticated(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    if (!engine)
        return false;

    return engine->IsClientFullyAuthenticated(*player->GetSlot());
}

SMM_API const char *scripting_Player_GetConvar(uint32 playerId, const char *name)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "";

    if (!engine)
        return "";

    return engine->GetClientConVarValue(*player->GetSlot(), name);
}