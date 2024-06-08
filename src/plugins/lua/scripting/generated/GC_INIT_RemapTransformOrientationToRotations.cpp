#include "../../../core/scripting/generated/classes/GC_INIT_RemapTransformOrientationToRotations.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapTransformOrientationToRotations(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapTransformOrientationToRotations>("C_INIT_RemapTransformOrientationToRotations")
        .addProperty("TransformInput", &GC_INIT_RemapTransformOrientationToRotations::GetTransformInput, &GC_INIT_RemapTransformOrientationToRotations::SetTransformInput)
        .addProperty("Rotation", &GC_INIT_RemapTransformOrientationToRotations::GetRotation, &GC_INIT_RemapTransformOrientationToRotations::SetRotation)
        .addProperty("UseQuat", &GC_INIT_RemapTransformOrientationToRotations::GetUseQuat, &GC_INIT_RemapTransformOrientationToRotations::SetUseQuat)
        .addProperty("WriteNormal", &GC_INIT_RemapTransformOrientationToRotations::GetWriteNormal, &GC_INIT_RemapTransformOrientationToRotations::SetWriteNormal)
        .endClass();
}