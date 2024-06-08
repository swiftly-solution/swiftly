#include "../../../core/scripting/generated/classes/GC_INIT_VelocityFromCP.h"
#include "../core.h"

void SetupLuaClassGC_INIT_VelocityFromCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_VelocityFromCP>("C_INIT_VelocityFromCP")
        .addProperty("TransformInput", &GC_INIT_VelocityFromCP::GetTransformInput, &GC_INIT_VelocityFromCP::SetTransformInput)
        .addProperty("VelocityScale", &GC_INIT_VelocityFromCP::GetVelocityScale, &GC_INIT_VelocityFromCP::SetVelocityScale)
        .addProperty("DirectionOnly", &GC_INIT_VelocityFromCP::GetDirectionOnly, &GC_INIT_VelocityFromCP::SetDirectionOnly)
        .endClass();
}