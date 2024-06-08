#include "../../../core/scripting/generated/classes/GC_OP_RemapVectorComponentToScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapVectorComponentToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapVectorComponentToScalar>("C_OP_RemapVectorComponentToScalar")
        .addProperty("FieldInput", &GC_OP_RemapVectorComponentToScalar::GetFieldInput, &GC_OP_RemapVectorComponentToScalar::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_RemapVectorComponentToScalar::GetFieldOutput, &GC_OP_RemapVectorComponentToScalar::SetFieldOutput)
        .addProperty("Component", &GC_OP_RemapVectorComponentToScalar::GetComponent, &GC_OP_RemapVectorComponentToScalar::SetComponent)
        .endClass();
}