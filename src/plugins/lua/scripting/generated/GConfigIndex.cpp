#include "../../../core/scripting/generated/classes/GConfigIndex.h"
#include "../core.h"

void SetupLuaClassGConfigIndex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GConfigIndex>("ConfigIndex")
        .addProperty("Group", &GConfigIndex::GetGroup, &GConfigIndex::SetGroup)
        .addProperty("Config", &GConfigIndex::GetConfig, &GConfigIndex::SetConfig)
        .endClass();
}