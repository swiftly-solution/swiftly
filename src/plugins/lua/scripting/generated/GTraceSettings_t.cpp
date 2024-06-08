#include "../../../core/scripting/generated/classes/GTraceSettings_t.h"
#include "../core.h"

void SetupLuaClassGTraceSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTraceSettings_t>("TraceSettings_t")
        .addProperty("TraceHeight", &GTraceSettings_t::GetTraceHeight, &GTraceSettings_t::SetTraceHeight)
        .addProperty("TraceRadius", &GTraceSettings_t::GetTraceRadius, &GTraceSettings_t::SetTraceRadius)
        .endClass();
}