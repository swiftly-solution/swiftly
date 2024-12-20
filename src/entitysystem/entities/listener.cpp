#include "listener.h"

PluginEvent* pEvent = nullptr;
CEntityListener g_entityListener;

void EntityListener::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &EntityListener::StartupServer, true);
}

void EntityListener::Destroy()
{
    SH_REMOVE_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &EntityListener::StartupServer, true);

    // g_pGameEntitySystem->RemoveListenerEntity(&g_entityListener);
}

bool bDone = false;
void EntityListener::StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*)
{
    if(bDone) return;

    g_pGameEntitySystem = ((CGameResourceService*)g_pGameResourceService)->GetGameEntitySystem();
    g_pEntitySystem = g_pGameEntitySystem;

    // g_pGameEntitySystem->AddListenerEntity(&g_entityListener);

    bDone = true;
}

void CEntityListener::OnEntitySpawned(CEntityInstance* pEntity)
{
    if(!pEvent) pEvent = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEntitySpawned", encoders::msgpack::SerializeToString({ string_format("%p", (void*)pEntity) }), pEvent);
}

void CEntityListener::OnEntityParentChanged(CEntityInstance* pEntity, CEntityInstance* pNewParent)
{
}

void EntityAllowHammerID(CEntityInstance* pEntity)
{
    Plat_WriteMemory((*(void ***)pEntity)[g_Offsets->GetOffset("GetHammerUniqueID")], (uint8_t*)"\xB0\x01", 2);
}

void CEntityListener::OnEntityCreated(CEntityInstance* pEntity)
{   
    ExecuteOnce(EntityAllowHammerID(pEntity));

    if(!pEvent) pEvent = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEntityCreated", encoders::msgpack::SerializeToString({ string_format("%p", (void*)pEntity) }), pEvent);

    if (std::string(pEntity->GetClassname()) == "cs_gamerules")
        gameRules = ((CCSGameRulesProxy*)pEntity)->m_pGameRules;
}

void CEntityListener::OnEntityDeleted(CEntityInstance* pEntity)
{
    if(!pEvent) pEvent = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEntityDeleted", encoders::msgpack::SerializeToString({ string_format("%p", (void*)pEntity) }), pEvent);
}