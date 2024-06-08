#include "../../../core/scripting/generated/classes/GC_OP_SetRandomControlPointPosition.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetRandomControlPointPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetRandomControlPointPosition>("C_OP_SetRandomControlPointPosition")
        .addProperty("UseWorldLocation", &GC_OP_SetRandomControlPointPosition::GetUseWorldLocation, &GC_OP_SetRandomControlPointPosition::SetUseWorldLocation)
        .addProperty("Orient", &GC_OP_SetRandomControlPointPosition::GetOrient, &GC_OP_SetRandomControlPointPosition::SetOrient)
        .addProperty("CP1", &GC_OP_SetRandomControlPointPosition::GetCP1, &GC_OP_SetRandomControlPointPosition::SetCP1)
        .addProperty("HeadLocation", &GC_OP_SetRandomControlPointPosition::GetHeadLocation, &GC_OP_SetRandomControlPointPosition::SetHeadLocation)
        .addProperty("ReRandomRate", &GC_OP_SetRandomControlPointPosition::GetReRandomRate, &GC_OP_SetRandomControlPointPosition::SetReRandomRate)
        .addProperty("CPMinPos", &GC_OP_SetRandomControlPointPosition::GetCPMinPos, &GC_OP_SetRandomControlPointPosition::SetCPMinPos)
        .addProperty("CPMaxPos", &GC_OP_SetRandomControlPointPosition::GetCPMaxPos, &GC_OP_SetRandomControlPointPosition::SetCPMaxPos)
        .addProperty("Interpolation", &GC_OP_SetRandomControlPointPosition::GetInterpolation, &GC_OP_SetRandomControlPointPosition::SetInterpolation)
        .endClass();
}