#include "../../../core/scripting/generated/classes/GCInterpolatedValue.h"
#include "../core.h"

void SetupLuaClassGCInterpolatedValue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInterpolatedValue>("CInterpolatedValue")
        .addProperty("StartTime", &GCInterpolatedValue::GetStartTime, &GCInterpolatedValue::SetStartTime)
        .addProperty("EndTime", &GCInterpolatedValue::GetEndTime, &GCInterpolatedValue::SetEndTime)
        .addProperty("StartValue", &GCInterpolatedValue::GetStartValue, &GCInterpolatedValue::SetStartValue)
        .addProperty("EndValue", &GCInterpolatedValue::GetEndValue, &GCInterpolatedValue::SetEndValue)
        .addProperty("InterpType", &GCInterpolatedValue::GetInterpType, &GCInterpolatedValue::SetInterpType)
        .endClass();
}