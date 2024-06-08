#include "../../../core/scripting/generated/classes/GParticleChildrenInfo_t.h"
#include "../core.h"

void SetupLuaClassGParticleChildrenInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleChildrenInfo_t>("ParticleChildrenInfo_t")
        .addProperty("Delay", &GParticleChildrenInfo_t::GetDelay, &GParticleChildrenInfo_t::SetDelay)
        .addProperty("EndCap", &GParticleChildrenInfo_t::GetEndCap, &GParticleChildrenInfo_t::SetEndCap)
        .addProperty("DisableChild", &GParticleChildrenInfo_t::GetDisableChild, &GParticleChildrenInfo_t::SetDisableChild)
        .addProperty("DetailLevel", &GParticleChildrenInfo_t::GetDetailLevel, &GParticleChildrenInfo_t::SetDetailLevel)
        .endClass();
}