#include "../../../core/scripting/generated/classes/GPhysSoftbodyDesc_t.h"
#include "../core.h"

void SetupLuaClassGPhysSoftbodyDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPhysSoftbodyDesc_t>("PhysSoftbodyDesc_t")
        .addProperty("ParticleBoneHash", &GPhysSoftbodyDesc_t::GetParticleBoneHash, &GPhysSoftbodyDesc_t::SetParticleBoneHash)
        .addProperty("Particles", &GPhysSoftbodyDesc_t::GetParticles, &GPhysSoftbodyDesc_t::SetParticles)
        .addProperty("Springs", &GPhysSoftbodyDesc_t::GetSprings, &GPhysSoftbodyDesc_t::SetSprings)
        .addProperty("Capsules", &GPhysSoftbodyDesc_t::GetCapsules, &GPhysSoftbodyDesc_t::SetCapsules)
        .addProperty("ParticleBoneName", &GPhysSoftbodyDesc_t::GetParticleBoneName, &GPhysSoftbodyDesc_t::SetParticleBoneName)
        .endClass();
}