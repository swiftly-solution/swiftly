#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointPositionToRandomActiveCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointPositionToRandomActiveCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointPositionToRandomActiveCP>("C_OP_SetControlPointPositionToRandomActiveCP")
        .addProperty("CP1", &GC_OP_SetControlPointPositionToRandomActiveCP::GetCP1, &GC_OP_SetControlPointPositionToRandomActiveCP::SetCP1)
        .addProperty("HeadLocationMin", &GC_OP_SetControlPointPositionToRandomActiveCP::GetHeadLocationMin, &GC_OP_SetControlPointPositionToRandomActiveCP::SetHeadLocationMin)
        .addProperty("HeadLocationMax", &GC_OP_SetControlPointPositionToRandomActiveCP::GetHeadLocationMax, &GC_OP_SetControlPointPositionToRandomActiveCP::SetHeadLocationMax)
        .addProperty("ResetRate", &GC_OP_SetControlPointPositionToRandomActiveCP::GetResetRate, &GC_OP_SetControlPointPositionToRandomActiveCP::SetResetRate)
        .endClass();
}