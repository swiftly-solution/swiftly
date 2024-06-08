#include "../../../core/scripting/generated/classes/GC_OP_RampScalarLinearSimple.h"
#include "../core.h"

void SetupLuaClassGC_OP_RampScalarLinearSimple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RampScalarLinearSimple>("C_OP_RampScalarLinearSimple")
        .addProperty("Rate", &GC_OP_RampScalarLinearSimple::GetRate, &GC_OP_RampScalarLinearSimple::SetRate)
        .addProperty("StartTime", &GC_OP_RampScalarLinearSimple::GetStartTime, &GC_OP_RampScalarLinearSimple::SetStartTime)
        .addProperty("EndTime", &GC_OP_RampScalarLinearSimple::GetEndTime, &GC_OP_RampScalarLinearSimple::SetEndTime)
        .addProperty("Field", &GC_OP_RampScalarLinearSimple::GetField, &GC_OP_RampScalarLinearSimple::SetField)
        .endClass();
}