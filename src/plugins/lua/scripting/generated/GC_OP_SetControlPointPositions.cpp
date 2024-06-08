#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointPositions.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointPositions(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointPositions>("C_OP_SetControlPointPositions")
        .addProperty("UseWorldLocation", &GC_OP_SetControlPointPositions::GetUseWorldLocation, &GC_OP_SetControlPointPositions::SetUseWorldLocation)
        .addProperty("Orient", &GC_OP_SetControlPointPositions::GetOrient, &GC_OP_SetControlPointPositions::SetOrient)
        .addProperty("SetOnce", &GC_OP_SetControlPointPositions::GetSetOnce, &GC_OP_SetControlPointPositions::SetSetOnce)
        .addProperty("CP1", &GC_OP_SetControlPointPositions::GetCP1, &GC_OP_SetControlPointPositions::SetCP1)
        .addProperty("CP2", &GC_OP_SetControlPointPositions::GetCP2, &GC_OP_SetControlPointPositions::SetCP2)
        .addProperty("CP3", &GC_OP_SetControlPointPositions::GetCP3, &GC_OP_SetControlPointPositions::SetCP3)
        .addProperty("CP4", &GC_OP_SetControlPointPositions::GetCP4, &GC_OP_SetControlPointPositions::SetCP4)
        .addProperty("CP1Pos", &GC_OP_SetControlPointPositions::GetCP1Pos, &GC_OP_SetControlPointPositions::SetCP1Pos)
        .addProperty("CP2Pos", &GC_OP_SetControlPointPositions::GetCP2Pos, &GC_OP_SetControlPointPositions::SetCP2Pos)
        .addProperty("CP3Pos", &GC_OP_SetControlPointPositions::GetCP3Pos, &GC_OP_SetControlPointPositions::SetCP3Pos)
        .addProperty("CP4Pos", &GC_OP_SetControlPointPositions::GetCP4Pos, &GC_OP_SetControlPointPositions::SetCP4Pos)
        .addProperty("HeadLocation", &GC_OP_SetControlPointPositions::GetHeadLocation, &GC_OP_SetControlPointPositions::SetHeadLocation)
        .endClass();
}