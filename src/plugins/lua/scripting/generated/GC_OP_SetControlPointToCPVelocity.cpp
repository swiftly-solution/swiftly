#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointToCPVelocity.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointToCPVelocity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointToCPVelocity>("C_OP_SetControlPointToCPVelocity")
        .addProperty("CPInput", &GC_OP_SetControlPointToCPVelocity::GetCPInput, &GC_OP_SetControlPointToCPVelocity::SetCPInput)
        .addProperty("CPOutputVel", &GC_OP_SetControlPointToCPVelocity::GetCPOutputVel, &GC_OP_SetControlPointToCPVelocity::SetCPOutputVel)
        .addProperty("Normalize", &GC_OP_SetControlPointToCPVelocity::GetNormalize, &GC_OP_SetControlPointToCPVelocity::SetNormalize)
        .addProperty("CPOutputMag", &GC_OP_SetControlPointToCPVelocity::GetCPOutputMag, &GC_OP_SetControlPointToCPVelocity::SetCPOutputMag)
        .addProperty("CPField", &GC_OP_SetControlPointToCPVelocity::GetCPField, &GC_OP_SetControlPointToCPVelocity::SetCPField)
        .endClass();
}