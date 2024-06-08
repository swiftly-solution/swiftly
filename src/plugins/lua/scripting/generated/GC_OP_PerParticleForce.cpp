#include "../../../core/scripting/generated/classes/GC_OP_PerParticleForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_PerParticleForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PerParticleForce>("C_OP_PerParticleForce")
        .addProperty("ForceScale", &GC_OP_PerParticleForce::GetForceScale, &GC_OP_PerParticleForce::SetForceScale)
        .addProperty("Force", &GC_OP_PerParticleForce::GetForce, &GC_OP_PerParticleForce::SetForce)
        .addProperty("CP", &GC_OP_PerParticleForce::GetCP, &GC_OP_PerParticleForce::SetCP)
        .endClass();
}