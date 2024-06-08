#include "../../../core/scripting/generated/classes/GC_OP_ExternalGameImpulseForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_ExternalGameImpulseForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ExternalGameImpulseForce>("C_OP_ExternalGameImpulseForce")
        .addProperty("ForceScale", &GC_OP_ExternalGameImpulseForce::GetForceScale, &GC_OP_ExternalGameImpulseForce::SetForceScale)
        .addProperty("Ropes", &GC_OP_ExternalGameImpulseForce::GetRopes, &GC_OP_ExternalGameImpulseForce::SetRopes)
        .addProperty("RopesZOnly", &GC_OP_ExternalGameImpulseForce::GetRopesZOnly, &GC_OP_ExternalGameImpulseForce::SetRopesZOnly)
        .addProperty("Explosions", &GC_OP_ExternalGameImpulseForce::GetExplosions, &GC_OP_ExternalGameImpulseForce::SetExplosions)
        .addProperty("Particles", &GC_OP_ExternalGameImpulseForce::GetParticles, &GC_OP_ExternalGameImpulseForce::SetParticles)
        .endClass();
}