#include "../../../core/scripting/generated/classes/GC_OP_LerpEndCapVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_LerpEndCapVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LerpEndCapVector>("C_OP_LerpEndCapVector")
        .addProperty("FieldOutput", &GC_OP_LerpEndCapVector::GetFieldOutput, &GC_OP_LerpEndCapVector::SetFieldOutput)
        .addProperty("Output", &GC_OP_LerpEndCapVector::GetOutput, &GC_OP_LerpEndCapVector::SetOutput)
        .addProperty("LerpTime", &GC_OP_LerpEndCapVector::GetLerpTime, &GC_OP_LerpEndCapVector::SetLerpTime)
        .endClass();
}