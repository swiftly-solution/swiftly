#include "../../../core/scripting/generated/classes/GC_INIT_RemapInitialTransformDirectionToRotation.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapInitialTransformDirectionToRotation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapInitialTransformDirectionToRotation>("C_INIT_RemapInitialTransformDirectionToRotation")
        .addProperty("TransformInput", &GC_INIT_RemapInitialTransformDirectionToRotation::GetTransformInput, &GC_INIT_RemapInitialTransformDirectionToRotation::SetTransformInput)
        .addProperty("FieldOutput", &GC_INIT_RemapInitialTransformDirectionToRotation::GetFieldOutput, &GC_INIT_RemapInitialTransformDirectionToRotation::SetFieldOutput)
        .addProperty("OffsetRot", &GC_INIT_RemapInitialTransformDirectionToRotation::GetOffsetRot, &GC_INIT_RemapInitialTransformDirectionToRotation::SetOffsetRot)
        .addProperty("Component", &GC_INIT_RemapInitialTransformDirectionToRotation::GetComponent, &GC_INIT_RemapInitialTransformDirectionToRotation::SetComponent)
        .endClass();
}