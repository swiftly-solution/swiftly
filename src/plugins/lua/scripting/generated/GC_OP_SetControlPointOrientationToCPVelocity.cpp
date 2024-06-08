#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointOrientationToCPVelocity.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointOrientationToCPVelocity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointOrientationToCPVelocity>("C_OP_SetControlPointOrientationToCPVelocity")
        .addProperty("CPInput", &GC_OP_SetControlPointOrientationToCPVelocity::GetCPInput, &GC_OP_SetControlPointOrientationToCPVelocity::SetCPInput)
        .addProperty("CPOutput", &GC_OP_SetControlPointOrientationToCPVelocity::GetCPOutput, &GC_OP_SetControlPointOrientationToCPVelocity::SetCPOutput)
        .endClass();
}