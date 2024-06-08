#include "../../../core/scripting/generated/classes/GCNmEvent.h"
#include "../core.h"

void SetupLuaClassGCNmEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmEvent>("CNmEvent")
        .addProperty("StartTime", &GCNmEvent::GetStartTime, &GCNmEvent::SetStartTime)
        .addProperty("Duration", &GCNmEvent::GetDuration, &GCNmEvent::SetDuration)
        .endClass();
}