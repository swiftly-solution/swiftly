#include "../../../core/scripting/generated/classes/GCFilterLOS.h"
#include "../core.h"

void SetupLuaClassGCFilterLOS(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterLOS>("CFilterLOS")

        .endClass();
}