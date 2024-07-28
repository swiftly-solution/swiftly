#include "../scripting.h"
#include "../../../player/PlayerManager.h"
#include "generated/classes.h"

PluginWeaponManager::PluginWeaponManager(int playerId)
{
    this->m_playerId = playerId;
}

void PluginWeaponManager::GiveWeapon(std::string weapon_name)
{
    Player *player = g_playerManager->GetPlayer(m_playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CCSPlayer_ItemServices *itemServices = pawn->m_pItemServices();
    if (!itemServices)
        return;

    pawn->GiveNamedItem(weapon_name.c_str());
}
void PluginWeaponManager::RemoveWeapons()
{
    Player *player = g_playerManager->GetPlayer(m_playerId);
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
void PluginWeaponManager::DropWeapons()
{
    Player *player = g_playerManager->GetPlayer(m_playerId);
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

std::vector<PluginWeapon> PluginWeaponManager::GetWeapons()
{
    std::vector<PluginWeapon> vec;

    Player *player = g_playerManager->GetPlayer(m_playerId);
    if (!player)
        return vec;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return vec;

    CPlayer_WeaponServices *weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return vec;

    CUtlVector<CHandle<CBasePlayerWeapon>> *weapons = weaponServices->m_hMyWeapons();
    if (!weapons)
        return vec;

    FOR_EACH_VEC(*weapons, i)
    {
        CHandle<CBasePlayerWeapon> &weaponHandle = (*weapons)[i];
        if (!weaponHandle.IsValid())
            continue;

        CBasePlayerWeapon *weapon = weaponHandle.Get();
        if (!weapon)
            continue;

        vec.push_back(PluginWeapon(this->m_playerId, weapon));
    }

    return vec;
}

PluginWeapon::PluginWeapon(int playerId, CBasePlayerWeapon *ptr)
{
    this->m_playerId = playerId;
    this->m_ptr = ptr;
}

GCBasePlayerWeapon PluginWeapon::GetCBasePlayerWeapon()
{
    return GCBasePlayerWeapon(this->m_ptr);
}

GCCSWeaponBase PluginWeapon::GetCCSWeaponBase()
{
    return GCCSWeaponBase(this->m_ptr);
}
GCBasePlayerWeaponVData PluginWeapon::GetCBasePlayerWeaponVData()
{
    if (!this->m_ptr)
        return GCBasePlayerWeaponVData(nullptr);

    return GCBasePlayerWeaponVData((void *)(this->m_ptr->GetWeaponVData()));
}
GCCSWeaponBaseVData PluginWeapon::GetCCSWeaponBaseVData()
{
    if (!this->m_ptr)
        return GCCSWeaponBaseVData(nullptr);

    return GCCSWeaponBaseVData((void *)(this->m_ptr->GetWeaponVData()));
}

void PluginWeapon::Drop()
{
    Player *player = g_playerManager->GetPlayer(m_playerId);
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

    if (!this->m_ptr)
        return;

    weaponServices->m_hActiveWeapon = this->m_ptr;
    itemServices->DropPlayerWeapon(this->m_ptr);
}
void PluginWeapon::Remove()
{
    Player *player = g_playerManager->GetPlayer(m_playerId);
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

    if (!this->m_ptr)
        return;

    weaponServices->m_hActiveWeapon = this->m_ptr;
    itemServices->DropPlayerWeapon(this->m_ptr);
    weaponServices->RemoveWeapon(this->m_ptr);
    this->m_ptr->Despawn();
}

std::vector<uint16_t> paintkitsFallbackCheck = {1171, 1170, 1169, 1164, 1162, 1161, 1159, 1175, 1174, 1167, 1165, 1168, 1163, 1160, 1166, 1173};

void PluginWeapon::SetDefaultAttributes()
{
    if (!this->m_ptr)
        return;

    Player *player = g_playerManager->GetPlayer(m_playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    this->m_ptr->m_AttributeManager().m_Item().m_iItemIDHigh = -1;

    if (this->m_ptr->GetWeaponVData()->m_GearSlot == cgear_slot_t::GEAR_SLOT_KNIFE)
    {
        this->m_ptr->m_AttributeManager().m_Item().m_iEntityQuality = 3;
    }

    int paintkit = this->m_ptr->m_nFallbackPaintKit();
    bool legacy = (std::find(paintkitsFallbackCheck.begin(), paintkitsFallbackCheck.end(), paintkit) == paintkitsFallbackCheck.end());

    if (this->m_ptr->m_CBodyComponent() && this->m_ptr->m_CBodyComponent()->m_pSceneNode())
    {
        CSkeletonInstance *skeleton = this->m_ptr->m_CBodyComponent()->m_pSceneNode()->GetSkeletonInstance();
        if (skeleton)
        {
            if (skeleton->m_modelState().m_MeshGroupMask() != (legacy == true ? 2 : 1))
            {
                skeleton->m_modelState().m_MeshGroupMask = (legacy == true ? 2 : 1);
            }
        }
    }

    CCSPlayer_ViewModelServices *viewmodelServices = pawn->m_pViewModelServices();
    if (!viewmodelServices)
        return;

    CHandle<CBaseViewModel> *viewmodelHandles = viewmodelServices->m_hViewModel();
    if (!viewmodelHandles)
        return;
    if (!viewmodelHandles[0])
        return;
    if (!viewmodelHandles[0].IsValid())
        return;

    CBaseViewModel *viewmodel = viewmodelHandles[0].Get();

    if (!viewmodel)
        return;

    if (viewmodel->m_CBodyComponent() && viewmodel->m_CBodyComponent()->m_pSceneNode())
    {
        CSkeletonInstance *viewmodelskeleton = viewmodel->m_CBodyComponent()->m_pSceneNode()->GetSkeletonInstance();
        if (viewmodelskeleton)
        {
            if (viewmodelskeleton->m_modelState().m_MeshGroupMask() != (legacy == true ? 2 : 1))
            {
                viewmodelskeleton->m_modelState().m_MeshGroupMask = (legacy == true ? 2 : 1);
            }
        }
    }

    viewmodel->m_CBodyComponent.StateUpdate();
}