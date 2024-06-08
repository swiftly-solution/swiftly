#include "../../../core/scripting/generated/classes/GC_OP_MovementMoveAlongSkinnedCPSnapshot.h"
#include "../core.h"

void SetupLuaClassGC_OP_MovementMoveAlongSkinnedCPSnapshot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MovementMoveAlongSkinnedCPSnapshot>("C_OP_MovementMoveAlongSkinnedCPSnapshot")
        .addProperty("ControlPointNumber", &GC_OP_MovementMoveAlongSkinnedCPSnapshot::GetControlPointNumber, &GC_OP_MovementMoveAlongSkinnedCPSnapshot::SetControlPointNumber)
        .addProperty("SnapshotControlPointNumber", &GC_OP_MovementMoveAlongSkinnedCPSnapshot::GetSnapshotControlPointNumber, &GC_OP_MovementMoveAlongSkinnedCPSnapshot::SetSnapshotControlPointNumber)
        .addProperty("SetNormal", &GC_OP_MovementMoveAlongSkinnedCPSnapshot::GetSetNormal, &GC_OP_MovementMoveAlongSkinnedCPSnapshot::SetSetNormal)
        .addProperty("SetRadius", &GC_OP_MovementMoveAlongSkinnedCPSnapshot::GetSetRadius, &GC_OP_MovementMoveAlongSkinnedCPSnapshot::SetSetRadius)
        .addProperty("Interpolation", &GC_OP_MovementMoveAlongSkinnedCPSnapshot::GetInterpolation, &GC_OP_MovementMoveAlongSkinnedCPSnapshot::SetInterpolation)
        .addProperty("TValue", &GC_OP_MovementMoveAlongSkinnedCPSnapshot::GetTValue, &GC_OP_MovementMoveAlongSkinnedCPSnapshot::SetTValue)
        .endClass();
}