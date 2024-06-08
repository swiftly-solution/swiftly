#include "../../../core/scripting/generated/classes/GCAttributeManager.h"
#include "../core.h"

void SetupLuaClassGCAttributeManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttributeManager>("CAttributeManager")
        .addProperty("ReapplyProvisionParity", &GCAttributeManager::GetReapplyProvisionParity, &GCAttributeManager::SetReapplyProvisionParity)
        .addProperty("Outer", &GCAttributeManager::GetOuter, &GCAttributeManager::SetOuter)
        .addProperty("PreventLoopback", &GCAttributeManager::GetPreventLoopback, &GCAttributeManager::SetPreventLoopback)
        .addProperty("ProviderType", &GCAttributeManager::GetProviderType, &GCAttributeManager::SetProviderType)
        .addProperty("CachedResults", &GCAttributeManager::GetCachedResults, &GCAttributeManager::SetCachedResults)
        .endClass();
}