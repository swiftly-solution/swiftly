#include "../../../core/scripting/generated/classes/GC_OP_SnapshotSkinToBones.h"
#include "../core.h"

void SetupLuaClassGC_OP_SnapshotSkinToBones(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SnapshotSkinToBones>("C_OP_SnapshotSkinToBones")
        .addProperty("TransformNormals", &GC_OP_SnapshotSkinToBones::GetTransformNormals, &GC_OP_SnapshotSkinToBones::SetTransformNormals)
        .addProperty("TransformRadii", &GC_OP_SnapshotSkinToBones::GetTransformRadii, &GC_OP_SnapshotSkinToBones::SetTransformRadii)
        .addProperty("ControlPointNumber", &GC_OP_SnapshotSkinToBones::GetControlPointNumber, &GC_OP_SnapshotSkinToBones::SetControlPointNumber)
        .addProperty("LifeTimeFadeStart", &GC_OP_SnapshotSkinToBones::GetLifeTimeFadeStart, &GC_OP_SnapshotSkinToBones::SetLifeTimeFadeStart)
        .addProperty("LifeTimeFadeEnd", &GC_OP_SnapshotSkinToBones::GetLifeTimeFadeEnd, &GC_OP_SnapshotSkinToBones::SetLifeTimeFadeEnd)
        .addProperty("JumpThreshold", &GC_OP_SnapshotSkinToBones::GetJumpThreshold, &GC_OP_SnapshotSkinToBones::SetJumpThreshold)
        .addProperty("PrevPosScale", &GC_OP_SnapshotSkinToBones::GetPrevPosScale, &GC_OP_SnapshotSkinToBones::SetPrevPosScale)
        .endClass();
}