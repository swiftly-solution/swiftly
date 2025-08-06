#include <vector>
#include <set>
#include <public/tier1/KeyValues.h>

#include <scripting/core.h>
#include <memory/gamedata/gamedata.h>
#include <memory/virtual/virtual.h>
#include <entities/system.h>
#include <utils/utils.h>

#include "ehandle.h"
#include <sdk/schema.h>
#include <server/player/manager.h>

typedef void (*GiveNamedItem_t)(void*, const char*, int, int, int, int);

std::set<uint16_t> paintkitsFallbackCheck;

void* GetWeaponServices(int playerid) {
    auto player = g_playerManager.GetPlayer(playerid);
    if (!player) return nullptr;

    void* pawn = player->GetPawn();
    if (!pawn) return nullptr;

    void* weaponServices = schema::GetProp<void*>(pawn, "CBasePlayerPawn", "m_pWeaponServices");
    if (!weaponServices) return nullptr;

    return weaponServices;
}

void DropWeapon(void* weaponServices, void* weapon)
{
    if (!weaponServices) return;
    if (!weapon) return;

    CALL_VIRTUAL(void, g_GameData.GetOffset("CCSPlayer_WeaponServices_DropWeapon"), weaponServices, weapon, nullptr, nullptr);
}

void RemoveWeapon(void* weaponServices, void* weapon)
{
    if (!weaponServices) return;
    if (!weapon) return;

    DropWeapon(weaponServices, weapon);
    g_entSystem.Despawn(weapon);
}

std::vector<void*> GetWeapons(int playerid) {
    std::vector<void*> weapons;

    void* weaponServices = GetWeaponServices(playerid);
    if (!weaponServices) return weapons;

    CUtlVector<CHandle<CEntityInstance>>* weaponsVec = schema::GetPropPtr<CUtlVector<CHandle<CEntityInstance>>>(weaponServices, "CPlayer_WeaponServices", "m_hMyWeapons");
    if (!weaponsVec) return weapons;

    FOR_EACH_VEC(*weaponsVec, i)
    {
        CHandle<CEntityInstance>& weaponHandle = (*weaponsVec)[i];
        if (!weaponHandle.IsValid())
            continue;

        weapons.push_back(weaponHandle.Get());
    }

    return weapons;
}

LoadScriptingComponent(weapons, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("WeaponManager");
    ADD_CLASS("Weapon");

    ADD_CLASS_FUNCTION("WeaponManager", "GiveWeapon", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        std::string weapon_name = context->GetArgumentOr<std::string>(0, "");
        if (weapon_name == "") return;

        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        void* pawn = player->GetPawn();
        if (!pawn) return;

        void* itemServices = schema::GetProp<void*>(pawn, "CBasePlayerPawn", "m_pItemServices");
        if (!itemServices) return;

        g_GameData.FetchSignature<GiveNamedItem_t>("GiveNamedItem")(itemServices, weapon_name.c_str(), 0, 0, 0, 0);
    });

    ADD_CLASS_FUNCTION("WeaponManager", "RemoveWeapons", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        void* weaponService = GetWeaponServices(playerid);
        if (!weaponService) return;

        auto weapons = GetWeapons(playerid);

        for (void* weapon : weapons)
            RemoveWeapon(weaponService, weapon);
    });

    ADD_CLASS_FUNCTION("WeaponManager", "DropWeapons", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        void* weaponService = GetWeaponServices(playerid);
        if (!weaponService) return;

        auto weapons = GetWeapons(playerid);

        for (void* weapon : weapons)
            DropWeapon(weaponService, weapon);
    });

    ADD_CLASS_FUNCTION("WeaponManager", "GetWeapons", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        auto weapons = GetWeapons(playerid);

        std::vector<EValue> scriptWeapons;
        for (void* weapon : weapons)
            scriptWeapons.push_back(MAKE_CLASS_INSTANCE("Weapon", { { "playerid", playerid }, { "ptr", weapon } }));

        context->SetReturn(scriptWeapons);
    });

    ADD_CLASS_FUNCTION("WeaponManager", "RemoveByClassname", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        std::string class_name = context->GetArgumentOr<std::string>(0, "");
        if (class_name == "") return;

        void* weaponService = GetWeaponServices(playerid);
        if (!weaponService) return;

        auto weapons = GetWeapons(playerid);

        for (void* weapon : weapons)
            if (((CEntityInstance*)weapon)->GetClassname() == class_name)
                RemoveWeapon(weaponService, weapon);
    });

    ADD_CLASS_FUNCTION("WeaponManager", "RemoveBySlot", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        int slot = context->GetArgumentOr<int>(0, -1);
        if (slot == -1) return;

        void* weaponService = GetWeaponServices(playerid);
        if (!weaponService) return;

        auto weapons = GetWeapons(playerid);

        for (void* weapon : weapons) {
            void* vdata = schema::GetVData(weapon);
            int gear_slot = schema::GetProp<int>(vdata, "CCSWeaponBaseVData", "m_GearSlot");
            if (gear_slot == slot) {
                RemoveWeapon(weaponService, weapon);
            }
        }
    });

    ADD_CLASS_FUNCTION("WeaponManager", "GetFirstInSlot", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        int slot = context->GetArgumentOr<int>(0, -1);
        if (slot == -1) return;

        void* weaponService = GetWeaponServices(playerid);
        if (!weaponService) return;

        auto weapons = GetWeapons(playerid);

        void* weaponptr = nullptr;
        for (void* weapon : weapons) {
            void* vdata = schema::GetVData(weapon);
            int gear_slot = schema::GetProp<int>(vdata, "CCSWeaponBaseVData", "m_GearSlot");
            if (gear_slot == slot) {
                weaponptr = weapon;
                break;
            }
        }

        context->SetReturn(MAKE_CLASS_INSTANCE("Weapon", { { "playerid", playerid }, { "ptr", weaponptr } }));
    });

    ADD_CLASS_FUNCTION("WeaponManager", "GetInSlot", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        int slot = context->GetArgumentOr<int>(0, -1);
        if (slot == -1) return;

        void* weaponService = GetWeaponServices(playerid);
        if (!weaponService) return;

        auto weapons = GetWeapons(playerid);

        std::vector<EValue> scriptWeapons;
        for (void* weapon : weapons) {
            void* vdata = schema::GetVData(weapon);
            int gear_slot = schema::GetProp<int>(vdata, "CCSWeaponBaseVData", "m_GearSlot");
            if (gear_slot == slot) {
                scriptWeapons.push_back(MAKE_CLASS_INSTANCE("Weapon", { { "playerid", playerid }, { "ptr", weapon } }));
            }
        }

        context->SetReturn(scriptWeapons);
    });

    ADD_CLASS_FUNCTION("WeaponManager", "RemoveByItemDefinition", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        int itemid = context->GetArgumentOr<int>(0, -1);
        if (itemid == -1) return;

        void* weaponService = GetWeaponServices(playerid);
        if (!weaponService) return;

        auto weapons = GetWeapons(playerid);

        for (void* weapon : weapons) {
            void* attrContainer = schema::GetPropPtr<void>(weapon, "CEconEntity", "m_AttributeManager");
            if (!attrContainer) continue;

            void* item = schema::GetPropPtr<void>(attrContainer, "CAttributeContainer", "m_Item");
            if (!item) continue;

            int itemidx = schema::GetProp<int>(item, "CEconItemView", "m_iItemDefinitionIndex");
            if (itemidx == itemid) {
                RemoveWeapon(weaponService, weapon);
            }
        }
    });

    ADD_CLASS_FUNCTION("Weapon", "Weapon", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = context->GetArgumentOr<int>(0, -1);
        if (playerid == -1) return;

        data->SetData("playerid", playerid);

        auto classData = context->GetArgumentOr<ClassData*>(1, nullptr);
        if (classData) {
            if (classData->HasData("class_name")) {
                data->SetData("ptr", classData->GetData<void*>("class_ptr"));
            }
            else if (classData->HasData("ptr")) {
                data->SetData("ptr", classData->GetData<void*>("ptr"));
            }
            else data->SetData("ptr", (void*)nullptr);
        }
        else {
            auto strptr = context->GetArgumentOr<std::string>(1, "");
            if (starts_with(strptr, "0x")) {
                data->SetData("ptr", (void*)StringToPtr(strptr));
            }
            else data->SetData("ptr", (void*)nullptr);
        }
    });

    ADD_CLASS_FUNCTION("Weapon", "CBasePlayerWeapon", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MakeSDKClassInstance("CBasePlayerWeapon", data->GetData<void*>("ptr"), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Weapon", "CCSWeaponBase", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MakeSDKClassInstance("CCSWeaponBase", data->GetData<void*>("ptr"), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Weapon", "CBasePlayerWeaponVData", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MakeSDKClassInstance("CBasePlayerWeaponVData", schema::GetVData(data->GetData<void*>("ptr")), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Weapon", "CCSWeaponBaseVData", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MakeSDKClassInstance("CCSWeaponBaseVData", schema::GetVData(data->GetData<void*>("ptr")), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Weapon", "Drop", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        void* weaponService = GetWeaponServices(playerid);
        if (!weaponService) return;

        void* weapon = data->GetData<void*>("ptr");

        DropWeapon(weaponService, weapon);
    });

    ADD_CLASS_FUNCTION("Weapon", "Remove", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        void* weaponService = GetWeaponServices(playerid);
        if (!weaponService) return;

        void* weapon = data->GetData<void*>("ptr");

        RemoveWeapon(weaponService, weapon);
    });

    ADD_CLASS_FUNCTION("Weapon", "SetDefaultAttributes", [](FunctionContext* context, ClassData* data) -> void {
        if (paintkitsFallbackCheck.size() == 0) {
            KeyValues kv("scripts/items/items_game.txt");
            kv.LoadFromFile(g_pFullFileSystem, "scripts/items/items_game.txt", "GAME");

            for (KeyValues* sub = kv.GetFirstSubKey(); sub != nullptr; sub = sub->GetNextKey()) {
                if (!strcmp(sub->GetName(), "paint_kits")) {
                    for (KeyValues* sub2 = sub->GetFirstSubKey(); sub2 != nullptr; sub2 = sub2->GetNextKey()) {
                        if (strcmp(sub2->GetString("composite_material_path", ""), "") != 0 && !sub2->GetBool("use_legacy_model", false)) {
                            paintkitsFallbackCheck.insert(V_StringToUint16(sub2->GetName(), 0));
                        }
                    }
                }
            }
        }

        void* weapon = data->GetData<void*>("ptr");
        if (!weapon) return;

        int playerid = data->GetDataOr<int>("playerid", -1);
        if (playerid == -1) return;

        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        void* pawn = player->GetPlayerPawn();
        if (!pawn) return;

        void* attrContainer = schema::GetPropPtr<void>(weapon, "CEconEntity", "m_AttributeManager");
        if (!attrContainer) return;

        void* item = schema::GetPropPtr<void>(attrContainer, "CAttributeContainer", "m_Item");
        if (!item) return;

        schema::SetProp(item, "CEconItemView", "m_iItemIDHigh", (uint32_t)-1);

        void* vdata = schema::GetVData(weapon);
        int gear_slot = schema::GetProp<int>(vdata, "CCSWeaponBaseVData", "m_GearSlot");
        if (gear_slot == 0x2) {
            schema::SetProp(item, "CEconItemView", "m_iEntityQuality", 3);
        }

        int fallbackPaintKit = schema::GetProp<int>(weapon, "CEconEntity", "m_nFallbackPaintKit");
        bool legacy = (paintkitsFallbackCheck.find(fallbackPaintKit) == paintkitsFallbackCheck.end());

        void* bodyComponent = schema::GetProp<void*>(weapon, "CBaseEntity", "m_CBodyComponent");
        if (bodyComponent) {
            void* sceneNode = schema::GetProp<void*>(bodyComponent, "CBodyComponent", "m_pSceneNode");
            if (sceneNode) {
                void* skeletonInstance = CALL_VIRTUAL(void*, g_GameData.GetOffset("CGameSceneNode_GetSkeletonInstance"), sceneNode);
                if (skeletonInstance) {
                    void* modelState = schema::GetPropPtr<void>(skeletonInstance, "CSkeletonInstance", "m_modelState");
                    if (modelState) {
                        uint64_t meshGroupMask = schema::GetProp<uint64_t>(modelState, "CModelState", "m_MeshGroupMask");
                        if (meshGroupMask != (legacy ? 2 : 1)) schema::SetProp<uint64_t>(modelState, "CModelState", "m_MeshGroupMask", (legacy ? 2 : 1));
                    }
                }
            }
        }
    });
})