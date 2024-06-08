#include "../../../core/scripting/generated/classes/GCHandleDummy.h"
#include "../core.h"

void SetupLuaClassGCHandleDummy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHandleDummy>("CHandleDummy")

        .endClass();
}