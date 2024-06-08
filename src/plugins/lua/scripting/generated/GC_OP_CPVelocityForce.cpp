#include "../../../core/scripting/generated/classes/GC_OP_CPVelocityForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_CPVelocityForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_CPVelocityForce>("C_OP_CPVelocityForce")
        .addProperty("ControlPointNumber", &GC_OP_CPVelocityForce::GetControlPointNumber, &GC_OP_CPVelocityForce::SetControlPointNumber)
        .addProperty("Scale", &GC_OP_CPVelocityForce::GetScale, &GC_OP_CPVelocityForce::SetScale)
        .endClass();
}