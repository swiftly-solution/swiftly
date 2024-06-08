#include "../../../core/scripting/generated/classes/GC_OP_MoveToHitbox.h"
#include "../core.h"

void SetupLuaClassGC_OP_MoveToHitbox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MoveToHitbox>("C_OP_MoveToHitbox")
        .addProperty("ModelInput", &GC_OP_MoveToHitbox::GetModelInput, &GC_OP_MoveToHitbox::SetModelInput)
        .addProperty("TransformInput", &GC_OP_MoveToHitbox::GetTransformInput, &GC_OP_MoveToHitbox::SetTransformInput)
        .addProperty("LifeTimeLerpStart", &GC_OP_MoveToHitbox::GetLifeTimeLerpStart, &GC_OP_MoveToHitbox::SetLifeTimeLerpStart)
        .addProperty("LifeTimeLerpEnd", &GC_OP_MoveToHitbox::GetLifeTimeLerpEnd, &GC_OP_MoveToHitbox::SetLifeTimeLerpEnd)
        .addProperty("PrevPosScale", &GC_OP_MoveToHitbox::GetPrevPosScale, &GC_OP_MoveToHitbox::SetPrevPosScale)
        .addProperty("HitboxSetName", &GC_OP_MoveToHitbox::GetHitboxSetName, &GC_OP_MoveToHitbox::SetHitboxSetName)
        .addProperty("UseBones", &GC_OP_MoveToHitbox::GetUseBones, &GC_OP_MoveToHitbox::SetUseBones)
        .addProperty("LerpType", &GC_OP_MoveToHitbox::GetLerpType, &GC_OP_MoveToHitbox::SetLerpType)
        .addProperty("Interpolation", &GC_OP_MoveToHitbox::GetInterpolation, &GC_OP_MoveToHitbox::SetInterpolation)
        .endClass();
}