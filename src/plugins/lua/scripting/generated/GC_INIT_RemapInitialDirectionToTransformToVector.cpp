#include "../../../core/scripting/generated/classes/GC_INIT_RemapInitialDirectionToTransformToVector.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapInitialDirectionToTransformToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapInitialDirectionToTransformToVector>("C_INIT_RemapInitialDirectionToTransformToVector")
        .addProperty("TransformInput", &GC_INIT_RemapInitialDirectionToTransformToVector::GetTransformInput, &GC_INIT_RemapInitialDirectionToTransformToVector::SetTransformInput)
        .addProperty("FieldOutput", &GC_INIT_RemapInitialDirectionToTransformToVector::GetFieldOutput, &GC_INIT_RemapInitialDirectionToTransformToVector::SetFieldOutput)
        .addProperty("Scale", &GC_INIT_RemapInitialDirectionToTransformToVector::GetScale, &GC_INIT_RemapInitialDirectionToTransformToVector::SetScale)
        .addProperty("OffsetRot", &GC_INIT_RemapInitialDirectionToTransformToVector::GetOffsetRot, &GC_INIT_RemapInitialDirectionToTransformToVector::SetOffsetRot)
        .addProperty("OffsetAxis", &GC_INIT_RemapInitialDirectionToTransformToVector::GetOffsetAxis, &GC_INIT_RemapInitialDirectionToTransformToVector::SetOffsetAxis)
        .addProperty("Normalize", &GC_INIT_RemapInitialDirectionToTransformToVector::GetNormalize, &GC_INIT_RemapInitialDirectionToTransformToVector::SetNormalize)
        .endClass();
}