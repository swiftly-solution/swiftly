#include "../../../core/scripting/generated/classes/GCPointGamestatsCounter.h"
#include "../core.h"

void SetupLuaClassGCPointGamestatsCounter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointGamestatsCounter>("CPointGamestatsCounter")
        .addProperty("StrStatisticName", &GCPointGamestatsCounter::GetStrStatisticName, &GCPointGamestatsCounter::SetStrStatisticName)
        .addProperty("Disabled", &GCPointGamestatsCounter::GetDisabled, &GCPointGamestatsCounter::SetDisabled)
        .endClass();
}