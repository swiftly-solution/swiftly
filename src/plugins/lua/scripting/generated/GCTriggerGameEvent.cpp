#include "../../../core/scripting/generated/classes/GCTriggerGameEvent.h"
#include "../core.h"

void SetupLuaClassGCTriggerGameEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerGameEvent>("CTriggerGameEvent")
        .addProperty("StrStartTouchEventName", &GCTriggerGameEvent::GetStrStartTouchEventName, &GCTriggerGameEvent::SetStrStartTouchEventName)
        .addProperty("StrEndTouchEventName", &GCTriggerGameEvent::GetStrEndTouchEventName, &GCTriggerGameEvent::SetStrEndTouchEventName)
        .addProperty("StrTriggerID", &GCTriggerGameEvent::GetStrTriggerID, &GCTriggerGameEvent::SetStrTriggerID)
        .endClass();
}