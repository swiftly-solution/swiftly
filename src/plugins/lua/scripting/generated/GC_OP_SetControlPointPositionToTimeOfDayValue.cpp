#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointPositionToTimeOfDayValue.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointPositionToTimeOfDayValue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointPositionToTimeOfDayValue>("C_OP_SetControlPointPositionToTimeOfDayValue")
        .addProperty("ControlPointNumber", &GC_OP_SetControlPointPositionToTimeOfDayValue::GetControlPointNumber, &GC_OP_SetControlPointPositionToTimeOfDayValue::SetControlPointNumber)
        .addProperty("TimeOfDayParameter", &GC_OP_SetControlPointPositionToTimeOfDayValue::GetTimeOfDayParameter, &GC_OP_SetControlPointPositionToTimeOfDayValue::SetTimeOfDayParameter)
        .addProperty("DefaultValue", &GC_OP_SetControlPointPositionToTimeOfDayValue::GetDefaultValue, &GC_OP_SetControlPointPositionToTimeOfDayValue::SetDefaultValue)
        .endClass();
}