#include "../../../core/scripting/generated/classes/GCBumpMine.h"
#include "../core.h"

void SetupLuaClassGCBumpMine(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBumpMine>("CBumpMine")

        .endClass();
}