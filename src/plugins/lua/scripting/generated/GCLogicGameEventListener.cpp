#include "../../../core/scripting/generated/classes/GCLogicGameEventListener.h"
#include "../core.h"

void SetupLuaClassGCLogicGameEventListener(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicGameEventListener>("CLogicGameEventListener")
        .addProperty("OnEventFired", &GCLogicGameEventListener::GetOnEventFired, &GCLogicGameEventListener::SetOnEventFired)
        .addProperty("GameEventName", &GCLogicGameEventListener::GetGameEventName, &GCLogicGameEventListener::SetGameEventName)
        .addProperty("GameEventItem", &GCLogicGameEventListener::GetGameEventItem, &GCLogicGameEventListener::SetGameEventItem)
        .addProperty("Enabled", &GCLogicGameEventListener::GetEnabled, &GCLogicGameEventListener::SetEnabled)
        .addProperty("StartDisabled", &GCLogicGameEventListener::GetStartDisabled, &GCLogicGameEventListener::SetStartDisabled)
        .endClass();
}