#include "../../../core/scripting/generated/classes/GC_OP_LerpEndCapScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_LerpEndCapScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LerpEndCapScalar>("C_OP_LerpEndCapScalar")
        .addProperty("FieldOutput", &GC_OP_LerpEndCapScalar::GetFieldOutput, &GC_OP_LerpEndCapScalar::SetFieldOutput)
        .addProperty("Output", &GC_OP_LerpEndCapScalar::GetOutput, &GC_OP_LerpEndCapScalar::SetOutput)
        .addProperty("LerpTime", &GC_OP_LerpEndCapScalar::GetLerpTime, &GC_OP_LerpEndCapScalar::SetLerpTime)
        .endClass();
}