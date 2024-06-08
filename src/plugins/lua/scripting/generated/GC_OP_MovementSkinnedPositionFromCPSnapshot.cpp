#include "../../../core/scripting/generated/classes/GC_OP_MovementSkinnedPositionFromCPSnapshot.h"
#include "../core.h"

void SetupLuaClassGC_OP_MovementSkinnedPositionFromCPSnapshot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MovementSkinnedPositionFromCPSnapshot>("C_OP_MovementSkinnedPositionFromCPSnapshot")
        .addProperty("SnapshotControlPointNumber", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetSnapshotControlPointNumber, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetSnapshotControlPointNumber)
        .addProperty("ControlPointNumber", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetControlPointNumber, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetControlPointNumber)
        .addProperty("Random", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetRandom, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetRandom)
        .addProperty("RandomSeed", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetRandomSeed, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetRandomSeed)
        .addProperty("SetNormal", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetSetNormal, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetSetNormal)
        .addProperty("SetRadius", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetSetRadius, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetSetRadius)
        .addProperty("IndexType", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetIndexType, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetIndexType)
        .addProperty("ReadIndex", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetReadIndex, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetReadIndex)
        .addProperty("Increment", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetIncrement, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetIncrement)
        .addProperty("FullLoopIncrement", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetFullLoopIncrement, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetFullLoopIncrement)
        .addProperty("SnapShotStartPoint", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetSnapShotStartPoint, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetSnapShotStartPoint)
        .addProperty("Interpolation", &GC_OP_MovementSkinnedPositionFromCPSnapshot::GetInterpolation, &GC_OP_MovementSkinnedPositionFromCPSnapshot::SetInterpolation)
        .endClass();
}