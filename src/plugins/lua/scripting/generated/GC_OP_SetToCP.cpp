#include "../../../core/scripting/generated/classes/GC_OP_SetToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetToCP>("C_OP_SetToCP")
        .addProperty("ControlPointNumber", &GC_OP_SetToCP::GetControlPointNumber, &GC_OP_SetToCP::SetControlPointNumber)
        .addProperty("Offset", &GC_OP_SetToCP::GetOffset, &GC_OP_SetToCP::SetOffset)
        .addProperty("OffsetLocal", &GC_OP_SetToCP::GetOffsetLocal, &GC_OP_SetToCP::SetOffsetLocal)
        .endClass();
}