#include "../../../core/scripting/generated/classes/GEntityKeyValueData_t.h"
#include "../core.h"

void SetupLuaClassGEntityKeyValueData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntityKeyValueData_t>("EntityKeyValueData_t")
        .addProperty("Connections", &GEntityKeyValueData_t::GetConnections, &GEntityKeyValueData_t::SetConnections)
        .endClass();
}