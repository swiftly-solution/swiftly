#include "../../../../common.h"
#include "../../../../player/PlayerManager.h"
#include "../../../../sdk/entity/CCSPlayerController.h"
#include "../../../../sdk/entity/CCSPlayerPawnBase.h"
#include "../../inc/Scripting.h"

extern CEntitySystem *g_pEntitySystem;
std::string SerializeData(std::any data);

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

SMM_API void scripting_Player_SendMessage(uint32 playerId, int dest, const char *text)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    player->SendMsg(dest, text);
}

SMM_API uint8 scripting_Player_GetTeam(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerController *controller = player->GetController();
    if (!controller)
        return CS_TEAM_NONE;

    return controller->m_iTeamNum();
}

SMM_API void scripting_Player_SetTeam(uint32 playerId, int team)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    if (team < 0 || team > 3)
        return;

    player->SwitchTeam(team);
}

SMM_API int scripting_Player_GetHealth(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerPawn *pawn = player->GetPawn();
    if (!pawn)
        return 0;

    return pawn->m_iHealth();
}

SMM_API void scripting_Player_SetHealth(uint32 playerId, int health)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *pawn = player->GetPawn();
    if (!pawn)
        return;

    pawn->m_iHealth = health;
}

SMM_API void scripting_Player_TakeHealth(uint32 playerId, int health)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *pawn = player->GetPawn();
    if (!pawn)
        return;

    pawn->TakeDamage(health);
}

SMM_API void scripting_Player_Kill(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *pawn = player->GetPawn();
    if (!pawn)
        return;

    pawn->CommitSuicide(false, true);
}

SMM_API void scripting_Players_SendMessage(int dest, const char *text)
{
    for (uint16 i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (player == nullptr)
            continue;

        player->SendMsg(dest, text);
    }
}

SMM_API int scripting_Player_GetArmor(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPlayerPawn = player->GetPlayerBasePawn();
    if (!pPlayerPawn)
        return 0;

    return pPlayerPawn->m_ArmorValue();
}

SMM_API void scripting_Player_SetArmor(uint32 playerId, int armor)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPlayerPawn = player->GetPlayerBasePawn();
    if (!pPlayerPawn)
        return;

    pPlayerPawn->m_ArmorValue = (armor > 0 ? armor : 0);
}

SMM_API void scripting_Player_TakeArmor(uint32 playerId, int armor)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPlayerPawn = player->GetPlayerBasePawn();
    if (!pPlayerPawn)
        return;

    if (pPlayerPawn->m_ArmorValue() - armor < 0)
        pPlayerPawn->m_ArmorValue = 0;
    else
        pPlayerPawn->m_ArmorValue = pPlayerPawn->m_ArmorValue() - armor;
}

SMM_API const char *scripting_Player_GetClanTag(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "";

    CCSPlayerController *pPlayerController = player->GetPlayerController();
    if (!pPlayerController)
        return "";

    return pPlayerController->m_szClan().String();
}

SMM_API void scripting_Player_SetClanTag(uint32 playerId, const char *tag)
{
    if (tag == nullptr)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pPlayerController = player->GetPlayerController();
    if (!pPlayerController)
        return;

    pPlayerController->m_szClan = CUtlSymbolLarge(tag);
}

SMM_API void scripting_Player_SetVar(uint32 playerId, const char *name, int type, ...)
{
    if (name == nullptr)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    va_list ap;
    va_start(ap, type);

    if (type == 1)
        player->SetInternalVar(name, std::string(va_arg(ap, const char *)));
    else if (type == 2)
        player->SetInternalVar(name, va_arg(ap, int));
    else if (type == 3)
        player->SetInternalVar(name, va_arg(ap, unsigned int));
    else if (type == 4)
        player->SetInternalVar(name, va_arg(ap, double));
    else if (type == 5)
        player->SetInternalVar(name, va_arg(ap, long));
    else if (type == 6)
        player->SetInternalVar(name, va_arg(ap, unsigned long));
    else if (type == 7)
        player->SetInternalVar(name, (va_arg(ap, int) == 1));
    else if (type == 8)
        player->SetInternalVar(name, va_arg(ap, long long));
    else if (type == 9)
        player->SetInternalVar(name, va_arg(ap, unsigned long long));

    va_end(ap);
}

SMM_API const char *scripting_Player_GetVar(uint32 playerId, const char *name)
{
    if (name == nullptr)
        return "";

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "";

    std::any value = player->GetInternalVar(name);

    std::string data = SerializeData(value);

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API uint32 scripting_Player_GetConnectedTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    return player->GetConnectedTime();
}

SMM_API int scripting_Player_FetchMatchStat(uint32 playerId, PlayerStat stat)
{
    if (stat < 0 || stat > 3)
        return 0;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *playerController = player->GetPlayerController();
    if (!playerController)
        return 0;

    CSMatchStats_t *matchStats = &playerController->m_pActionTrackingServices->m_matchStats();

    if (stat == PlayerStat::KILLS)
        return matchStats->m_iKills.Get();
    else if (stat == PlayerStat::DAMAGE)
        return matchStats->m_iDamage.Get();
    else if (stat == PlayerStat::ASSISTS)
        return matchStats->m_iAssists.Get();
    else if (stat == PlayerStat::DEATHS)
        return matchStats->m_iDeaths.Get();
    else
        return 0;
}

SMM_API void scripting_Player_SetMatchStat(uint32 playerId, PlayerStat stat, int value)
{
    if (stat < 0 || stat > 3)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *playerController = player->GetPlayerController();
    if (!playerController)
        return;

    if (stat == PlayerStat::KILLS)
        playerController->m_pActionTrackingServices->m_matchStats().m_iKills = value;
    else if (stat == PlayerStat::DAMAGE)
        playerController->m_pActionTrackingServices->m_matchStats().m_iDamage = value;
    else if (stat == PlayerStat::ASSISTS)
        playerController->m_pActionTrackingServices->m_matchStats().m_iAssists = value;
    else if (stat == PlayerStat::DEATHS)
        playerController->m_pActionTrackingServices->m_matchStats().m_iDeaths = value;
}