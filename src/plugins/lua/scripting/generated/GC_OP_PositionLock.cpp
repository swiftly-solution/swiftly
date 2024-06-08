#include "../../../core/scripting/generated/classes/GC_OP_PositionLock.h"
#include "../core.h"

void SetupLuaClassGC_OP_PositionLock(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PositionLock>("C_OP_PositionLock")
        .addProperty("TransformInput", &GC_OP_PositionLock::GetTransformInput, &GC_OP_PositionLock::SetTransformInput)
        .addProperty("StartTime_min", &GC_OP_PositionLock::GetStartTime_min, &GC_OP_PositionLock::SetStartTime_min)
        .addProperty("StartTime_max", &GC_OP_PositionLock::GetStartTime_max, &GC_OP_PositionLock::SetStartTime_max)
        .addProperty("StartTime_exp", &GC_OP_PositionLock::GetStartTime_exp, &GC_OP_PositionLock::SetStartTime_exp)
        .addProperty("EndTime_min", &GC_OP_PositionLock::GetEndTime_min, &GC_OP_PositionLock::SetEndTime_min)
        .addProperty("EndTime_max", &GC_OP_PositionLock::GetEndTime_max, &GC_OP_PositionLock::SetEndTime_max)
        .addProperty("EndTime_exp", &GC_OP_PositionLock::GetEndTime_exp, &GC_OP_PositionLock::SetEndTime_exp)
        .addProperty("Range", &GC_OP_PositionLock::GetRange, &GC_OP_PositionLock::SetRange)
        .addProperty("RangeBias", &GC_OP_PositionLock::GetRangeBias, &GC_OP_PositionLock::SetRangeBias)
        .addProperty("JumpThreshold", &GC_OP_PositionLock::GetJumpThreshold, &GC_OP_PositionLock::SetJumpThreshold)
        .addProperty("PrevPosScale", &GC_OP_PositionLock::GetPrevPosScale, &GC_OP_PositionLock::SetPrevPosScale)
        .addProperty("LockRot", &GC_OP_PositionLock::GetLockRot, &GC_OP_PositionLock::SetLockRot)
        .addProperty("FieldOutput", &GC_OP_PositionLock::GetFieldOutput, &GC_OP_PositionLock::SetFieldOutput)
        .addProperty("FieldOutputPrev", &GC_OP_PositionLock::GetFieldOutputPrev, &GC_OP_PositionLock::SetFieldOutputPrev)
        .endClass();
}