#include "../../../core/scripting/generated/classes/GC_OP_SetCPtoVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetCPtoVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetCPtoVector>("C_OP_SetCPtoVector")
        .addProperty("CPInput", &GC_OP_SetCPtoVector::GetCPInput, &GC_OP_SetCPtoVector::SetCPInput)
        .addProperty("FieldOutput", &GC_OP_SetCPtoVector::GetFieldOutput, &GC_OP_SetCPtoVector::SetFieldOutput)
        .endClass();
}