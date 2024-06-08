#include "../../../core/scripting/generated/classes/GC_OP_SetFromCPSnapshot.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetFromCPSnapshot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetFromCPSnapshot>("C_OP_SetFromCPSnapshot")
        .addProperty("ControlPointNumber", &GC_OP_SetFromCPSnapshot::GetControlPointNumber, &GC_OP_SetFromCPSnapshot::SetControlPointNumber)
        .addProperty("AttributeToRead", &GC_OP_SetFromCPSnapshot::GetAttributeToRead, &GC_OP_SetFromCPSnapshot::SetAttributeToRead)
        .addProperty("AttributeToWrite", &GC_OP_SetFromCPSnapshot::GetAttributeToWrite, &GC_OP_SetFromCPSnapshot::SetAttributeToWrite)
        .addProperty("LocalSpaceCP", &GC_OP_SetFromCPSnapshot::GetLocalSpaceCP, &GC_OP_SetFromCPSnapshot::SetLocalSpaceCP)
        .addProperty("Random", &GC_OP_SetFromCPSnapshot::GetRandom, &GC_OP_SetFromCPSnapshot::SetRandom)
        .addProperty("Reverse", &GC_OP_SetFromCPSnapshot::GetReverse, &GC_OP_SetFromCPSnapshot::SetReverse)
        .addProperty("RandomSeed", &GC_OP_SetFromCPSnapshot::GetRandomSeed, &GC_OP_SetFromCPSnapshot::SetRandomSeed)
        .addProperty("SnapShotStartPoint", &GC_OP_SetFromCPSnapshot::GetSnapShotStartPoint, &GC_OP_SetFromCPSnapshot::SetSnapShotStartPoint)
        .addProperty("SnapShotIncrement", &GC_OP_SetFromCPSnapshot::GetSnapShotIncrement, &GC_OP_SetFromCPSnapshot::SetSnapShotIncrement)
        .addProperty("Interpolation", &GC_OP_SetFromCPSnapshot::GetInterpolation, &GC_OP_SetFromCPSnapshot::SetInterpolation)
        .addProperty("SubSample", &GC_OP_SetFromCPSnapshot::GetSubSample, &GC_OP_SetFromCPSnapshot::SetSubSample)
        .addProperty("Prev", &GC_OP_SetFromCPSnapshot::GetPrev, &GC_OP_SetFromCPSnapshot::SetPrev)
        .endClass();
}