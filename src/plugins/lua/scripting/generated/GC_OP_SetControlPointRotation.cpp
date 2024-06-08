#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointRotation.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointRotation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointRotation>("C_OP_SetControlPointRotation")
        .addProperty("RotRate", &GC_OP_SetControlPointRotation::GetRotRate, &GC_OP_SetControlPointRotation::SetRotRate)
        .addProperty("CP", &GC_OP_SetControlPointRotation::GetCP, &GC_OP_SetControlPointRotation::SetCP)
        .addProperty("LocalCP", &GC_OP_SetControlPointRotation::GetLocalCP, &GC_OP_SetControlPointRotation::SetLocalCP)
        .endClass();
}