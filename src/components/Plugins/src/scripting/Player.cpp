#include "../../../../common.h"
#include "../../../../player/PlayerManager.h"
#include "../../../../sdk/entity/CCSPlayerController.h"
#include "../../../../sdk/entity/CCSPlayerPawnBase.h"
#include "../../../../sdk/entity/CBaseCombatCharacter.h"
#include "../../inc/Scripting.h"
#include "../../../../utils/plat.h"
#include "../../../../commands/CommandsManager.h"

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

SMM_API const char *scripting_Player_GetSteamID2(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "STEAM_0:0:000000000";

    uint64_t steamid = player->GetSteamID();
    if (steamid == 0)
        return "STEAM_0:0:000000000";

    static const uint64_t base = 76561197960265728;
    std::string data = string_format("STEAM_0:%d:%llu", (steamid - base) % 2, (steamid - base) / 2);

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API void scripting_Player_Drop(uint32 playerId, int reason)
{
    if (reason < 0 || reason > 69)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    if (!engine)
        return;

    engine->DisconnectClient(*player->GetSlot(), (ENetworkDisconnectionReason)reason);
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

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return 0;

    return pawn->m_iHealth();
}

SMM_API void scripting_Player_SetHealth(uint32 playerId, int health)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    pawn->m_iHealth = health;
}

SMM_API int scripting_Player_GetMaxHealth(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return 0;

    return pawn->m_iMaxHealth();
}

SMM_API void scripting_Player_SetMaxHealth(uint32 playerId, int health)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    pawn->m_iMaxHealth = health;
}

SMM_API void scripting_Player_TakeHealth(uint32 playerId, int health)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
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

    CCSPlayerPawn *pPlayerPawn = player->GetPlayerPawn();
    if (!pPlayerPawn)
        return 0;

    return pPlayerPawn->m_ArmorValue();
}

SMM_API void scripting_Player_SetArmor(uint32 playerId, int armor)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPlayerPawn = player->GetPlayerPawn();
    if (!pPlayerPawn)
        return;

    pPlayerPawn->m_ArmorValue = (armor > 0 ? armor : 0);
}

SMM_API void scripting_Player_TakeArmor(uint32 playerId, int armor)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPlayerPawn = player->GetPlayerPawn();
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

SMM_API const char *scripting_Player_GetIPAddress(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "";

    return player->GetIPAddress().c_str();
}

SMM_API const char *scripting_Player_GetCoords(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "";

    std::string data = SerializeData(player->GetCoords());

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API void scripting_Player_SetCoords(uint32 playerId, float x, float y, float z)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    player->SetCoords(x, y, z);
}

SMM_API const char *scripting_Player_GetVelocity(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "";

    CBasePlayerPawn *pawn = player->GetPawn();
    if (!pawn)
        return "";

    std::string data = SerializeData(pawn->m_vecAbsVelocity());

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API void scripting_Player_SetVelocity(uint32 playerId, float x, float y, float z)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *pawn = player->GetPawn();
    if (!pawn)
        return;

    Vector vec(x, y, z);
    pawn->m_vecAbsVelocity = vec;
}

SMM_API int scripting_Player_GetMoney(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return 0;

    return controller->m_pInGameMoneyServices->m_iAccount();
}

SMM_API void scripting_Player_SetMoney(uint32 playerId, int money)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return;

    controller->m_pInGameMoneyServices->m_iAccount = money;
}

SMM_API void scripting_Player_TakeMoney(uint32 playerId, int money)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return;

    controller->m_pInGameMoneyServices->m_iAccount = controller->m_pInGameMoneyServices->m_iAccount() - money;
}

SMM_API void scripting_Player_Weapons_Drop(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CPlayer_WeaponServices *weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return;

    CCSPlayer_ItemServices *itemServices = pawn->m_pItemServices();
    if (!itemServices)
        return;

    CUtlVector<CHandle<CBasePlayerWeapon>> *weapons = weaponServices->m_hMyWeapons();
    if (!weapons)
        return;

    FOR_EACH_VEC(*weapons, i)
    {
        CHandle<CBasePlayerWeapon> &weaponHandle = (*weapons)[i];
        if (!weaponHandle.IsValid())
            continue;

        CBasePlayerWeapon *weapon = weaponHandle.Get();
        if (!weapon)
            continue;

        weaponServices->m_hActiveWeapon = weaponHandle;
        itemServices->DropPlayerWeapon(weapon);
    }
}

SMM_API void scripting_Player_Weapons_Remove(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CPlayer_WeaponServices *weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return;

    CCSPlayer_ItemServices *itemServices = pawn->m_pItemServices();
    if (!itemServices)
        return;

    CUtlVector<CHandle<CBasePlayerWeapon>> *weapons = weaponServices->m_hMyWeapons();
    if (!weapons)
        return;

    FOR_EACH_VEC(*weapons, i)
    {
        CHandle<CBasePlayerWeapon> &weaponHandle = (*weapons)[i];
        if (!weaponHandle.IsValid())
            continue;

        CBasePlayerWeapon *weapon = weaponHandle.Get();
        if (!weapon)
            continue;

        weaponServices->m_hActiveWeapon = weaponHandle;
        itemServices->DropPlayerWeapon(weapon);
        weaponServices->RemoveWeapon(weapon);
        weapon->Despawn();
    }
}

SMM_API void scripting_Player_Weapon_Remove(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CPlayer_WeaponServices *weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return;

    CCSPlayer_ItemServices *itemServices = pawn->m_pItemServices();
    if (!itemServices)
        return;

    weaponServices->m_hActiveWeapon = weapon;
    itemServices->DropPlayerWeapon(weapon);
    weaponServices->RemoveWeapon(weapon);
    weapon->Despawn();
}

SMM_API void scripting_Player_Weapon_SetClipAmmo(uint32 playerId, uint32 slot, int ammo)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    CCSWeaponBaseVData *vData = weapon->GetWeaponVData();
    if (vData)
    {
        vData->m_iMaxClip1 = ammo;
        vData->m_iDefaultClip1 = ammo;
    }

    weapon->m_iClip1 = ammo;
}

SMM_API void scripting_Player_Weapon_SetClip2Ammo(uint32 playerId, uint32 slot, int ammo)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    CCSWeaponBaseVData *vData = weapon->GetWeaponVData();
    if (vData)
    {
        vData->m_iMaxClip2 = ammo;
        vData->m_iDefaultClip2 = ammo;
    }

    weapon->m_iClip2 = ammo;
}

SMM_API int32_t scripting_Player_Weapon_GetNextPrimaryAttackTick(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return 0;

    return weapon->m_nNextPrimaryAttackTick();
}

SMM_API int32_t scripting_Player_Weapon_GetNextSecondaryAttackTick(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return 0;

    return weapon->m_nNextSecondaryAttackTick();
}

SMM_API void scripting_Player_Weapon_SetNextPrimaryAttackTick(uint32 playerId, uint32 slot, int32_t tick)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_nNextPrimaryAttackTick = tick;
}

SMM_API void scripting_Player_Weapon_SetNextSecondaryAttackTick(uint32 playerId, uint32 slot, int32_t tick)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_nNextSecondaryAttackTick = tick;
}

SMM_API float scripting_Player_Weapon_GetNextPrimaryAttackTickRatio(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return 0.0f;

    return weapon->m_flNextPrimaryAttackTickRatio();
}

SMM_API float scripting_Player_Weapon_GetNextSecondaryAttackTickRatio(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return 0.0f;

    return weapon->m_flNextSecondaryAttackTickRatio();
}

SMM_API void scripting_Player_Weapon_SetNextPrimaryAttackTickRatio(uint32 playerId, uint32 slot, float ratio)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_flNextPrimaryAttackTickRatio = ratio;
}

SMM_API void scripting_Player_Weapon_SetNextSecondaryAttackTickRatio(uint32 playerId, uint32 slot, float ratio)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_flNextSecondaryAttackTickRatio = ratio;
}

SMM_API uint32_t scripting_Player_Weapon_GetSilencerType(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return CSWeaponSilencerType::WEAPONSILENCER_NONE;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return CSWeaponSilencerType::WEAPONSILENCER_NONE;

    CCSWeaponBaseVData *vData = weapon->GetWeaponVData();
    if (!vData)
        return CSWeaponSilencerType::WEAPONSILENCER_NONE;

    return vData->m_eSilencerType();
}

SMM_API void scripting_Player_Weapons_SetActiveWeapon(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromSlot((gear_slot_t)slot);
    if (!weapon)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CPlayer_WeaponServices *weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return;

    CCSPlayer_ItemServices *itemServices = pawn->m_pItemServices();
    if (!itemServices)
        return;

    weaponServices->m_hActiveWeapon = weapon;
}

SMM_API void scripting_Player_Weapon_SetReserveAmmo(uint32 playerId, uint32 slot, int ammo)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    CCSWeaponBaseVData *vData = weapon->GetWeaponVData();
    if (vData)
    {
        vData->m_nPrimaryReserveAmmoMax = ammo;
    }

    weapon->m_pReserveAmmo[0] = ammo;
}

SMM_API void scripting_Player_Weapon_Drop(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CPlayer_WeaponServices *weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return;

    CCSPlayer_ItemServices *itemServices = pawn->m_pItemServices();
    if (!itemServices)
        return;

    weaponServices->m_hActiveWeapon = weapon;
    itemServices->DropPlayerWeapon(weapon);
}

SMM_API void scripting_Player_Weapon_SetStatTrack(uint32 playerId, uint32 slot, bool stattrack)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_nFallbackStatTrak = (int)stattrack;
}

SMM_API void scripting_Player_Weapon_SetWear(uint32 playerId, uint32 slot, float wear)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_flFallbackWear = wear;
}

SMM_API void scripting_Player_Weapon_SetSticker(uint32 playerId, uint32 slot, int stickerslot, uint32_t stickerid)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    float stickeridfloat = *reinterpret_cast<float *>(&stickerid);
    g_Signatures->FetchSignature<CAttributeList_SetOrAddAttributeValueByName>("CAttributeList_SetOrAddAttributeValueByName")(weapon->m_AttributeManager().m_Item().m_NetworkedDynamicAttributes(), string_format("sticker slot %d id", stickerslot).c_str(), stickeridfloat);
}

SMM_API void scripting_Player_Weapon_SetPaintKit(uint32 playerId, uint32 slot, int paintkit)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_nFallbackPaintKit = paintkit;
}

SMM_API void scripting_Player_Weapon_SetSeed(uint32 playerId, uint32 slot, int seed)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_nFallbackSeed = seed;
}

SMM_API bool scripting_Player_Weapon_GetStatTrack(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return false;

    return (weapon->m_nFallbackStatTrak() != 0);
}
SMM_API float scripting_Player_Weapon_GetWear(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return 0.0f;

    return weapon->m_flFallbackWear();
}
SMM_API int scripting_Player_Weapon_GetPaintKit(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return 0;

    return weapon->m_nFallbackPaintKit();
}
SMM_API int scripting_Player_Weapon_GetSeed(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return 0;

    return weapon->m_nFallbackSeed();
}

SMM_API uint32 scripting_Player_Weapon_GetType(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return gear_slot_t::GEAR_SLOT_INVALID;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return gear_slot_t::GEAR_SLOT_INVALID;

    return weapon->GetWeaponVData()->m_GearSlot();
}

SMM_API const char *scripting_Player_Weapon_GetName(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "";

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return "";

    return weapon->GetClassname();
}

SMM_API void scripting_Player_SetFlashDuration(uint32 playerId, float duration)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pawn = player->GetPlayerBasePawn();
    if (!pawn)
        return;

    pawn->m_flFlashDuration = duration;
}

SMM_API void scripting_Player_Weapons_Give(uint32 playerId, const char *name)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CCSPlayer_ItemServices *itemServices = pawn->m_pItemServices();
    if (!itemServices)
        return;

    std::string n = std::string(name);

    if (n == "item_defuser" && player->GetController() && player->GetController()->m_iTeamNum() == CS_TEAM_CT)
        itemServices->m_bHasDefuser = true;
    else if (n == "item_assaultsuit")
    {
        itemServices->m_bHasHelmet = true;
        scripting_Player_SetArmor(playerId, 100);
    }
    else if (n == "item_kevlar")
    {
        scripting_Player_SetArmor(playerId, 100);
    }
    else
        pawn->GiveNamedItem(name);
}

SMM_API uint32_t scripting_Player_Weapons_GetWeaponID(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromSlot((gear_slot_t)slot);
    if (!weapon)
        return 0;

    return weapon->m_AttributeManager().m_Item().m_iItemDefinitionIndex();
}

SMM_API bool scripting_Player_Weapon_Exists(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    return (weapon != nullptr);
}

std::vector<uint16_t> paintkitsFallbackCheck = {1171, 1170, 1169, 1164, 1162, 1161, 1159, 1175, 1174, 1167, 1165, 1168, 1163, 1160, 1166, 1173};

SMM_API void scripting_Player_Weapon_SetDefaultChangeSkinAttributes(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_AttributeManager().m_Item().m_iItemIDHigh = -1;

    if (weapon->GetWeaponVData()->m_GearSlot == gear_slot_t::GEAR_SLOT_KNIFE)
    {
        weapon->m_AttributeManager().m_Item().m_iEntityQuality = 3;
    }

    int paintkit = weapon->m_nFallbackPaintKit();
    bool legacy = (std::find(paintkitsFallbackCheck.begin(), paintkitsFallbackCheck.end(), paintkit) == paintkitsFallbackCheck.end());

    if (weapon->m_CBodyComponent() && weapon->m_CBodyComponent()->m_pSceneNode())
    {
        CSkeletonInstance *skeleton = weapon->m_CBodyComponent()->m_pSceneNode()->GetSkeletonInstance();
        if (skeleton && skeleton->m_modelState())
            if (skeleton->m_modelState()->m_MeshGroupMask() != (legacy == true ? 2 : 1))
            {
                skeleton->m_modelState()->m_MeshGroupMask = (legacy == true ? 2 : 1);
            }
    }

    CCSPlayer_ViewModelServices *viewmodelServices = pawn->m_pViewModelServices();
    if (!viewmodelServices)
        return;

    CHandle<CBaseViewModel> *viewmodelHandles = viewmodelServices->m_hViewModel();
    if (!viewmodelHandles)
        return;

    CBaseViewModel *viewmodel = viewmodelHandles[0];

    if (!viewmodel)
        return;

    if (viewmodel->m_CBodyComponent() && viewmodel->m_CBodyComponent()->m_pSceneNode())
    {
        CSkeletonInstance *viewmodelskeleton = viewmodel->m_CBodyComponent()->m_pSceneNode()->GetSkeletonInstance();
        if (viewmodelskeleton && viewmodelskeleton->m_modelState())
            if (viewmodelskeleton->m_modelState()->m_MeshGroupMask() != (legacy == true ? 2 : 1))
            {
                viewmodelskeleton->m_modelState()->m_MeshGroupMask = (legacy == true ? 2 : 1);
            }
    }

    viewmodel->m_CBodyComponent.StateUpdate();
}

SMM_API void scripting_Player_Weapon_SetNametag(uint32 playerId, uint32 slot, const char *text)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    auto customNamePtr = weapon->m_AttributeManager().m_Item().m_szCustomName();
    Plat_WriteMemory((void *)customNamePtr, reinterpret_cast<byte *>(const_cast<char *>(text)), strlen(text));
}

SMM_API void scripting_Player_ExecuteCommand(uint32 playerId, const char *cmd)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    if (starts_with(cmd, "sw_"))
    {
        CCommand tokenizedArgs;
        tokenizedArgs.Tokenize(cmd);

        std::vector<std::string> cmdString;
        for (int i = 1; i < tokenizedArgs.ArgC(); i++)
            cmdString.push_back(tokenizedArgs[i]);

        std::string commandName = replace(tokenizedArgs[0], "sw_", "");

        Command *command = g_commandsManager->FetchCommand(commandName);
        if (command)
            command->Exec(player->GetSlot()->Get(), cmdString, true);
    }
    else
        engine->ClientCommand(*player->GetSlot(), cmd);
}

SMM_API void scripting_Player_SetModel(uint32 playerId, const char *model)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    bool hasModel = (g_precacher->HasModelInList(model));
    if (!hasModel)
    {
        g_precacher->AddModel(model);
        PRINTF("Precacher", "Model '%s' was not precached before and it was added to the list.\n", model);
        PRINT("Precacher", "It may work on the second map change if the model is valid.\n");
    }

    pawn->SetModel(model);
}

SMM_API void scripting_Player_SetPin(uint32 playerId, int index)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return;

    CCSPlayerController_InventoryServices *inventory = controller->m_pInventoryServices();
    if (!inventory)
        return;

    MedalRank_t rank[5];

    rank[5] = static_cast<MedalRank_t>(index);
    Plat_WriteMemory(reinterpret_cast<uint8_t *>(&inventory->m_rank[5]), reinterpret_cast<uint8_t *>(&rank[5]), 5);
    SetStateChanged((Z_CBaseEntity *)controller, 0x6D0 + 0x44);
}

SMM_API void scripting_Player_SetMusicKit(uint32 playerId, int musicid)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return;

    CCSPlayerController_InventoryServices *inventory = controller->m_pInventoryServices();
    if (!inventory)
        return;

    inventory->m_unMusicID = musicid;
}

SMM_API void scripting_Player_ShowMenu(uint32 playerId, const char *menuid)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    if (player->HasMenuShown())
        return;

    player->ShowMenu(menuid);
}

SMM_API void scripting_Player_HideMenu(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    if (!player->HasMenuShown())
        return;

    player->HideMenu();
}

SMM_API int scripting_Player_GetLatency(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return -1;
    if (player->IsFakeClient())
        return 0;

    INetChannelInfo *netinfo = engine->GetPlayerNetInfo(*player->GetSlot());

    return netinfo->GetLatency(FLOW_INCOMING) + netinfo->GetLatency(FLOW_OUTGOING);
}

SMM_API void scripting_Player_SetGloves(uint32 playerId, uint16_t defindex, int paintkit, int seed, float wear)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CEconItemView *gloves_view = pawn->m_EconGloves();

    gloves_view->m_iItemDefinitionIndex = defindex;
    gloves_view->m_iItemIDLow = -1;
    gloves_view->m_iItemIDHigh = (16384 & 0xFFFFFFFF);

    gloves_view->m_bInitialized = true;

    g_Plugin.NextFrame([gloves_view, paintkit, seed, wear, pawn]() -> void
                       {
            g_Signatures->FetchSignature<CAttributeList_SetOrAddAttributeValueByName>("CAttributeList_SetOrAddAttributeValueByName")(gloves_view->m_NetworkedDynamicAttributes(), "set item texture prefab", paintkit);
            g_Signatures->FetchSignature<CAttributeList_SetOrAddAttributeValueByName>("CAttributeList_SetOrAddAttributeValueByName")(gloves_view->m_NetworkedDynamicAttributes(), "set item texture seed", static_cast<float>(seed));
            g_Signatures->FetchSignature<CAttributeList_SetOrAddAttributeValueByName>("CAttributeList_SetOrAddAttributeValueByName")(gloves_view->m_NetworkedDynamicAttributes(), "set item texture wear", wear);

            g_Signatures->FetchSignature<CBaseModelEntity_SetBodygroup>("CBaseModelEntity_SetBodygroup")(pawn, "default_gloves", 1LL); });
}

SMM_API float scripting_Player_GetGravity(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return 0.0f;

    return pawn->m_flGravityScale();
}

SMM_API MoveType_t scripting_Player_GetMoveType(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return MOVETYPE_NONE;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return MOVETYPE_NONE;

    return bPawn->m_MoveType();
}

SMM_API MoveType_t scripting_Player_GetActualMoveType(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return MOVETYPE_NONE;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return MOVETYPE_NONE;

    return bPawn->m_nActualMoveType();
}

SMM_API void scripting_Player_SetGravity(uint32 playerId, float gravity)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    pawn->m_flGravityScale = gravity;
}

SMM_API float scripting_Player_GetSpeed(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pawn = player->GetPlayerBasePawn();
    if (!pawn)
        return 0.0f;

    return pawn->m_flVelocityModifier();
}

SMM_API void scripting_Player_SetSpeed(uint32 playerId, float speed)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pawn = player->GetPlayerBasePawn();
    if (!pawn)
        return;

    pawn->m_flVelocityModifier = speed;
}

QAngle scripting_Player_GetEyeAnglesRaw(uint32 playerId)
{
    QAngle angle(0.0f, 0.0f, 0.0f);

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return angle;

    CCSPlayerPawnBase *pawn = player->GetPlayerBasePawn();
    if (!pawn)
        return angle;

    return pawn->m_angEyeAngles();
}

SMM_API const char *scripting_Player_GetEyeAngles(uint32 playerId)
{
    std::string data = SerializeData(scripting_Player_GetEyeAnglesRaw(playerId));

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API void scripting_Player_SetEyeAngles(uint32 playerId, float x, float y, float z)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pawn = player->GetPlayerBasePawn();
    if (!pawn)
        return;

    QAngle angle(x, y, z);
    pawn->m_angEyeAngles = angle;
}

SMM_API void scripting_Player_Respawn(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return;

    controller->Respawn();
}

SMM_API void scripting_Player_SetDesiredFOV(uint32 playerId, uint32_t fov)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *controller = player->GetController();
    if (!controller)
        return;

    controller->m_iDesiredFOV = fov;
}

SMM_API uint32_t scripting_Player_GetDesiredFOV(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerController *controller = player->GetController();
    if (!controller)
        return 0;

    return controller->m_iDesiredFOV();
}

SMM_API void scripting_Player_SetHealthShotBoostEffectExpirationTime(uint32 playerId, float expireTime)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    pawn->m_flHealthShotBoostExpirationTime = expireTime;
}

SMM_API void scripting_Player_SetConvar(uint32 playerId, const char *cvarname, const char *cvarvalue)
{
    if (cvarname == nullptr || cvarvalue == nullptr)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    player->SetClientConvar(cvarname, cvarvalue);
}

SMM_API const char *scripting_Player_GetChatTag(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return "";

    std::string data = player->tag;

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API void scripting_Player_SetChatTag(uint32 playerId, const char *tag)
{
    if (tag == nullptr)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    player->tag = tag;
}

SMM_API void scripting_Player_SetChatTagColor(uint32 playerId, const char *tagcolor)
{
    if (tagcolor == nullptr)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    player->tagcolor = tagcolor;
}

SMM_API void scripting_Player_SetNameColor(uint32 playerId, const char *namecolor)
{
    if (namecolor == nullptr)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    player->namecolor = namecolor;
}

SMM_API void scripting_Player_SetChatColor(uint32 playerId, const char *chatcolor)
{
    if (chatcolor == nullptr)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    player->chatcolor = chatcolor;
}

SMM_API void scripting_Player_SetName(uint32 playerId, const char *name)
{
    if (name == nullptr)
        return;

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *controller = player->GetController();
    if (!controller)
        return;

    auto namePtr = controller->m_iszPlayerName();
    Plat_WriteMemory((void *)namePtr, reinterpret_cast<byte *>(const_cast<char *>(name)), 128);
}

SMM_API bool scripting_Player_IsFirstSpawn(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    return player->IsFirstSpawn();
}

SMM_API bool scripting_Player_IsAlive(uint32 playerId)
{

    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->IsAlive();
}

SMM_API void scripting_Player_SetMoveType(uint32 playerId, MoveType_t movetype)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return;

    bPawn->m_MoveType = movetype;
}

SMM_API void scripting_Player_SetActualMoveType(uint32 playerId, MoveType_t actualmovetype)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return;

    bPawn->m_nActualMoveType = actualmovetype;
}

SMM_API bool scripting_Player_IsFakeClient(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    return player->IsFakeClient();
}

SMM_API void scripting_Player_SetCompetitiveRanking(uint32 playerId, int ranking)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return;

    controller->m_iCompetitiveRanking = ranking;
}

SMM_API void scripting_Player_SetCompetitiveWins(uint32 playerId, int wins)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return;

    controller->m_iCompetitiveWins = wins;
}

SMM_API void scripting_Player_SetCompetitiveRankType(uint32 playerId, int type)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return;

    controller->m_iCompetitiveRankType = type;
}

SMM_API bool scripting_Player_GetAutoKickDisabled(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return false;

    return bController->m_bAutoKickDisabled;
}

SMM_API void scripting_Player_SetAutoKickDisabled(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_bAutoKickDisabled = val;
}

SMM_API int32_t scripting_Player_GetAvailableEntitySteadyState(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return 0;

    return bController->m_nAvailableEntitySteadyState;
}

SMM_API void scripting_Player_SetAvailableEntitySteadyState(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_nAvailableEntitySteadyState = val;
}

SMM_API bool scripting_Player_GetPredict(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return false;

    return bController->m_bPredict;
}

SMM_API void scripting_Player_SetPredict(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_bPredict = val;
}

SMM_API uint32_t scripting_Player_GetTickBase(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return 0;

    return bController->m_nTickBase;
}

SMM_API void scripting_Player_SetTickBase(uint32 playerId, uint32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_nTickBase = val;
}

SMM_API float scripting_Player_GetLerpTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return 0.0f;

    return bController->m_fLerpTime;
}

SMM_API void scripting_Player_SetLerpTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_fLerpTime = val;
}

SMM_API int32_t scripting_Player_GetLastRealCommandNumberExecuted(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return 0;

    return bController->m_nLastRealCommandNumberExecuted;
}

SMM_API void scripting_Player_SetLastRealCommandNumberExecuted(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_nLastRealCommandNumberExecuted = val;
}

SMM_API float scripting_Player_GetLastPlayerTalkTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return 0.0f;

    return bController->m_flLastPlayerTalkTime;
}

SMM_API void scripting_Player_SetLastPlayerTalkTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_flLastPlayerTalkTime = val;
}

SMM_API int32_t scripting_Player_GetLastLateCommandExecuted(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return 0;

    return bController->m_nLastLateCommandExecuted;
}

SMM_API void scripting_Player_SetLastLateCommandExecuted(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_nLastLateCommandExecuted = val;
}

SMM_API float scripting_Player_GetLastEntitySteadyState(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return 0.0f;

    return bController->m_flLastEntitySteadyState;
}

SMM_API void scripting_Player_SetLastEntitySteadyState(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_flLastEntitySteadyState = val;
}

SMM_API bool scripting_Player_GetLagCompensation(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return false;

    return bController->m_bLagCompensation;
}

SMM_API void scripting_Player_SetLagCompensation(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_bLagCompensation = val;
}

SMM_API bool scripting_Player_GetIsLowViolence(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return false;

    return bController->m_bIsLowViolence;
}

SMM_API void scripting_Player_SetIsLowViolence(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_bIsLowViolence = val;
}

SMM_API bool scripting_Player_GetIsHLTV(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return false;

    return bController->m_bIsHLTV;
}

SMM_API void scripting_Player_SetIsHLTV(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_bIsHLTV = val;
}

SMM_API bool scripting_Player_GetHasAnySteadyStateEnts(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return false;

    return bController->m_bHasAnySteadyStateEnts;
}

SMM_API void scripting_Player_SetHasAnySteadyStateEnts(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_bHasAnySteadyStateEnts = val;
}

SMM_API bool scripting_Player_GetGamePaused(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return false;

    return bController->m_bGamePaused;
}

SMM_API void scripting_Player_SetGamePaused(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerController *bController = player->GetController();
    if (!bController)
        return;

    bController->m_bGamePaused = val;
}

SMM_API uint32_t scripting_Player_GetHighestGeneratedServerViewAngleChangeIndex(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return 0;

    return bPawn->m_nHighestGeneratedServerViewAngleChangeIndex;
}

SMM_API void scripting_Player_SetHighestGeneratedServerViewAngleChangeIndex(uint32 playerId, uint32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return;

    bPawn->m_nHighestGeneratedServerViewAngleChangeIndex = val;
}

SMM_API uint32_t scripting_Player_GetHideHUD(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return 0;

    return bPawn->m_iHideHUD;
}

SMM_API void scripting_Player_SetHideHUD(uint32 playerId, uint32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return;

    bPawn->m_iHideHUD = val;
}

SMM_API bool scripting_Player_GetInitHUD(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return false;

    return bPawn->m_fInitHUD;
}

SMM_API void scripting_Player_SetInitHUD(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return;

    bPawn->m_fInitHUD = val;
}

SMM_API float scripting_Player_GetHltvReplayDelay(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return 0.0f;

    return bPawn->m_fHltvReplayDelay;
}

SMM_API void scripting_Player_SetHltvReplayDelay(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return;

    bPawn->m_fHltvReplayDelay = val;
}

SMM_API float scripting_Player_GetHltvReplayEnd(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return 0.0f;

    return bPawn->m_fHltvReplayEnd;
}

SMM_API void scripting_Player_SetHltvReplayEnd(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerPawn *bPawn = player->GetPawn();
    if (!bPawn)
        return;

    bPawn->m_fHltvReplayEnd = val;
}

SMM_API uint16_t scripting_Player_GetCharacterDefIndex(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0;

    return pPawn->m_nCharacterDefIndex;
}

SMM_API void scripting_Player_SetCharacterDefIndex(uint32 playerId, uint16_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_nCharacterDefIndex = val;
}

SMM_API bool scripting_Player_GetHasFemaleVoice(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bHasFemaleVoice;
}

SMM_API void scripting_Player_SetHasFemaleVoice(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bHasFemaleVoice = val;
}

SMM_API bool scripting_Player_GetInHostageResetZone(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bInHostageResetZone;
}

SMM_API void scripting_Player_SetInHostageResetZone(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bInHostageResetZone = val;
}

SMM_API bool scripting_Player_GetInBuyZone(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bInBuyZone;
}

SMM_API void scripting_Player_SetInBuyZone(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bInBuyZone = val;
}

SMM_API bool scripting_Player_GetWasInBuyZone(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bWasInBuyZone;
}

SMM_API void scripting_Player_SetWasInBuyZone(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bWasInBuyZone = val;
}

SMM_API bool scripting_Player_GetInHostageRescueZone(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bInHostageRescueZone;
}

SMM_API void scripting_Player_SetInHostageRescueZone(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bInHostageRescueZone = val;
}

SMM_API bool scripting_Player_GetInBombZone(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bInBombZone;
}

SMM_API void scripting_Player_SetInBombZone(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bInBombZone = val;
}

SMM_API bool scripting_Player_GetWasInHostageRescueZone(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bWasInHostageRescueZone;
}

SMM_API void scripting_Player_SetWasInHostageRescueZone(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bWasInHostageRescueZone = val;
}

SMM_API int32_t scripting_Player_GetRetakesOffering(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0;

    return pPawn->m_iRetakesOffering;
}

SMM_API void scripting_Player_SetRetakesOffering(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_iRetakesOffering = val;
}

SMM_API int32_t scripting_Player_GetRetakesOfferingCard(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0;

    return pPawn->m_iRetakesOfferingCard;
}

SMM_API void scripting_Player_SetRetakesOfferingCard(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_iRetakesOfferingCard = val;
}

SMM_API bool scripting_Player_GetRetakesHasDefuseKit(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bRetakesHasDefuseKit;
}

SMM_API void scripting_Player_SetRetakesHasDefuseKit(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bRetakesHasDefuseKit = val;
}

SMM_API bool scripting_Player_GetRetakesMVPLastRound(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bRetakesMVPLastRound;
}

SMM_API void scripting_Player_SetRetakesMVPLastRound(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bRetakesMVPLastRound = val;
}

SMM_API int32_t scripting_Player_GetRetakesMVPBoostItem(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0;

    return pPawn->m_iRetakesMVPBoostItem;
}

SMM_API void scripting_Player_SetRetakesMVPBoostItem(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_iRetakesMVPBoostItem = val;
}

SMM_API float scripting_Player_GetLandseconds(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0.0f;

    return pPawn->m_flLandseconds;
}

SMM_API void scripting_Player_SetLandseconds(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_flLandseconds = val;
}

SMM_API int32_t scripting_Player_GetAimPunchTickBase(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0;

    return pPawn->m_aimPunchTickBase;
}

SMM_API void scripting_Player_SetAimPunchTickBase(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_aimPunchTickBase = val;
}

SMM_API float scripting_Player_GetAimPunchTickFraction(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0.0f;

    return pPawn->m_aimPunchTickFraction;
}

SMM_API void scripting_Player_SetAimPunchTickFraction(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_aimPunchTickFraction = val;
}

SMM_API bool scripting_Player_GetIsBuyMenuOpen(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bIsBuyMenuOpen;
}

SMM_API void scripting_Player_SetIsBuyMenuOpen(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bIsBuyMenuOpen = val;
}

SMM_API bool scripting_Player_GetLastHeadBoneTransformIsValid(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bLastHeadBoneTransformIsValid;
}

SMM_API void scripting_Player_SetLastHeadBoneTransformIsValid(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bLastHeadBoneTransformIsValid = val;
}

SMM_API float scripting_Player_GetLastLandTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0.0f;

    return pPawn->m_lastLandTime;
}

SMM_API void scripting_Player_SetLastLandTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_lastLandTime = val;
}

SMM_API bool scripting_Player_GetOnGroundLastTick(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bOnGroundLastTick;
}

SMM_API void scripting_Player_SetOnGroundLastTick(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bOnGroundLastTick = val;
}

SMM_API int32_t scripting_Player_GetPlayerLocked(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0;

    return pPawn->m_iPlayerLocked;
}

SMM_API void scripting_Player_SetPlayerLocked(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_iPlayerLocked = val;
}

SMM_API float scripting_Player_GetTimeOfLastInjury(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0.0f;

    return pPawn->m_flTimeOfLastInjury;
}

SMM_API void scripting_Player_SetTimeOfLastInjury(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_flTimeOfLastInjury = val;
}

SMM_API float scripting_Player_GetNextSprayDecalTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0.0f;

    return pPawn->m_flNextSprayDecalTime;
}

SMM_API void scripting_Player_SetNextSprayDecalTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_flNextSprayDecalTime = val;
}

SMM_API bool scripting_Player_GetNextSprayDecalTimeExpedited(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bNextSprayDecalTimeExpedited;
}

SMM_API void scripting_Player_SetNextSprayDecalTimeExpedited(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bNextSprayDecalTimeExpedited = val;
}

SMM_API int32_t scripting_Player_GetRagdollDamageBone(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0;

    return pPawn->m_nRagdollDamageBone;
}

SMM_API void scripting_Player_SetRagdollDamageBone(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_nRagdollDamageBone = val;
}

SMM_API bool scripting_Player_GetRagdollDamageHeadshot(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bRagdollDamageHeadshot;
}

SMM_API void scripting_Player_SetRagdollDamageHeadshot(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bRagdollDamageHeadshot = val;
}

SMM_API uint8_t scripting_Player_GetEconGlovesChanged(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return 0;

    return pPawn->m_nEconGlovesChanged;
}

SMM_API void scripting_Player_SetEconGlovesChanged(uint32 playerId, uint8_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_nEconGlovesChanged = val;
}

SMM_API bool scripting_Player_GetSkipOneHeadConstraintUpdate(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return false;

    return pPawn->m_bSkipOneHeadConstraintUpdate;
}

SMM_API void scripting_Player_SetSkipOneHeadConstraintUpdate(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawn *pPawn = player->GetPlayerPawn();
    if (!pPawn)
        return;

    pPawn->m_bSkipOneHeadConstraintUpdate = val;
}

SMM_API bool scripting_Player_GetHasCommunicationAbuseMute(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bHasCommunicationAbuseMute;
}

SMM_API void scripting_Player_SetHasCommunicationAbuseMute(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bHasCommunicationAbuseMute = val;
}

SMM_API uint8_t scripting_Player_GetPendingTeamNum(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iPendingTeamNum;
}

SMM_API void scripting_Player_SetPendingTeamNum(uint32 playerId, uint8_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iPendingTeamNum = val;
}

SMM_API float scripting_Player_GetForceTeamTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0.0f;

    return pController->m_flForceTeamTime;
}

SMM_API void scripting_Player_SetForceTeamTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_flForceTeamTime = val;
}

SMM_API int32_t scripting_Player_GetCompTeammateColor(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iCompTeammateColor;
}

SMM_API void scripting_Player_SetCompTeammateColor(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iCompTeammateColor = val;
}

SMM_API bool scripting_Player_GetEverPlayedOnTeam(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bEverPlayedOnTeam;
}

SMM_API void scripting_Player_SetEverPlayedOnTeam(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bEverPlayedOnTeam = val;
}

SMM_API bool scripting_Player_GetAttemptedToGetColor(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bAttemptedToGetColor;
}

SMM_API void scripting_Player_SetAttemptedToGetColor(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bAttemptedToGetColor = val;
}

SMM_API int32_t scripting_Player_GetTeammatePreferredColor(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iTeammatePreferredColor;
}

SMM_API void scripting_Player_SetTeammatePreferredColor(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iTeammatePreferredColor = val;
}

SMM_API bool scripting_Player_GetTeamChanged(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bTeamChanged;
}

SMM_API void scripting_Player_SetTeamChanged(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bTeamChanged = val;
}

SMM_API bool scripting_Player_GetInSwitchTeam(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bInSwitchTeam;
}

SMM_API void scripting_Player_SetInSwitchTeam(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bInSwitchTeam = val;
}

SMM_API bool scripting_Player_GetHasSeenJoinGame(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bHasSeenJoinGame;
}

SMM_API void scripting_Player_SetHasSeenJoinGame(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bHasSeenJoinGame = val;
}

SMM_API bool scripting_Player_GetJustBecameSpectator(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bJustBecameSpectator;
}

SMM_API void scripting_Player_SetJustBecameSpectator(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bJustBecameSpectator = val;
}

SMM_API bool scripting_Player_GetSwitchTeamsOnNextRoundReset(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bSwitchTeamsOnNextRoundReset;
}

SMM_API void scripting_Player_SetSwitchTeamsOnNextRoundReset(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bSwitchTeamsOnNextRoundReset = val;
}

SMM_API bool scripting_Player_GetRemoveAllItemsOnNextRoundReset(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bRemoveAllItemsOnNextRoundReset;
}

SMM_API void scripting_Player_SetRemoveAllItemsOnNextRoundReset(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bRemoveAllItemsOnNextRoundReset = val;
}

SMM_API int32_t scripting_Player_GetCompetitiveRankingPredicted_Win(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iCompetitiveRankingPredicted_Win;
}

SMM_API void scripting_Player_SetCompetitiveRankingPredicted_Win(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iCompetitiveRankingPredicted_Win = val;
}

SMM_API int32_t scripting_Player_GetCompetitiveRankingPredicted_Loss(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iCompetitiveRankingPredicted_Loss;
}

SMM_API void scripting_Player_SetCompetitiveRankingPredicted_Loss(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iCompetitiveRankingPredicted_Loss = val;
}

SMM_API int32_t scripting_Player_GetCompetitiveRankingPredicted_Tie(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iCompetitiveRankingPredicted_Tie;
}

SMM_API void scripting_Player_SetCompetitiveRankingPredicted_Tie(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iCompetitiveRankingPredicted_Tie = val;
}

SMM_API int32_t scripting_Player_GetEndMatchNextMapVote(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_nEndMatchNextMapVote;
}

SMM_API void scripting_Player_SetEndMatchNextMapVote(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_nEndMatchNextMapVote = val;
}

SMM_API uint16_t scripting_Player_GetActiveQuestId(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_unActiveQuestId;
}

SMM_API void scripting_Player_SetActiveQuestId(uint32 playerId, uint16_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_unActiveQuestId = val;
}

SMM_API uint32_t scripting_Player_GetPlayerTvControlFlags(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_unPlayerTvControlFlags;
}

SMM_API void scripting_Player_SetPlayerTvControlFlags(uint32 playerId, uint32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_unPlayerTvControlFlags = val;
}

SMM_API int32_t scripting_Player_GetDraftIndex(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iDraftIndex;
}

SMM_API void scripting_Player_SetDraftIndex(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iDraftIndex = val;
}

SMM_API uint32_t scripting_Player_GetQueuedModeDisconnectionTimestamp(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_msQueuedModeDisconnectionTimestamp;
}

SMM_API void scripting_Player_SetQueuedModeDisconnectionTimestamp(uint32 playerId, uint32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_msQueuedModeDisconnectionTimestamp = val;
}

SMM_API uint32_t scripting_Player_GetAbandonRecordedReason(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_uiAbandonRecordedReason;
}

SMM_API void scripting_Player_SetAbandonRecordedReason(uint32 playerId, uint32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_uiAbandonRecordedReason = val;
}

SMM_API bool scripting_Player_GetCannotBeKicked(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bCannotBeKicked;
}

SMM_API void scripting_Player_SetCannotBeKicked(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bCannotBeKicked = val;
}

SMM_API bool scripting_Player_GetEverFullyConnected(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bEverFullyConnected;
}

SMM_API void scripting_Player_SetEverFullyConnected(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bEverFullyConnected = val;
}

SMM_API bool scripting_Player_GetAbandonAllowsSurrender(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bAbandonAllowsSurrender;
}

SMM_API void scripting_Player_SetAbandonAllowsSurrender(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bAbandonAllowsSurrender = val;
}

SMM_API bool scripting_Player_GetAbandonOffersInstantSurrender(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bAbandonOffersInstantSurrender;
}

SMM_API void scripting_Player_SetAbandonOffersInstantSurrender(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bAbandonOffersInstantSurrender = val;
}

SMM_API bool scripting_Player_GetDisconnection1MinWarningPrinted(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bDisconnection1MinWarningPrinted;
}

SMM_API void scripting_Player_SetDisconnection1MinWarningPrinted(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bDisconnection1MinWarningPrinted = val;
}

SMM_API bool scripting_Player_GetScoreReported(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bScoreReported;
}

SMM_API void scripting_Player_SetScoreReported(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bScoreReported = val;
}

SMM_API int32_t scripting_Player_GetDisconnectionTick(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_nDisconnectionTick;
}

SMM_API void scripting_Player_SetDisconnectionTick(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_nDisconnectionTick = val;
}

SMM_API bool scripting_Player_GetControllingBot(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bControllingBot;
}

SMM_API void scripting_Player_SetControllingBot(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bControllingBot = val;
}

SMM_API bool scripting_Player_GetHasControlledBotThisRound(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bHasControlledBotThisRound;
}

SMM_API void scripting_Player_SetHasControlledBotThisRound(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bHasControlledBotThisRound = val;
}

SMM_API bool scripting_Player_GetHasBeenControlledByPlayerThisRound(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bHasBeenControlledByPlayerThisRound;
}

SMM_API void scripting_Player_SetHasBeenControlledByPlayerThisRound(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bHasBeenControlledByPlayerThisRound = val;
}

SMM_API int32_t scripting_Player_GetBotsControlledThisRound(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_nBotsControlledThisRound;
}

SMM_API void scripting_Player_SetBotsControlledThisRound(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_nBotsControlledThisRound = val;
}

SMM_API bool scripting_Player_GetCanControlObservedBot(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bCanControlObservedBot;
}

SMM_API void scripting_Player_SetCanControlObservedBot(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bCanControlObservedBot = val;
}

SMM_API int32_t scripting_Player_GetDesiredObserverMode(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_DesiredObserverMode;
}

SMM_API void scripting_Player_SetDesiredObserverMode(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_DesiredObserverMode = val;
}

SMM_API uint16_t scripting_Player_GetPawnCharacterDefIndex(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_nPawnCharacterDefIndex;
}

SMM_API void scripting_Player_SetPawnCharacterDefIndex(uint32 playerId, uint16_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_nPawnCharacterDefIndex = val;
}

SMM_API int32_t scripting_Player_GetPawnLifetimeStart(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iPawnLifetimeStart;
}

SMM_API void scripting_Player_SetPawnLifetimeStart(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iPawnLifetimeStart = val;
}

SMM_API int32_t scripting_Player_GetPawnLifetimeEnd(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iPawnLifetimeEnd;
}

SMM_API void scripting_Player_SetPawnLifetimeEnd(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iPawnLifetimeEnd = val;
}

SMM_API int32_t scripting_Player_GetPawnBotDifficulty(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iPawnBotDifficulty;
}

SMM_API void scripting_Player_SetPawnBotDifficulty(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iPawnBotDifficulty = val;
}

SMM_API int32_t scripting_Player_GetScore(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iScore;
}

SMM_API void scripting_Player_SetScore(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iScore = val;
}

SMM_API int32_t scripting_Player_GetRoundScore(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iRoundScore;
}

SMM_API void scripting_Player_SetRoundScore(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iRoundScore = val;
}

SMM_API int32_t scripting_Player_GetRoundsWon(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iRoundsWon;
}

SMM_API void scripting_Player_SetRoundsWon(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iRoundsWon = val;
}

SMM_API int32_t scripting_Player_GetMVPs(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iMVPs;
}

SMM_API void scripting_Player_SetMVPs(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iMVPs = val;
}

SMM_API int32_t scripting_Player_GetUpdateCounter(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_nUpdateCounter;
}

SMM_API void scripting_Player_SetUpdateCounter(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_nUpdateCounter = val;
}

SMM_API bool scripting_Player_GetShowHints(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bShowHints;
}

SMM_API void scripting_Player_SetShowHints(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bShowHints = val;
}

SMM_API int32_t scripting_Player_GetNextTimeCheck(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_iNextTimeCheck;
}

SMM_API void scripting_Player_SetNextTimeCheck(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_iNextTimeCheck = val;
}

SMM_API bool scripting_Player_GetJustDidTeamKill(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bJustDidTeamKill;
}

SMM_API void scripting_Player_SetJustDidTeamKill(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bJustDidTeamKill = val;
}

SMM_API bool scripting_Player_GetPunishForTeamKill(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bPunishForTeamKill;
}

SMM_API void scripting_Player_SetPunishForTeamKill(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bPunishForTeamKill = val;
}

SMM_API bool scripting_Player_GetGaveTeamDamageWarning(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bGaveTeamDamageWarning;
}

SMM_API void scripting_Player_SetGaveTeamDamageWarning(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bGaveTeamDamageWarning = val;
}

SMM_API bool scripting_Player_GetGaveTeamDamageWarningThisRound(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return false;

    return pController->m_bGaveTeamDamageWarningThisRound;
}

SMM_API void scripting_Player_SetGaveTeamDamageWarningThisRound(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_bGaveTeamDamageWarningThisRound = val;
}

SMM_API double scripting_Player_GetLastReceivedPacketPlatFloatTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0.0f;

    return pController->m_dblLastReceivedPacketPlatFloatTime;
}

SMM_API void scripting_Player_SetLastReceivedPacketPlatFloatTime(uint32 playerId, double val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_dblLastReceivedPacketPlatFloatTime = val;
}

SMM_API float scripting_Player_GetLastTeamDamageWarningTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0.0f;

    return pController->m_LastTeamDamageWarningTime;
}

SMM_API void scripting_Player_SetLastTeamDamageWarningTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_LastTeamDamageWarningTime = val;
}

SMM_API float scripting_Player_GetLastTimePlayerWasDisconnectedForPawnsRemove(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0.0f;

    return pController->m_LastTimePlayerWasDisconnectedForPawnsRemove;
}

SMM_API void scripting_Player_SetLastTimePlayerWasDisconnectedForPawnsRemove(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_LastTimePlayerWasDisconnectedForPawnsRemove = val;
}

SMM_API uint32_t scripting_Player_GetSuspiciousHitCount(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_nSuspiciousHitCount;
}

SMM_API void scripting_Player_SetSuspiciousHitCount(uint32 playerId, uint32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_nSuspiciousHitCount = val;
}

SMM_API uint32_t scripting_Player_GetNonSuspiciousHitStreak(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return 0;

    return pController->m_nNonSuspiciousHitStreak;
}

SMM_API void scripting_Player_SetNonSuspiciousHitStreak(uint32 playerId, uint32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerController *pController = player->GetPlayerController();
    if (!pController)
        return;

    pController->m_nNonSuspiciousHitStreak = val;
}

SMM_API uint32_t scripting_Player_GetDisplayHistoryBits(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iDisplayHistoryBits;
}

SMM_API void scripting_Player_SetDisplayHistoryBits(uint32 playerId, uint32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iDisplayHistoryBits = val;
}

SMM_API float scripting_Player_GetLastAttackedTeammate(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastAttackedTeammate;
}

SMM_API void scripting_Player_SetLastAttackedTeammate(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastAttackedTeammate = val;
}

SMM_API float scripting_Player_GetBlindUntilTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_blindUntilTime;
}

SMM_API void scripting_Player_SetBlindUntilTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_blindUntilTime = val;
}

SMM_API float scripting_Player_GetBlindStartTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_blindStartTime;
}

SMM_API void scripting_Player_SetBlindStartTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_blindStartTime = val;
}

SMM_API float scripting_Player_GetallowAutoFollowTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_allowAutoFollowTime;
}

SMM_API void scripting_Player_SetallowAutoFollowTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_allowAutoFollowTime = val;
}

SMM_API int32_t scripting_Player_GetSpotRules(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_nSpotRules;
}

SMM_API void scripting_Player_SetSpotRules(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_nSpotRules = val;
}

SMM_API CSPlayerState scripting_Player_GetPlayerState(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return CSPlayerState::STATE_ACTIVE;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return CSPlayerState::STATE_ACTIVE;

    return pPawnBase->m_iPlayerState;
}

SMM_API void scripting_Player_SetPlayerState(uint32 playerId, CSPlayerState val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iPlayerState = val;
}

SMM_API float scripting_Player_GetLastDistanceTraveledNotice(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastDistanceTraveledNotice;
}

SMM_API void scripting_Player_SetLastDistanceTraveledNotice(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastDistanceTraveledNotice = val;
}

SMM_API float scripting_Player_GetAccumulatedDistanceTraveled(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flAccumulatedDistanceTraveled;
}

SMM_API void scripting_Player_SetAccumulatedDistanceTraveled(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flAccumulatedDistanceTraveled = val;
}

SMM_API float scripting_Player_GetLastFriendlyFireDamageReductionRatio(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastFriendlyFireDamageReductionRatio;
}

SMM_API void scripting_Player_SetLastFriendlyFireDamageReductionRatio(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastFriendlyFireDamageReductionRatio = val;
}

SMM_API bool scripting_Player_GetRespawning(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bRespawning;
}

SMM_API void scripting_Player_SetRespawning(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bRespawning = val;
}

SMM_API int32_t scripting_Player_GetLastPickupPriority(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_nLastPickupPriority;
}

SMM_API void scripting_Player_SetLastPickupPriority(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_nLastPickupPriority = val;
}

SMM_API float scripting_Player_GetLastPickupPriorityTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastPickupPriorityTime;
}

SMM_API void scripting_Player_SetLastPickupPriorityTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastPickupPriorityTime = val;
}

SMM_API bool scripting_Player_GetIsScoped(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bIsScoped;
}

SMM_API void scripting_Player_SetIsScoped(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bIsScoped = val;
}

SMM_API bool scripting_Player_GetIsWalking(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bIsWalking;
}

SMM_API void scripting_Player_SetIsWalking(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bIsWalking = val;
}

SMM_API bool scripting_Player_GetResumeZoom(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bResumeZoom;
}

SMM_API void scripting_Player_SetResumeZoom(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bResumeZoom = val;
}

SMM_API bool scripting_Player_GetIsDefusing(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bIsDefusing;
}

SMM_API void scripting_Player_SetIsDefusing(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bIsDefusing = val;
}

SMM_API bool scripting_Player_GetIsGrabbingHostage(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bIsGrabbingHostage;
}

SMM_API void scripting_Player_SetIsGrabbingHostage(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bIsGrabbingHostage = val;
}

SMM_API CSPlayerBlockingUseAction_t scripting_Player_GetBlockingUseActionInProgress(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return CSPlayerBlockingUseAction_t::k_CSPlayerBlockingUseAction_None;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return CSPlayerBlockingUseAction_t::k_CSPlayerBlockingUseAction_None;

    return pPawnBase->m_iBlockingUseActionInProgress;
}

SMM_API void scripting_Player_SetBlockingUseActionInProgress(uint32 playerId, CSPlayerBlockingUseAction_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iBlockingUseActionInProgress = val;
}

SMM_API float scripting_Player_GetImmuneToGunGameDamageTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_fImmuneToGunGameDamageTime;
}

SMM_API void scripting_Player_SetImmuneToGunGameDamageTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_fImmuneToGunGameDamageTime = val;
}

SMM_API bool scripting_Player_GetGunGameImmunity(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bGunGameImmunity;
}

SMM_API void scripting_Player_SetGunGameImmunity(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bGunGameImmunity = val;
}

SMM_API float scripting_Player_GetMolotovDamageTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_fMolotovDamageTime;
}

SMM_API void scripting_Player_SetMolotovDamageTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_fMolotovDamageTime = val;
}

SMM_API bool scripting_Player_GetHasMovedSinceSpawn(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bHasMovedSinceSpawn;
}

SMM_API void scripting_Player_SetHasMovedSinceSpawn(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bHasMovedSinceSpawn = val;
}

SMM_API bool scripting_Player_GetCanMoveDuringFreezePeriod(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bCanMoveDuringFreezePeriod;
}

SMM_API void scripting_Player_SetCanMoveDuringFreezePeriod(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bCanMoveDuringFreezePeriod = val;
}

SMM_API float scripting_Player_GetGuardianTooFarDistFrac(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flGuardianTooFarDistFrac;
}

SMM_API void scripting_Player_SetGuardianTooFarDistFrac(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flGuardianTooFarDistFrac = val;
}

SMM_API float scripting_Player_GetNextGuardianTooFarHurtTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flNextGuardianTooFarHurtTime;
}

SMM_API void scripting_Player_SetNextGuardianTooFarHurtTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flNextGuardianTooFarHurtTime = val;
}

SMM_API float scripting_Player_GetDetectedByEnemySensorTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flDetectedByEnemySensorTime;
}

SMM_API void scripting_Player_SetDetectedByEnemySensorTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flDetectedByEnemySensorTime = val;
}

SMM_API float scripting_Player_GetDealtDamageToEnemyMostRecentTimestamp(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flDealtDamageToEnemyMostRecentTimestamp;
}

SMM_API void scripting_Player_SetDealtDamageToEnemyMostRecentTimestamp(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flDealtDamageToEnemyMostRecentTimestamp = val;
}

SMM_API float scripting_Player_GetLastEquippedHelmetTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastEquippedHelmetTime;
}

SMM_API void scripting_Player_SetLastEquippedHelmetTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastEquippedHelmetTime = val;
}

SMM_API float scripting_Player_GetLastEquippedArmorTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastEquippedArmorTime;
}

SMM_API void scripting_Player_SetLastEquippedArmorTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastEquippedArmorTime = val;
}

SMM_API int32_t scripting_Player_GetHeavyAssaultSuitCooldownRemaining(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_nHeavyAssaultSuitCooldownRemaining;
}

SMM_API void scripting_Player_SetHeavyAssaultSuitCooldownRemaining(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_nHeavyAssaultSuitCooldownRemaining = val;
}

SMM_API bool scripting_Player_GetResetArmorNextSpawn(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bResetArmorNextSpawn;
}

SMM_API void scripting_Player_SetResetArmorNextSpawn(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bResetArmorNextSpawn = val;
}

SMM_API float scripting_Player_GetLastBumpMineBumpTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastBumpMineBumpTime;
}

SMM_API void scripting_Player_SetLastBumpMineBumpTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastBumpMineBumpTime = val;
}

SMM_API float scripting_Player_GetEmitSoundTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flEmitSoundTime;
}

SMM_API void scripting_Player_SetEmitSoundTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flEmitSoundTime = val;
}

SMM_API int32_t scripting_Player_GetNumSpawns(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iNumSpawns;
}

SMM_API void scripting_Player_SetNumSpawns(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iNumSpawns = val;
}

SMM_API int32_t scripting_Player_GetShouldHaveCash(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iShouldHaveCash;
}

SMM_API void scripting_Player_SetShouldHaveCash(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iShouldHaveCash = val;
}

SMM_API bool scripting_Player_GetInvalidSteamLogonDelayed(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bInvalidSteamLogonDelayed;
}

SMM_API void scripting_Player_SetInvalidSteamLogonDelayed(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bInvalidSteamLogonDelayed = val;
}

SMM_API float scripting_Player_GetLastAction(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastAction;
}

SMM_API void scripting_Player_SetLastAction(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastAction = val;
}

SMM_API float scripting_Player_GetLastGivenDefuserTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_fLastGivenDefuserTime;
}

SMM_API void scripting_Player_SetLastGivenDefuserTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_fLastGivenDefuserTime = val;
}

SMM_API float scripting_Player_GetLastGivenBombTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_fLastGivenBombTime;
}

SMM_API void scripting_Player_SetLastGivenBombTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_fLastGivenBombTime = val;
}

SMM_API bool scripting_Player_GetHasNightVision(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bHasNightVision;
}

SMM_API void scripting_Player_SetHasNightVision(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bHasNightVision = val;
}

SMM_API bool scripting_Player_GetNightVisionOn(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bNightVisionOn;
}

SMM_API void scripting_Player_SetNightVisionOn(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bNightVisionOn = val;
}

SMM_API float scripting_Player_GetNextRadarUpdateTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_fNextRadarUpdateTime;
}

SMM_API void scripting_Player_SetNextRadarUpdateTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_fNextRadarUpdateTime = val;
}

SMM_API float scripting_Player_GetLastMoneyUpdateTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastMoneyUpdateTime;
}

SMM_API void scripting_Player_SetLastMoneyUpdateTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastMoneyUpdateTime = val;
}

SMM_API float scripting_Player_GetIntroCamTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_fIntroCamTime;
}

SMM_API void scripting_Player_SetIntroCamTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_fIntroCamTime = val;
}

SMM_API bool scripting_Player_GetInNoDefuseArea(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bInNoDefuseArea;
}

SMM_API void scripting_Player_SetInNoDefuseArea(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bInNoDefuseArea = val;
}

SMM_API bool scripting_Player_GetKilledByTaser(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bKilledByTaser;
}

SMM_API void scripting_Player_SetKilledByTaser(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bKilledByTaser = val;
}

SMM_API int32_t scripting_Player_GetMoveState(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iMoveState;
}

SMM_API void scripting_Player_SetMoveState(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iMoveState = val;
}

SMM_API float scripting_Player_GetGrenadeParameterStashTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_grenadeParameterStashTime;
}

SMM_API void scripting_Player_SetGrenadeParameterStashTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_grenadeParameterStashTime = val;
}

SMM_API bool scripting_Player_GetGrenadeParametersStashed(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bGrenadeParametersStashed;
}

SMM_API void scripting_Player_SetGrenadeParametersStashed(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bGrenadeParametersStashed = val;
}

SMM_API bool scripting_Player_GetDiedAirborne(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bDiedAirborne;
}

SMM_API void scripting_Player_SetDiedAirborne(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bDiedAirborne = val;
}

SMM_API int32_t scripting_Player_GetWhichBombZone(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_nWhichBombZone;
}

SMM_API void scripting_Player_SetWhichBombZone(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_nWhichBombZone = val;
}

SMM_API bool scripting_Player_GetInBombZoneTrigger(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bInBombZoneTrigger;
}

SMM_API void scripting_Player_SetInBombZoneTrigger(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bInBombZoneTrigger = val;
}

SMM_API bool scripting_Player_GetWasInBombZoneTrigger(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bWasInBombZoneTrigger;
}

SMM_API void scripting_Player_SetWasInBombZoneTrigger(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bWasInBombZoneTrigger = val;
}

SMM_API int32_t scripting_Player_GetDirection(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iDirection;
}

SMM_API void scripting_Player_SetDirection(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iDirection = val;
}

SMM_API int32_t scripting_Player_GetShotsFired(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iShotsFired;
}

SMM_API void scripting_Player_SetShotsFired(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iShotsFired = val;
}

SMM_API float scripting_Player_GetFlinchStack(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flFlinchStack;
}

SMM_API void scripting_Player_SetFlinchStack(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flFlinchStack = val;
}

SMM_API float scripting_Player_GetHitHeading(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flHitHeading;
}

SMM_API void scripting_Player_SetHitHeading(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flHitHeading = val;
}

SMM_API int32_t scripting_Player_GetHitBodyPart(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_nHitBodyPart;
}

SMM_API void scripting_Player_SetHitBodyPart(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_nHitBodyPart = val;
}

SMM_API int32_t scripting_Player_GetHostagesKilled(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iHostagesKilled;
}

SMM_API void scripting_Player_SetHostagesKilled(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iHostagesKilled = val;
}

SMM_API float scripting_Player_GetFlashMaxAlpha(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flFlashMaxAlpha;
}

SMM_API void scripting_Player_SetFlashMaxAlpha(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flFlashMaxAlpha = val;
}

SMM_API float scripting_Player_GetProgressBarStartTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flProgressBarStartTime;
}

SMM_API void scripting_Player_SetProgressBarStartTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flProgressBarStartTime = val;
}

SMM_API int32_t scripting_Player_GetProgressBarDuration(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iProgressBarDuration;
}

SMM_API void scripting_Player_SetProgressBarDuration(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iProgressBarDuration = val;
}

SMM_API bool scripting_Player_GetWaitForNoAttack(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bWaitForNoAttack;
}

SMM_API void scripting_Player_SetWaitForNoAttack(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bWaitForNoAttack = val;
}

SMM_API float scripting_Player_GetLowerBodyYawTarget(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLowerBodyYawTarget;
}

SMM_API void scripting_Player_SetLowerBodyYawTarget(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLowerBodyYawTarget = val;
}

SMM_API bool scripting_Player_GetStrafing(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bStrafing;
}

SMM_API void scripting_Player_SetStrafing(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bStrafing = val;
}

SMM_API float scripting_Player_GetIgnoreLadderJumpTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_ignoreLadderJumpTime;
}

SMM_API void scripting_Player_SetIgnoreLadderJumpTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_ignoreLadderJumpTime = val;
}

SMM_API float scripting_Player_GetSlopeDropOffset(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flSlopeDropOffset;
}

SMM_API void scripting_Player_SetSlopeDropOffset(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flSlopeDropOffset = val;
}

SMM_API float scripting_Player_GetSlopeDropHeight(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flSlopeDropHeight;
}

SMM_API void scripting_Player_SetSlopeDropHeight(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flSlopeDropHeight = val;
}

SMM_API int32_t scripting_Player_GetLastWeaponFireUsercmd(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iLastWeaponFireUsercmd;
}

SMM_API void scripting_Player_SetLastWeaponFireUsercmd(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iLastWeaponFireUsercmd = val;
}

SMM_API bool scripting_Player_GetVCollisionInitted(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bVCollisionInitted;
}

SMM_API void scripting_Player_SetVCollisionInitted(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bVCollisionInitted = val;
}

SMM_API bool scripting_Player_GetIsSpawning(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bIsSpawning;
}

SMM_API void scripting_Player_SetIsSpawning(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bIsSpawning = val;
}

SMM_API bool scripting_Player_GetHideTargetID(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bHideTargetID;
}

SMM_API void scripting_Player_SetHideTargetID(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bHideTargetID = val;
}

SMM_API int32_t scripting_Player_GetNumDangerZoneDamageHits(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_nNumDangerZoneDamageHits;
}

SMM_API void scripting_Player_SetNumDangerZoneDamageHits(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_nNumDangerZoneDamageHits = val;
}

SMM_API bool scripting_Player_GetHud_MiniScoreHidden(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bHud_MiniScoreHidden;
}

SMM_API void scripting_Player_SetHud_MiniScoreHidden(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bHud_MiniScoreHidden = val;
}

SMM_API bool scripting_Player_GetHud_RadarHidden(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bHud_RadarHidden;
}

SMM_API void scripting_Player_SetHud_RadarHidden(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bHud_RadarHidden = val;
}

SMM_API int32_t scripting_Player_GetLastConcurrentKilled(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_nLastConcurrentKilled;
}

SMM_API void scripting_Player_SetLastConcurrentKilled(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_nLastConcurrentKilled = val;
}

SMM_API int32_t scripting_Player_GetDeathCamMusic(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_nDeathCamMusic;
}

SMM_API void scripting_Player_SetDeathCamMusic(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_nDeathCamMusic = val;
}

SMM_API int32_t scripting_Player_GetAddonBits(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iAddonBits;
}

SMM_API void scripting_Player_SetAddonBits(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iAddonBits = val;
}

SMM_API int32_t scripting_Player_GetPrimaryAddon(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iPrimaryAddon;
}

SMM_API void scripting_Player_SetPrimaryAddon(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iPrimaryAddon = val;
}

SMM_API int32_t scripting_Player_GetSecondaryAddon(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iSecondaryAddon;
}

SMM_API void scripting_Player_SetSecondaryAddon(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iSecondaryAddon = val;
}

SMM_API int32_t scripting_Player_GetNumEnemiesKilledThisSpawn(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_NumEnemiesKilledThisSpawn;
}

SMM_API void scripting_Player_SetNumEnemiesKilledThisSpawn(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_NumEnemiesKilledThisSpawn = val;
}

SMM_API int32_t scripting_Player_GetNumEnemiesKilledThisRound(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_NumEnemiesKilledThisRound;
}

SMM_API void scripting_Player_SetNumEnemiesKilledThisRound(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_NumEnemiesKilledThisRound = val;
}

SMM_API int32_t scripting_Player_GetNumEnemiesAtRoundStart(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_NumEnemiesAtRoundStart;
}

SMM_API void scripting_Player_SetNumEnemiesAtRoundStart(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_NumEnemiesAtRoundStart = val;
}

SMM_API bool scripting_Player_GetWasNotKilledNaturally(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_wasNotKilledNaturally;
}

SMM_API void scripting_Player_SetWasNotKilledNaturally(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_wasNotKilledNaturally = val;
}

SMM_API int32_t scripting_Player_GetDeathFlags(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_iDeathFlags;
}

SMM_API void scripting_Player_SetDeathFlags(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_iDeathFlags = val;
}

SMM_API uint16_t scripting_Player_GetCurrentEquipmentValue(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_unCurrentEquipmentValue;
}

SMM_API void scripting_Player_SetCurrentEquipmentValue(uint32 playerId, uint16_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_unCurrentEquipmentValue = val;
}

SMM_API uint16_t scripting_Player_GetRoundStartEquipmentValue(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_unRoundStartEquipmentValue;
}

SMM_API void scripting_Player_SetRoundStartEquipmentValue(uint32 playerId, uint16_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_unRoundStartEquipmentValue = val;
}

SMM_API uint16_t scripting_Player_GetFreezetimeEndEquipmentValue(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_unFreezetimeEndEquipmentValue;
}

SMM_API void scripting_Player_SetFreezetimeEndEquipmentValue(uint32 playerId, uint16_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_unFreezetimeEndEquipmentValue = val;
}

SMM_API int32_t scripting_Player_GetSurvivalTeamNumber(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_nSurvivalTeamNumber;
}

SMM_API void scripting_Player_SetSurvivalTeamNumber(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_nSurvivalTeamNumber = val;
}

SMM_API bool scripting_Player_GetHasDeathInfo(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bHasDeathInfo;
}

SMM_API void scripting_Player_SetHasDeathInfo(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bHasDeathInfo = val;
}

SMM_API float scripting_Player_GetDeathInfoTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flDeathInfoTime;
}

SMM_API void scripting_Player_SetDeathInfoTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flDeathInfoTime = val;
}

SMM_API bool scripting_Player_GetKilledByHeadshot(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bKilledByHeadshot;
}

SMM_API void scripting_Player_SetKilledByHeadshot(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bKilledByHeadshot = val;
}

SMM_API int32_t scripting_Player_GetLastHitBox(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_LastHitBox;
}

SMM_API void scripting_Player_SetLastHitBox(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_LastHitBox = val;
}

SMM_API int32_t scripting_Player_GetLastHealth(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0;

    return pPawnBase->m_LastHealth;
}

SMM_API void scripting_Player_SetLastHealth(uint32 playerId, int32_t val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_LastHealth = val;
}

SMM_API float scripting_Player_GetLastCollisionCeiling(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastCollisionCeiling;
}

SMM_API void scripting_Player_SetLastCollisionCeiling(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastCollisionCeiling = val;
}

SMM_API float scripting_Player_GetLastCollisionCeilingChangeTime(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return 0.0f;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return 0.0f;

    return pPawnBase->m_flLastCollisionCeilingChangeTime;
}

SMM_API void scripting_Player_SetLastCollisionCeilingChangeTime(uint32 playerId, float val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_flLastCollisionCeilingChangeTime = val;
}

SMM_API bool scripting_Player_GetBotAllowActive(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bBotAllowActive;
}

SMM_API void scripting_Player_SetBotAllowActive(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bBotAllowActive = val;
}

SMM_API bool scripting_Player_GetCommittingSuicideOnTeamChange(uint32 playerId)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return false;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return false;

    return pPawnBase->m_bCommittingSuicideOnTeamChange;
}

SMM_API void scripting_Player_SetCommittingSuicideOnTeamChange(uint32 playerId, bool val)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CCSPlayerPawnBase *pPawnBase = player->GetPlayerBasePawn();
    if (!pPawnBase)
        return;

    pPawnBase->m_bCommittingSuicideOnTeamChange = val;
}