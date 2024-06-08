#include "../../../core/scripting/generated/classes/GC_OP_RemapTransformOrientationToRotations.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapTransformOrientationToRotations(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapTransformOrientationToRotations>("C_OP_RemapTransformOrientationToRotations")
        .addProperty("TransformInput", &GC_OP_RemapTransformOrientationToRotations::GetTransformInput, &GC_OP_RemapTransformOrientationToRotations::SetTransformInput)
        .addProperty("Rotation", &GC_OP_RemapTransformOrientationToRotations::GetRotation, &GC_OP_RemapTransformOrientationToRotations::SetRotation)
        .addProperty("UseQuat", &GC_OP_RemapTransformOrientationToRotations::GetUseQuat, &GC_OP_RemapTransformOrientationToRotations::SetUseQuat)
        .addProperty("WriteNormal", &GC_OP_RemapTransformOrientationToRotations::GetWriteNormal, &GC_OP_RemapTransformOrientationToRotations::SetWriteNormal)
        .endClass();
}