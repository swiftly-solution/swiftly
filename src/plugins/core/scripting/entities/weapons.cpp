#include "../../scripting.h"
#include "../../../../player/playermanager/PlayerManager.h"

PluginWeaponManager::PluginWeaponManager(int playerId)
{
    this->m_playerId = playerId;
}

void PluginWeaponManager::GiveWeapon(std::string weapon_name)
{
    Player* player = g_playerManager->GetPlayer(m_playerId);
    if (!player)
        return;

    CCSPlayerPawn* pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CCSPlayer_ItemServices* itemServices = pawn->m_pItemServices();
    if (!itemServices)
        return;

    pawn->GiveNamedItem(weapon_name.c_str());
}
void PluginWeaponManager::RemoveWeapons()
{
    auto weapons = GetWeapons();

    for (auto weapon : weapons)
        weapon.Remove();
}
void PluginWeaponManager::DropWeapons()
{
    auto weapons = GetWeapons();

    for (auto weapon : weapons)
        weapon.Drop();
}

std::vector<PluginWeapon> PluginWeaponManager::GetWeapons()
{
    std::vector<PluginWeapon> vec;

    Player* player = g_playerManager->GetPlayer(m_playerId);
    if (!player)
        return vec;

    CCSPlayerPawn* pawn = player->GetPlayerPawn();
    if (!pawn)
        return vec;

    CPlayer_WeaponServices* weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return vec;

    CUtlVector<CHandle<CBasePlayerWeapon>>* weapons = weaponServices->m_hMyWeapons();
    if (!weapons)
        return vec;

    FOR_EACH_VEC(*weapons, i)
    {
        CHandle<CBasePlayerWeapon>& weaponHandle = (*weapons)[i];
        if (!weaponHandle.IsValid())
            continue;

        CBasePlayerWeapon* weapon = weaponHandle.Get();
        if (!weapon)
            continue;

        vec.push_back(PluginWeapon(this->m_playerId, weapon));
    }

    return vec;
}

PluginWeapon::PluginWeapon(int playerId, CBasePlayerWeapon* ptr)
{
    this->m_playerId = playerId;
    this->m_ptr = ptr;
}

SDKBaseClass PluginWeapon::GetCBasePlayerWeapon()
{
    return SDKBaseClass(this->m_ptr, "CBasePlayerWeapon");
}

SDKBaseClass PluginWeapon::GetCCSWeaponBase()
{
    return SDKBaseClass(this->m_ptr, "CCSWeaponBase");
}
SDKBaseClass PluginWeapon::GetCBasePlayerWeaponVData()
{
    if (!this->m_ptr)
        return SDKBaseClass(nullptr, "CBasePlayerWeaponVData");

    return SDKBaseClass((void*)(this->m_ptr->GetWeaponVData()), "CBasePlayerWeaponVData");
}
SDKBaseClass PluginWeapon::GetCCSWeaponBaseVData()
{
    if (!this->m_ptr)
        return SDKBaseClass(nullptr, "CCSWeaponBaseVData");

    return SDKBaseClass((void*)(this->m_ptr->GetWeaponVData()), "CCSWeaponBaseVData");
}

void PluginWeapon::Drop()
{
    Player* player = g_playerManager->GetPlayer(m_playerId);
    if (!player)
        return;

    CCSPlayerPawn* pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CPlayer_WeaponServices* weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return;

    if (!this->m_ptr)
        return;

    weaponServices->DropWeapon(this->m_ptr);
}
void PluginWeapon::Remove()
{
    Player* player = g_playerManager->GetPlayer(m_playerId);
    if (!player)
        return;

    CCSPlayerPawn* pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    CPlayer_WeaponServices* weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return;

    CCSPlayer_ItemServices* itemServices = pawn->m_pItemServices();
    if (!itemServices)
        return;

    if (!this->m_ptr)
        return;

    weaponServices->RemoveWeapon(this->m_ptr);
}

std::vector<uint16_t> paintkitsFallbackCheck = { 1171, 1170, 1169, 1164, 1162, 1161, 1159, 1175, 1174, 1167, 1165, 1168, 1163, 1160, 1166, 1173 };

void PluginWeapon::SetDefaultAttributes()
{
    if (!this->m_ptr)
        return;

    Player* player = g_playerManager->GetPlayer(m_playerId);
    if (!player)
        return;

    CCSPlayerPawn* pawn = player->GetPlayerPawn();
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
        CSkeletonInstance* skeleton = this->m_ptr->m_CBodyComponent()->m_pSceneNode()->GetSkeletonInstance();
        if (skeleton)
        {
            if (skeleton->m_modelState->m_MeshGroupMask() != (legacy == true ? 2 : 1))
            {
                skeleton->m_modelState->m_MeshGroupMask = (legacy == true ? 2 : 1);
            }
        }
    }

    CCSPlayer_ViewModelServices* viewmodelServices = pawn->m_pViewModelServices();
    if (!viewmodelServices)
        return;

    CHandle<CBaseViewModel>* viewmodelHandles = viewmodelServices->m_hViewModel();
    if (!viewmodelHandles)
        return;

    CBaseViewModel* viewmodel = viewmodelHandles[0];

    if (!viewmodel)
        return;

    if (viewmodel->m_CBodyComponent() && viewmodel->m_CBodyComponent()->m_pSceneNode())
    {
        CSkeletonInstance* viewmodelskeleton = viewmodel->m_CBodyComponent()->m_pSceneNode()->GetSkeletonInstance();
        if (viewmodelskeleton && viewmodelskeleton->m_modelState())
            if (viewmodelskeleton->m_modelState->m_MeshGroupMask() != (legacy == true ? 2 : 1))
            {
                viewmodelskeleton->m_modelState->m_MeshGroupMask = (legacy == true ? 2 : 1);
            }
    }

    viewmodel->m_CBodyComponent.StateUpdate();
}