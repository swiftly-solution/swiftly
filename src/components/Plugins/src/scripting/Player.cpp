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

    itemServices->DropPlayerWeapon(weapon);
    weaponServices->RemoveWeapon(weapon);
    weapon->Despawn();
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
        itemServices->m_bHasHeavyArmor = true;
        scripting_Player_SetArmor(playerId, 100);
    }
    else if (n == "item_kevlar")
    {
        itemServices->m_bHasHeavyArmor = true;
        scripting_Player_SetArmor(playerId, 100);
    }
    else
        itemServices->GiveNamedItem(name);
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

SMM_API void scripting_Player_Weapon_SetDefaultChangeSkinAttributes(uint32 playerId, uint32 slot)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    weapon->m_AttributeManager().m_Item().m_iItemIDHigh = -1;

    if (weapon->GetWeaponVData()->m_GearSlot == gear_slot_t::GEAR_SLOT_KNIFE)
        weapon->m_AttributeManager().m_Item().m_iEntityQuality = 3;
    else if (!weapon->m_AttributeManager().m_Item().m_iAccountID() && weapon->m_CBodyComponent() && weapon->m_CBodyComponent()->m_pSceneNode())
        weapon->m_CBodyComponent()->m_pSceneNode()->GetSkeletonInstance()->m_modelState().m_MeshGroupMask = 2;
}

SMM_API void scripting_Player_Weapon_SetNametag(uint32 playerId, uint32 slot, const char *text)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    CBasePlayerWeapon *weapon = player->GetPlayerWeaponFromID(slot);
    if (!weapon)
        return;

    // @todo: SetNametag
}

SMM_API void scripting_Player_ExecuteCommand(uint32 playerId, const char *cmd)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

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