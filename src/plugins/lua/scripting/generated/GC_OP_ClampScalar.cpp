#include "../../../core/scripting/generated/classes/GC_OP_ClampScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_ClampScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ClampScalar>("C_OP_ClampScalar")
        .addProperty("FieldOutput", &GC_OP_ClampScalar::GetFieldOutput, &GC_OP_ClampScalar::SetFieldOutput)
        .addProperty("OutputMin", &GC_OP_ClampScalar::GetOutputMin, &GC_OP_ClampScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_ClampScalar::GetOutputMax, &GC_OP_ClampScalar::SetOutputMax)
        .endClass();
}