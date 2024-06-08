#include "../../../core/scripting/generated/classes/GC_INIT_CreateFromParentParticles.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateFromParentParticles(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateFromParentParticles>("C_INIT_CreateFromParentParticles")
        .addProperty("VelocityScale", &GC_INIT_CreateFromParentParticles::GetVelocityScale, &GC_INIT_CreateFromParentParticles::SetVelocityScale)
        .addProperty("Increment", &GC_INIT_CreateFromParentParticles::GetIncrement, &GC_INIT_CreateFromParentParticles::SetIncrement)
        .addProperty("RandomDistribution", &GC_INIT_CreateFromParentParticles::GetRandomDistribution, &GC_INIT_CreateFromParentParticles::SetRandomDistribution)
        .addProperty("RandomSeed", &GC_INIT_CreateFromParentParticles::GetRandomSeed, &GC_INIT_CreateFromParentParticles::SetRandomSeed)
        .addProperty("SubFrame", &GC_INIT_CreateFromParentParticles::GetSubFrame, &GC_INIT_CreateFromParentParticles::SetSubFrame)
        .endClass();
}