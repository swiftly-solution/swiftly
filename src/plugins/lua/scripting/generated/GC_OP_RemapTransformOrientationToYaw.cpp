#include "../../../core/scripting/generated/classes/GC_OP_RemapTransformOrientationToYaw.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapTransformOrientationToYaw(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapTransformOrientationToYaw>("C_OP_RemapTransformOrientationToYaw")
        .addProperty("TransformInput", &GC_OP_RemapTransformOrientationToYaw::GetTransformInput, &GC_OP_RemapTransformOrientationToYaw::SetTransformInput)
        .addProperty("FieldOutput", &GC_OP_RemapTransformOrientationToYaw::GetFieldOutput, &GC_OP_RemapTransformOrientationToYaw::SetFieldOutput)
        .addProperty("RotOffset", &GC_OP_RemapTransformOrientationToYaw::GetRotOffset, &GC_OP_RemapTransformOrientationToYaw::SetRotOffset)
        .addProperty("SpinStrength", &GC_OP_RemapTransformOrientationToYaw::GetSpinStrength, &GC_OP_RemapTransformOrientationToYaw::SetSpinStrength)
        .endClass();
}