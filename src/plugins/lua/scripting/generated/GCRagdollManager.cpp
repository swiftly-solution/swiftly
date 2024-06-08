#include "../../../core/scripting/generated/classes/GCRagdollManager.h"
#include "../core.h"

void SetupLuaClassGCRagdollManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollManager>("CRagdollManager")
        .addProperty("CurrentMaxRagdollCount", &GCRagdollManager::GetCurrentMaxRagdollCount, &GCRagdollManager::SetCurrentMaxRagdollCount)
        .addProperty("MaxRagdollCount", &GCRagdollManager::GetMaxRagdollCount, &GCRagdollManager::SetMaxRagdollCount)
        .addProperty("SaveImportant", &GCRagdollManager::GetSaveImportant, &GCRagdollManager::SetSaveImportant)
        .endClass();
}