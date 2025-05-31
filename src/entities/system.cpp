#include "system.h"
#include <memory/gamedata/gamedata.h>
#include <public/entity2/entitykeyvalues.h>
#include <swiftly-ext/core.h>

typedef void (*CBaseEntity_DispatchSpawn)(void*, void*);
typedef void (*UTIL_Remove)(void*);
typedef void* (*UTIL_CreateEntityByName)(const char*, int);
typedef void (*CEntityInstance_AcceptInput)(void*, const char*, void*, void*, variant_t*, int);

void* gameRules = nullptr;

CGameEntitySystem* GameEntitySystem()
{
    return g_pGameEntitySystem;
}

EXT_API void* swiftly_GameEntitySystem()
{
    return (void*)GameEntitySystem();
}

void EntitySystem::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &EntitySystem::StartupServer, true);
}

void EntitySystem::Shutdown()
{
    SH_REMOVE_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &EntitySystem::StartupServer, true);

    g_pGameEntitySystem->RemoveListenerEntity(&g_entityListener);
}

bool bDone = false;
void EntitySystem::StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*)
{
    if (bDone) return;

    g_pGameEntitySystem = ((CGameResourceService*)g_pGameResourceService)->GetGameEntitySystem();
    g_pEntitySystem = g_pGameEntitySystem;

    bDone = true;

    g_pGameEntitySystem->AddListenerEntity(&g_entityListener);
}

void EntitySystem::Spawn(void* entity, void* keyvalues)
{
    g_GameData.FetchSignature<CBaseEntity_DispatchSpawn>("CBaseEntity_DispatchSpawn")(entity, keyvalues);
}

void EntitySystem::Despawn(void* entity)
{
    g_GameData.FetchSignature<UTIL_Remove>("UTIL_Remove")(entity);
}

void* EntitySystem::CreateByName(const char* name)
{
    return g_GameData.FetchSignature<UTIL_CreateEntityByName>("UTIL_CreateEntityByName")(name, -1);
}

void EntitySystem::AcceptInput(void* entity, std::string input, void* activator, void* caller, std::string value, int outputID)
{
    variant_t variantValue = variant_t(value.c_str());
    g_GameData.FetchSignature<CEntityInstance_AcceptInput>("CEntityInstance_AcceptInput")(entity, input.c_str(), activator, caller, &variantValue, outputID);
}

bool EntitySystem::IsValidEntity(void* entity)
{
    return entity != nullptr;
}