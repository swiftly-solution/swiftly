#include "../../../core/scripting/generated/classes/GC_OP_LerpScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_LerpScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LerpScalar>("C_OP_LerpScalar")
        .addProperty("FieldOutput", &GC_OP_LerpScalar::GetFieldOutput, &GC_OP_LerpScalar::SetFieldOutput)
        .addProperty("Output", &GC_OP_LerpScalar::GetOutput, &GC_OP_LerpScalar::SetOutput)
        .addProperty("StartTime", &GC_OP_LerpScalar::GetStartTime, &GC_OP_LerpScalar::SetStartTime)
        .addProperty("EndTime", &GC_OP_LerpScalar::GetEndTime, &GC_OP_LerpScalar::SetEndTime)
        .endClass();
}