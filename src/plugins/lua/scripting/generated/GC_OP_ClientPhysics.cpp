#include "../../../core/scripting/generated/classes/GC_OP_ClientPhysics.h"
#include "../core.h"

void SetupLuaClassGC_OP_ClientPhysics(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ClientPhysics>("C_OP_ClientPhysics")
        .addProperty("StrPhysicsType", &GC_OP_ClientPhysics::GetStrPhysicsType, &GC_OP_ClientPhysics::SetStrPhysicsType)
        .addProperty("KillParticles", &GC_OP_ClientPhysics::GetKillParticles, &GC_OP_ClientPhysics::SetKillParticles)
        .addProperty("DeleteSim", &GC_OP_ClientPhysics::GetDeleteSim, &GC_OP_ClientPhysics::SetDeleteSim)
        .addProperty("ControlPoint", &GC_OP_ClientPhysics::GetControlPoint, &GC_OP_ClientPhysics::SetControlPoint)
        .addProperty("ColorBlendType", &GC_OP_ClientPhysics::GetColorBlendType, &GC_OP_ClientPhysics::SetColorBlendType)
        .endClass();
}