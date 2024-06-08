#include "../../../core/scripting/generated/classes/GC_OP_VelocityMatchingForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_VelocityMatchingForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_VelocityMatchingForce>("C_OP_VelocityMatchingForce")
        .addProperty("DirScale", &GC_OP_VelocityMatchingForce::GetDirScale, &GC_OP_VelocityMatchingForce::SetDirScale)
        .addProperty("SpdScale", &GC_OP_VelocityMatchingForce::GetSpdScale, &GC_OP_VelocityMatchingForce::SetSpdScale)
        .addProperty("CPBroadcast", &GC_OP_VelocityMatchingForce::GetCPBroadcast, &GC_OP_VelocityMatchingForce::SetCPBroadcast)
        .endClass();
}