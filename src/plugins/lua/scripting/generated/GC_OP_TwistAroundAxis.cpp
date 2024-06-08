#include "../../../core/scripting/generated/classes/GC_OP_TwistAroundAxis.h"
#include "../core.h"

void SetupLuaClassGC_OP_TwistAroundAxis(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_TwistAroundAxis>("C_OP_TwistAroundAxis")
        .addProperty("ForceAmount", &GC_OP_TwistAroundAxis::GetForceAmount, &GC_OP_TwistAroundAxis::SetForceAmount)
        .addProperty("TwistAxis", &GC_OP_TwistAroundAxis::GetTwistAxis, &GC_OP_TwistAroundAxis::SetTwistAxis)
        .addProperty("LocalSpace", &GC_OP_TwistAroundAxis::GetLocalSpace, &GC_OP_TwistAroundAxis::SetLocalSpace)
        .addProperty("ControlPointNumber", &GC_OP_TwistAroundAxis::GetControlPointNumber, &GC_OP_TwistAroundAxis::SetControlPointNumber)
        .endClass();
}