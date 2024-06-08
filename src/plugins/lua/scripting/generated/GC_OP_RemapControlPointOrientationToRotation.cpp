#include "../../../core/scripting/generated/classes/GC_OP_RemapControlPointOrientationToRotation.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapControlPointOrientationToRotation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapControlPointOrientationToRotation>("C_OP_RemapControlPointOrientationToRotation")
        .addProperty("CP", &GC_OP_RemapControlPointOrientationToRotation::GetCP, &GC_OP_RemapControlPointOrientationToRotation::SetCP)
        .addProperty("FieldOutput", &GC_OP_RemapControlPointOrientationToRotation::GetFieldOutput, &GC_OP_RemapControlPointOrientationToRotation::SetFieldOutput)
        .addProperty("OffsetRot", &GC_OP_RemapControlPointOrientationToRotation::GetOffsetRot, &GC_OP_RemapControlPointOrientationToRotation::SetOffsetRot)
        .addProperty("Component", &GC_OP_RemapControlPointOrientationToRotation::GetComponent, &GC_OP_RemapControlPointOrientationToRotation::SetComponent)
        .endClass();
}