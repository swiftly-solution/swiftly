#include "../../../core/scripting/generated/classes/GCRandStopwatch.h"
#include "../core.h"

void SetupLuaClassGCRandStopwatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRandStopwatch>("CRandStopwatch")
        .addProperty("MinInterval", &GCRandStopwatch::GetMinInterval, &GCRandStopwatch::SetMinInterval)
        .addProperty("MaxInterval", &GCRandStopwatch::GetMaxInterval, &GCRandStopwatch::SetMaxInterval)
        .endClass();
}