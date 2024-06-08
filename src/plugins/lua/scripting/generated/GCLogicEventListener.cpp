#include "../../../core/scripting/generated/classes/GCLogicEventListener.h"
#include "../core.h"

void SetupLuaClassGCLogicEventListener(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicEventListener>("CLogicEventListener")
        .addProperty("StrEventName", &GCLogicEventListener::GetStrEventName, &GCLogicEventListener::SetStrEventName)
        .addProperty("IsEnabled", &GCLogicEventListener::GetIsEnabled, &GCLogicEventListener::SetIsEnabled)
        .addProperty("Team", &GCLogicEventListener::GetTeam, &GCLogicEventListener::SetTeam)
        .addProperty("OnEventFired", &GCLogicEventListener::GetOnEventFired, &GCLogicEventListener::SetOnEventFired)
        .endClass();
}