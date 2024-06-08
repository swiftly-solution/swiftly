#include "../../../core/scripting/generated/classes/GC_OP_RampScalarSplineSimple.h"
#include "../core.h"

void SetupLuaClassGC_OP_RampScalarSplineSimple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RampScalarSplineSimple>("C_OP_RampScalarSplineSimple")
        .addProperty("Rate", &GC_OP_RampScalarSplineSimple::GetRate, &GC_OP_RampScalarSplineSimple::SetRate)
        .addProperty("StartTime", &GC_OP_RampScalarSplineSimple::GetStartTime, &GC_OP_RampScalarSplineSimple::SetStartTime)
        .addProperty("EndTime", &GC_OP_RampScalarSplineSimple::GetEndTime, &GC_OP_RampScalarSplineSimple::SetEndTime)
        .addProperty("Field", &GC_OP_RampScalarSplineSimple::GetField, &GC_OP_RampScalarSplineSimple::SetField)
        .addProperty("EaseOut", &GC_OP_RampScalarSplineSimple::GetEaseOut, &GC_OP_RampScalarSplineSimple::SetEaseOut)
        .endClass();
}