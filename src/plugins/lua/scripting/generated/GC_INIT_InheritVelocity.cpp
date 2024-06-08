#include "../../../core/scripting/generated/classes/GC_INIT_InheritVelocity.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InheritVelocity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InheritVelocity>("C_INIT_InheritVelocity")
        .addProperty("ControlPointNumber", &GC_INIT_InheritVelocity::GetControlPointNumber, &GC_INIT_InheritVelocity::SetControlPointNumber)
        .addProperty("VelocityScale", &GC_INIT_InheritVelocity::GetVelocityScale, &GC_INIT_InheritVelocity::SetVelocityScale)
        .endClass();
}