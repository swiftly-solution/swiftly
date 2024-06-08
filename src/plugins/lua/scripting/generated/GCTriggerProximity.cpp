#include "../../../core/scripting/generated/classes/GCTriggerProximity.h"
#include "../core.h"

void SetupLuaClassGCTriggerProximity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerProximity>("CTriggerProximity")
        .addProperty("MeasureTarget", &GCTriggerProximity::GetMeasureTarget, &GCTriggerProximity::SetMeasureTarget)
        .addProperty("MeasureTarget1", &GCTriggerProximity::GetMeasureTarget1, &GCTriggerProximity::SetMeasureTarget1)
        .addProperty("Radius", &GCTriggerProximity::GetRadius, &GCTriggerProximity::SetRadius)
        .addProperty("Touchers", &GCTriggerProximity::GetTouchers, &GCTriggerProximity::SetTouchers)
        .endClass();
}