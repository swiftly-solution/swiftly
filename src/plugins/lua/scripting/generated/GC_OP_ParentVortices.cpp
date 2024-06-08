#include "../../../core/scripting/generated/classes/GC_OP_ParentVortices.h"
#include "../core.h"

void SetupLuaClassGC_OP_ParentVortices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ParentVortices>("C_OP_ParentVortices")
        .addProperty("ForceScale", &GC_OP_ParentVortices::GetForceScale, &GC_OP_ParentVortices::SetForceScale)
        .addProperty("TwistAxis", &GC_OP_ParentVortices::GetTwistAxis, &GC_OP_ParentVortices::SetTwistAxis)
        .addProperty("FlipBasedOnYaw", &GC_OP_ParentVortices::GetFlipBasedOnYaw, &GC_OP_ParentVortices::SetFlipBasedOnYaw)
        .endClass();
}