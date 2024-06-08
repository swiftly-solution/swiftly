#include "../../../core/scripting/generated/classes/GC_OP_DampenToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_DampenToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DampenToCP>("C_OP_DampenToCP")
        .addProperty("ControlPointNumber", &GC_OP_DampenToCP::GetControlPointNumber, &GC_OP_DampenToCP::SetControlPointNumber)
        .addProperty("Range", &GC_OP_DampenToCP::GetRange, &GC_OP_DampenToCP::SetRange)
        .addProperty("Scale", &GC_OP_DampenToCP::GetScale, &GC_OP_DampenToCP::SetScale)
        .endClass();
}