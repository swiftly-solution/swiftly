#include "../../../core/scripting/generated/classes/GCLogicActiveAutosave.h"
#include "../core.h"

void SetupLuaClassGCLogicActiveAutosave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicActiveAutosave>("CLogicActiveAutosave")
        .addProperty("TriggerHitPoints", &GCLogicActiveAutosave::GetTriggerHitPoints, &GCLogicActiveAutosave::SetTriggerHitPoints)
        .addProperty("TimeToTrigger", &GCLogicActiveAutosave::GetTimeToTrigger, &GCLogicActiveAutosave::SetTimeToTrigger)
        .addProperty("DangerousTime", &GCLogicActiveAutosave::GetDangerousTime, &GCLogicActiveAutosave::SetDangerousTime)
        .endClass();
}