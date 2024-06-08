#include "../../../core/scripting/generated/classes/GC_OP_LockToBone.h"
#include "../core.h"

void SetupLuaClassGC_OP_LockToBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LockToBone>("C_OP_LockToBone")
        .addProperty("ModelInput", &GC_OP_LockToBone::GetModelInput, &GC_OP_LockToBone::SetModelInput)
        .addProperty("TransformInput", &GC_OP_LockToBone::GetTransformInput, &GC_OP_LockToBone::SetTransformInput)
        .addProperty("LifeTimeFadeStart", &GC_OP_LockToBone::GetLifeTimeFadeStart, &GC_OP_LockToBone::SetLifeTimeFadeStart)
        .addProperty("LifeTimeFadeEnd", &GC_OP_LockToBone::GetLifeTimeFadeEnd, &GC_OP_LockToBone::SetLifeTimeFadeEnd)
        .addProperty("JumpThreshold", &GC_OP_LockToBone::GetJumpThreshold, &GC_OP_LockToBone::SetJumpThreshold)
        .addProperty("PrevPosScale", &GC_OP_LockToBone::GetPrevPosScale, &GC_OP_LockToBone::SetPrevPosScale)
        .addProperty("HitboxSetName", &GC_OP_LockToBone::GetHitboxSetName, &GC_OP_LockToBone::SetHitboxSetName)
        .addProperty("Rigid", &GC_OP_LockToBone::GetRigid, &GC_OP_LockToBone::SetRigid)
        .addProperty("UseBones", &GC_OP_LockToBone::GetUseBones, &GC_OP_LockToBone::SetUseBones)
        .addProperty("FieldOutput", &GC_OP_LockToBone::GetFieldOutput, &GC_OP_LockToBone::SetFieldOutput)
        .addProperty("FieldOutputPrev", &GC_OP_LockToBone::GetFieldOutputPrev, &GC_OP_LockToBone::SetFieldOutputPrev)
        .addProperty("RotationSetType", &GC_OP_LockToBone::GetRotationSetType, &GC_OP_LockToBone::SetRotationSetType)
        .addProperty("RigidRotationLock", &GC_OP_LockToBone::GetRigidRotationLock, &GC_OP_LockToBone::SetRigidRotationLock)
        .addProperty("Rotation", &GC_OP_LockToBone::GetRotation, &GC_OP_LockToBone::SetRotation)
        .addProperty("RotLerp", &GC_OP_LockToBone::GetRotLerp, &GC_OP_LockToBone::SetRotLerp)
        .endClass();
}