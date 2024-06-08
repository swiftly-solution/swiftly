#include "../../../core/scripting/generated/classes/GCSimpleStopwatch.h"
#include "../core.h"

void SetupLuaClassGCSimpleStopwatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSimpleStopwatch>("CSimpleStopwatch")

        .endClass();
}