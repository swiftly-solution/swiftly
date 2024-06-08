#include "../../../core/scripting/generated/classes/GCLogicRelay.h"
#include "../core.h"

void SetupLuaClassGCLogicRelay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicRelay>("CLogicRelay")
        .addProperty("OnTrigger", &GCLogicRelay::GetOnTrigger, &GCLogicRelay::SetOnTrigger)
        .addProperty("OnSpawn", &GCLogicRelay::GetOnSpawn, &GCLogicRelay::SetOnSpawn)
        .addProperty("Disabled", &GCLogicRelay::GetDisabled, &GCLogicRelay::SetDisabled)
        .addProperty("WaitForRefire", &GCLogicRelay::GetWaitForRefire, &GCLogicRelay::SetWaitForRefire)
        .addProperty("TriggerOnce", &GCLogicRelay::GetTriggerOnce, &GCLogicRelay::SetTriggerOnce)
        .addProperty("FastRetrigger", &GCLogicRelay::GetFastRetrigger, &GCLogicRelay::SetFastRetrigger)
        .addProperty("PassthoughCaller", &GCLogicRelay::GetPassthoughCaller, &GCLogicRelay::SetPassthoughCaller)
        .endClass();
}