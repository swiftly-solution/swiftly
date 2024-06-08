#include "../../../core/scripting/generated/classes/GCStopwatch.h"
#include "../core.h"

void SetupLuaClassGCStopwatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStopwatch>("CStopwatch")
        .addProperty("Interval", &GCStopwatch::GetInterval, &GCStopwatch::SetInterval)
        .endClass();
}