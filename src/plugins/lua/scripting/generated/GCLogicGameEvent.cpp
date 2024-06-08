#include "../../../core/scripting/generated/classes/GCLogicGameEvent.h"
#include "../core.h"

void SetupLuaClassGCLogicGameEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicGameEvent>("CLogicGameEvent")
        .addProperty("EventName", &GCLogicGameEvent::GetEventName, &GCLogicGameEvent::SetEventName)
        .endClass();
}