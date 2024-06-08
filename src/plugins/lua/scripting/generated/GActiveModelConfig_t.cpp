#include "../../../core/scripting/generated/classes/GActiveModelConfig_t.h"
#include "../core.h"

void SetupLuaClassGActiveModelConfig_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GActiveModelConfig_t>("ActiveModelConfig_t")
        .addProperty("Handle", &GActiveModelConfig_t::GetHandle, &GActiveModelConfig_t::SetHandle)
        .addProperty("Name", &GActiveModelConfig_t::GetName, &GActiveModelConfig_t::SetName)
        .addProperty("AssociatedEntities", &GActiveModelConfig_t::GetAssociatedEntities, &GActiveModelConfig_t::SetAssociatedEntities)
        .addProperty("AssociatedEntityNames", &GActiveModelConfig_t::GetAssociatedEntityNames, &GActiveModelConfig_t::SetAssociatedEntityNames)
        .endClass();
}