#include "../../../core/scripting/generated/classes/GC_OP_RemapControlPointDirectionToVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapControlPointDirectionToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapControlPointDirectionToVector>("C_OP_RemapControlPointDirectionToVector")
        .addProperty("FieldOutput", &GC_OP_RemapControlPointDirectionToVector::GetFieldOutput, &GC_OP_RemapControlPointDirectionToVector::SetFieldOutput)
        .addProperty("Scale", &GC_OP_RemapControlPointDirectionToVector::GetScale, &GC_OP_RemapControlPointDirectionToVector::SetScale)
        .addProperty("ControlPointNumber", &GC_OP_RemapControlPointDirectionToVector::GetControlPointNumber, &GC_OP_RemapControlPointDirectionToVector::SetControlPointNumber)
        .endClass();
}