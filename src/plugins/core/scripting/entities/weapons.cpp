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
        if(((CBasePlayerWeapon*)weapon.GetCBasePlayerWeapon().GetPtr())->GetClassname() == classname)
            weapon.Remove();
}

void PluginWeaponManager::RemoveBySlot(int slot)
{
    auto weapons = GetWeapons();

    for(auto weapon : weapons)
        if(((CCSWeaponBaseVData*)weapon.GetCCSWeaponBaseVData().GetPtr())->m_GearSlot == (cgear_slot_t)slot)
            weapon.Remove();
}

PluginWeapon PluginWeaponManager::GetFirstInSlot(int slot)
{
    auto weapons = GetWeapons();

    for(auto weapon : weapons)
        if(((CCSWeaponBaseVData*)weapon.GetCCSWeaponBaseVData().GetPtr())->m_GearSlot == (cgear_slot_t)slot)
            return weapon;

    return PluginWeapon(m_playerId, nullptr);
}

std::vector<PluginWeapon> PluginWeaponManager::GetInSlot(int slot)
{
    auto weapons = GetWeapons();
    std::vector<PluginWeapon> vec;

    for(auto weapon : weapons)
        if(((CCSWeaponBaseVData*)weapon.GetCCSWeaponBaseVData().GetPtr())->m_GearSlot == (cgear_slot_t)slot)
            vec.push_back(weapon);

    return vec;
}

void PluginWeaponManager::RemoveByItemDefinition(int idx)
{
    auto weapons = GetWeapons();

    for(auto weapon : weapons)
        if(((CBasePlayerWeapon*)weapon.GetCBasePlayerWeapon().GetPtr())->m_AttributeManager().m_Item().m_iItemDefinitionIndex == idx)
            weapon.Remove();
}

PluginWeapon::PluginWeapon(int playerId, CBasePlayerWeapon* ptr)
{
    this->m_playerId = playerId;
    this->m_ptr = ptr;
}

PluginWeapon::PluginWeapon(int playerId, std::string ptr)
{
    this->m_playerId = playerId;
    this->m_ptr = (CBasePlayerWeapon*)strtol(ptr.c_str(), nullptr, 16);
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

std::set<uint16_t> paintkitsFallbackCheck;

void PluginWeapon::SetDefaultAttributes()
{
    if(paintkitsFallbackCheck.size() == 0) {
        KeyValues kv("scripts/items/items_game.txt");
        kv.LoadFromFile(g_pFullFileSystem, "scripts/items/items_game.txt", "GAME");

        for (KeyValues *sub = kv.GetFirstSubKey(); sub != nullptr; sub = sub->GetNextKey()) {
            if(!strcmp(sub->GetName(), "paint_kits")) {
                for (KeyValues *sub2 = sub->GetFirstSubKey(); sub2 != nullptr; sub2 = sub2->GetNextKey()) {
                    if(strcmp(sub2->GetString("composite_material_path", ""), "") != 0 && !sub2->GetBool("use_legacy_model", false)) {
                        paintkitsFallbackCheck.insert(V_StringToUint16(sub2->GetName(), 0));
                    }
                }
            }
        }
    }

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
    bool legacy = (paintkitsFallbackCheck.find(paintkit) == paintkitsFallbackCheck.end());

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