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

void PluginWeaponManager::RemoveByClassname(std::string classname)
{
    auto weapons = GetWeapons();

    for(auto weapon : weapons)
        if(((CBasePlayerWeapon*)weapon.GetCBasePlayerWeapon()->GetPtr())->GetClassname() == classname)
            weapon.Remove();
}

void PluginWeaponManager::RemoveBySlot(int slot)
{
    auto weapons = GetWeapons();

    for(auto weapon : weapons)
        if(((CCSWeaponBaseVData*)weapon.GetCCSWeaponBaseVData()->GetPtr())->m_GearSlot == (cgear_slot_t)slot)
            weapon.Remove();
}

PluginWeapon PluginWeaponManager::GetFirstInSlot(int slot)
{
    auto weapons = GetWeapons();

    for(auto weapon : weapons)
        if(((CCSWeaponBaseVData*)weapon.GetCCSWeaponBaseVData()->GetPtr())->m_GearSlot == (cgear_slot_t)slot)
            return weapon;

    return PluginWeapon(m_playerId, nullptr);
}

std::vector<PluginWeapon> PluginWeaponManager::GetInSlot(int slot)
{
    auto weapons = GetWeapons();
    std::vector<PluginWeapon> vec;

    for(auto weapon : weapons)
        if(((CCSWeaponBaseVData*)weapon.GetCCSWeaponBaseVData()->GetPtr())->m_GearSlot == (cgear_slot_t)slot)
            vec.push_back(weapon);

    return vec;
}

void PluginWeaponManager::RemoveByItemDefinition(int idx)
{
    auto weapons = GetWeapons();

    for(auto weapon : weapons)
        if(((CBasePlayerWeapon*)weapon.GetCBasePlayerWeapon()->GetPtr())->m_AttributeManager().m_Item().m_iItemDefinitionIndex == idx)
            weapon.Remove();
}

PluginWeapon::PluginWeapon(int playerId, CBasePlayerWeapon* ptr)
{
    this->m_playerId = playerId;
    this->m_ptr = ptr;

    pCBasePlayerWeapon = new SDKBaseClass(this->m_ptr, "CBasePlayerWeapon");
    pCCSWeaponBase = new SDKBaseClass(this->m_ptr, "CCSWeaponBase");
    pCBasePlayerWeaponVData = new SDKBaseClass(this->m_ptr, "CBasePlayerWeaponVData");
    pCCSWeaponBaseVData = new SDKBaseClass(this->m_ptr, "CCSWeaponBaseVData");
}

PluginWeapon::PluginWeapon(int playerId, std::string ptr)
{
    this->m_playerId = playerId;
    this->m_ptr = (CBasePlayerWeapon*)strtol(ptr.c_str(), nullptr, 16);

    pCBasePlayerWeapon = new SDKBaseClass(this->m_ptr, "CBasePlayerWeapon");
    pCCSWeaponBase = new SDKBaseClass(this->m_ptr, "CCSWeaponBase");
    pCBasePlayerWeaponVData = new SDKBaseClass(nullptr, "CBasePlayerWeaponVData");
    pCCSWeaponBaseVData = new SDKBaseClass(nullptr, "CCSWeaponBaseVData");
}

PluginWeapon::~PluginWeapon()
{
    delete pCBasePlayerWeapon;
    delete pCCSWeaponBase;
    delete pCBasePlayerWeaponVData;
    delete pCCSWeaponBaseVData;
}

SDKBaseClass *PluginWeapon::GetCBasePlayerWeapon()
{
    return pCBasePlayerWeapon;
}

SDKBaseClass *PluginWeapon::GetCCSWeaponBase()
{
    return pCCSWeaponBase;
}

SDKBaseClass *PluginWeapon::GetCBasePlayerWeaponVData()
{
    if (!this->m_ptr) return pCBasePlayerWeaponVData;
    else if((void*)(this->m_ptr->GetWeaponVData()) != pCBasePlayerWeaponVData->GetPtr()) pCBasePlayerWeaponVData->SetPtr(this->m_ptr->GetWeaponVData());
    
    return pCBasePlayerWeaponVData;
}

SDKBaseClass *PluginWeapon::GetCCSWeaponBaseVData()
{
    if (!this->m_ptr) return pCCSWeaponBaseVData;
    else if((void*)(this->m_ptr->GetWeaponVData()) != pCCSWeaponBaseVData->GetPtr()) pCCSWeaponBaseVData->SetPtr(this->m_ptr->GetWeaponVData());
    
    return pCCSWeaponBaseVData;
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

std::vector<uint16_t> paintkitsFallbackCheck = { 106, 112, 113, 114, 115, 117, 118, 120, 121, 123, 126, 127, 128, 129, 130, 131, 133, 134, 137, 138, 139, 140, 142, 144, 145, 146, 152, 160, 161, 163, 173, 239, 292, 324, 331, 412, 461, 513, 766, 768, 770, 773, 774, 830, 831, 832, 834, 874, 875, 877, 878, 882, 883, 901, 912, 936, 937, 938, 939, 940, 1054, 1062, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167, 1168, 1169, 1170, 1171, 1172, 1173, 1174, 1175, 1177, 1178, 1179, 1180 };

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