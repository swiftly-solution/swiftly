#include "../../../core/scripting/generated/classes/GC_OP_ClampVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_ClampVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ClampVector>("C_OP_ClampVector")
        .addProperty("FieldOutput", &GC_OP_ClampVector::GetFieldOutput, &GC_OP_ClampVector::SetFieldOutput)
        .addProperty("OutputMin", &GC_OP_ClampVector::GetOutputMin, &GC_OP_ClampVector::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_ClampVector::GetOutputMax, &GC_OP_ClampVector::SetOutputMax)
        .endClass();
}