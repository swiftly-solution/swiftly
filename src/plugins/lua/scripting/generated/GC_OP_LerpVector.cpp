#include "../../../core/scripting/generated/classes/GC_OP_LerpVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_LerpVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LerpVector>("C_OP_LerpVector")
        .addProperty("FieldOutput", &GC_OP_LerpVector::GetFieldOutput, &GC_OP_LerpVector::SetFieldOutput)
        .addProperty("Output", &GC_OP_LerpVector::GetOutput, &GC_OP_LerpVector::SetOutput)
        .addProperty("StartTime", &GC_OP_LerpVector::GetStartTime, &GC_OP_LerpVector::SetStartTime)
        .addProperty("EndTime", &GC_OP_LerpVector::GetEndTime, &GC_OP_LerpVector::SetEndTime)
        .addProperty("SetMethod", &GC_OP_LerpVector::GetSetMethod, &GC_OP_LerpVector::SetSetMethod)
        .endClass();
}