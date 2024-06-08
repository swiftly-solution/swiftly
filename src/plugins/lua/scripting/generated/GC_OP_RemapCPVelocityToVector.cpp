#include "../../../core/scripting/generated/classes/GC_OP_RemapCPVelocityToVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapCPVelocityToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapCPVelocityToVector>("C_OP_RemapCPVelocityToVector")
        .addProperty("ControlPoint", &GC_OP_RemapCPVelocityToVector::GetControlPoint, &GC_OP_RemapCPVelocityToVector::SetControlPoint)
        .addProperty("FieldOutput", &GC_OP_RemapCPVelocityToVector::GetFieldOutput, &GC_OP_RemapCPVelocityToVector::SetFieldOutput)
        .addProperty("Scale", &GC_OP_RemapCPVelocityToVector::GetScale, &GC_OP_RemapCPVelocityToVector::SetScale)
        .addProperty("Normalize", &GC_OP_RemapCPVelocityToVector::GetNormalize, &GC_OP_RemapCPVelocityToVector::SetNormalize)
        .endClass();
}