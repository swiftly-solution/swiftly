#include "../../../core/scripting/generated/classes/GC_INIT_RemapInitialVisibilityScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapInitialVisibilityScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapInitialVisibilityScalar>("C_INIT_RemapInitialVisibilityScalar")
        .addProperty("FieldOutput", &GC_INIT_RemapInitialVisibilityScalar::GetFieldOutput, &GC_INIT_RemapInitialVisibilityScalar::SetFieldOutput)
        .addProperty("InputMin", &GC_INIT_RemapInitialVisibilityScalar::GetInputMin, &GC_INIT_RemapInitialVisibilityScalar::SetInputMin)
        .addProperty("InputMax", &GC_INIT_RemapInitialVisibilityScalar::GetInputMax, &GC_INIT_RemapInitialVisibilityScalar::SetInputMax)
        .addProperty("OutputMin", &GC_INIT_RemapInitialVisibilityScalar::GetOutputMin, &GC_INIT_RemapInitialVisibilityScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_RemapInitialVisibilityScalar::GetOutputMax, &GC_INIT_RemapInitialVisibilityScalar::SetOutputMax)
        .endClass();
}