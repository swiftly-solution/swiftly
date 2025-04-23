#include "system.h"

#include <utils/platform/platform.h>
#include <memory/gamedata/gamedata.h>
#include <sdk/schema.h>
#include <plugins/manager.h>
#include <public/entity2/entitykeyvalues.h>

CEntityListener g_entityListener;

void CEntityListener::OnEntitySpawned(CEntityInstance* pEntity)
{
    ClassData* entity = new ClassData({ { "should_mark_freeable", true }, { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)pEntity } }, "SDKClass", nullptr);
    g_pluginManager.ExecuteEvent("core", "OnEntitySpawned", { entity }, {});
}

void CEntityListener::OnEntityParentChanged(CEntityInstance* pEntity, CEntityInstance* pNewParent)
{
    ClassData* entity = new ClassData({ { "should_mark_freeable", true }, { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)pEntity } }, "SDKClass", nullptr);
    ClassData* pentity = new ClassData({ { "should_mark_freeable", true }, { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)pNewParent } }, "SDKClass", nullptr);
    g_pluginManager.ExecuteEvent("core", "OnEntityParentChanged", { entity, pentity }, {});
}

void EntityAllowHammerID(CEntityInstance* pEntity)
{
    Plat_WriteMemory((*(void***)pEntity)[g_GameData.GetOffset("GetHammerUniqueID")], (uint8_t*)"\xB0\x01", 2);
}

void CEntityListener::OnEntityCreated(CEntityInstance* pEntity)
{
    ExecuteOnce(EntityAllowHammerID(pEntity));

    ClassData* entity = new ClassData({ { "should_mark_freeable", true }, { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)pEntity } }, "SDKClass", nullptr);
    g_pluginManager.ExecuteEvent("core", "OnEntityCreated", { entity }, {});

    if (std::string(pEntity->GetClassname()) == "cs_gamerules")
        gameRules = schema::GetProp<void*>(pEntity, "CCSGameRulesProxy", "m_pGameRules");
}

void CEntityListener::OnEntityDeleted(CEntityInstance* pEntity)
{
    ClassData* entity = new ClassData({ { "should_mark_freeable", true }, { "class_name", std::string("CEntityInstance") }, { "class_ptr", (void*)pEntity } }, "SDKClass", nullptr);
    g_pluginManager.ExecuteEvent("core", "OnEntityDeleted", { entity }, {});
}