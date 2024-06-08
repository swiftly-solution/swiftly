#include "../../../core/scripting/generated/classes/GParticlePreviewBodyGroup_t.h"
#include "../core.h"

void SetupLuaClassGParticlePreviewBodyGroup_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticlePreviewBodyGroup_t>("ParticlePreviewBodyGroup_t")
        .addProperty("BodyGroupName", &GParticlePreviewBodyGroup_t::GetBodyGroupName, &GParticlePreviewBodyGroup_t::SetBodyGroupName)
        .addProperty("Value", &GParticlePreviewBodyGroup_t::GetValue, &GParticlePreviewBodyGroup_t::SetValue)
        .endClass();
}