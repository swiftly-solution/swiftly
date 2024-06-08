#include "../../../core/scripting/generated/classes/GTimedEvent.h"
#include "../core.h"

void SetupLuaClassGTimedEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTimedEvent>("TimedEvent")
        .addProperty("TimeBetweenEvents", &GTimedEvent::GetTimeBetweenEvents, &GTimedEvent::SetTimeBetweenEvents)
        .addProperty("NextEvent", &GTimedEvent::GetNextEvent, &GTimedEvent::SetNextEvent)
        .endClass();
}