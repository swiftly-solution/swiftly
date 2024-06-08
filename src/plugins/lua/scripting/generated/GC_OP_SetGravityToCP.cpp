#include "../../../core/scripting/generated/classes/GC_OP_SetGravityToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetGravityToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetGravityToCP>("C_OP_SetGravityToCP")
        .addProperty("CPInput", &GC_OP_SetGravityToCP::GetCPInput, &GC_OP_SetGravityToCP::SetCPInput)
        .addProperty("CPOutput", &GC_OP_SetGravityToCP::GetCPOutput, &GC_OP_SetGravityToCP::SetCPOutput)
        .addProperty("Scale", &GC_OP_SetGravityToCP::GetScale, &GC_OP_SetGravityToCP::SetScale)
        .addProperty("SetOrientation", &GC_OP_SetGravityToCP::GetSetOrientation, &GC_OP_SetGravityToCP::SetSetOrientation)
        .addProperty("SetZDown", &GC_OP_SetGravityToCP::GetSetZDown, &GC_OP_SetGravityToCP::SetSetZDown)
        .endClass();
}