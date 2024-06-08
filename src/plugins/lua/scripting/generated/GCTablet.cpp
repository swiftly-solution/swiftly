#include "../../../core/scripting/generated/classes/GCTablet.h"
#include "../core.h"

void SetupLuaClassGCTablet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTablet>("CTablet")

        .endClass();
}