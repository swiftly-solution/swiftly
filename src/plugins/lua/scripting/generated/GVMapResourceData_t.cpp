#include "../../../core/scripting/generated/classes/GVMapResourceData_t.h"
#include "../core.h"

void SetupLuaClassGVMapResourceData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMapResourceData_t>("VMapResourceData_t")

        .endClass();
}