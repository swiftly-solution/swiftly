#include "../../../core/scripting/generated/classes/GCNmStateNode__TimedEvent_t.h"
#include "../core.h"

void SetupLuaClassGCNmStateNode__TimedEvent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateNode__TimedEvent_t>("CNmStateNode__TimedEvent_t")
        .addProperty("TimeValue", &GCNmStateNode__TimedEvent_t::GetTimeValue, &GCNmStateNode__TimedEvent_t::SetTimeValue)
        .endClass();
}