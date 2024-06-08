#include "../../../core/scripting/generated/classes/GC_INIT_RemapNamedModelElementToScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapNamedModelElementToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapNamedModelElementToScalar>("C_INIT_RemapNamedModelElementToScalar")
        .addProperty("Names", &GC_INIT_RemapNamedModelElementToScalar::GetNames, &GC_INIT_RemapNamedModelElementToScalar::SetNames)
        .addProperty("Values", &GC_INIT_RemapNamedModelElementToScalar::GetValues, &GC_INIT_RemapNamedModelElementToScalar::SetValues)
        .addProperty("FieldInput", &GC_INIT_RemapNamedModelElementToScalar::GetFieldInput, &GC_INIT_RemapNamedModelElementToScalar::SetFieldInput)
        .addProperty("FieldOutput", &GC_INIT_RemapNamedModelElementToScalar::GetFieldOutput, &GC_INIT_RemapNamedModelElementToScalar::SetFieldOutput)
        .addProperty("SetMethod", &GC_INIT_RemapNamedModelElementToScalar::GetSetMethod, &GC_INIT_RemapNamedModelElementToScalar::SetSetMethod)
        .addProperty("ModelFromRenderer", &GC_INIT_RemapNamedModelElementToScalar::GetModelFromRenderer, &GC_INIT_RemapNamedModelElementToScalar::SetModelFromRenderer)
        .endClass();
}