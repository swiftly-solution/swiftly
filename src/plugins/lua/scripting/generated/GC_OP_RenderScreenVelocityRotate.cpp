#include "../../../core/scripting/generated/classes/GC_OP_RenderScreenVelocityRotate.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderScreenVelocityRotate(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderScreenVelocityRotate>("C_OP_RenderScreenVelocityRotate")
        .addProperty("RotateRateDegrees", &GC_OP_RenderScreenVelocityRotate::GetRotateRateDegrees, &GC_OP_RenderScreenVelocityRotate::SetRotateRateDegrees)
        .addProperty("ForwardDegrees", &GC_OP_RenderScreenVelocityRotate::GetForwardDegrees, &GC_OP_RenderScreenVelocityRotate::SetForwardDegrees)
        .endClass();
}