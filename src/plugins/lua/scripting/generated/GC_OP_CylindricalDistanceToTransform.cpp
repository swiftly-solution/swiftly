#include "../../../core/scripting/generated/classes/GC_OP_CylindricalDistanceToTransform.h"
#include "../core.h"

void SetupLuaClassGC_OP_CylindricalDistanceToTransform(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_CylindricalDistanceToTransform>("C_OP_CylindricalDistanceToTransform")
        .addProperty("FieldOutput", &GC_OP_CylindricalDistanceToTransform::GetFieldOutput, &GC_OP_CylindricalDistanceToTransform::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_CylindricalDistanceToTransform::GetInputMin, &GC_OP_CylindricalDistanceToTransform::SetInputMin)
        .addProperty("InputMax", &GC_OP_CylindricalDistanceToTransform::GetInputMax, &GC_OP_CylindricalDistanceToTransform::SetInputMax)
        .addProperty("OutputMin", &GC_OP_CylindricalDistanceToTransform::GetOutputMin, &GC_OP_CylindricalDistanceToTransform::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_CylindricalDistanceToTransform::GetOutputMax, &GC_OP_CylindricalDistanceToTransform::SetOutputMax)
        .addProperty("TransformStart", &GC_OP_CylindricalDistanceToTransform::GetTransformStart, &GC_OP_CylindricalDistanceToTransform::SetTransformStart)
        .addProperty("TransformEnd", &GC_OP_CylindricalDistanceToTransform::GetTransformEnd, &GC_OP_CylindricalDistanceToTransform::SetTransformEnd)
        .addProperty("SetMethod", &GC_OP_CylindricalDistanceToTransform::GetSetMethod, &GC_OP_CylindricalDistanceToTransform::SetSetMethod)
        .addProperty("ActiveRange", &GC_OP_CylindricalDistanceToTransform::GetActiveRange, &GC_OP_CylindricalDistanceToTransform::SetActiveRange)
        .addProperty("Additive", &GC_OP_CylindricalDistanceToTransform::GetAdditive, &GC_OP_CylindricalDistanceToTransform::SetAdditive)
        .addProperty("Capsule", &GC_OP_CylindricalDistanceToTransform::GetCapsule, &GC_OP_CylindricalDistanceToTransform::SetCapsule)
        .endClass();
}