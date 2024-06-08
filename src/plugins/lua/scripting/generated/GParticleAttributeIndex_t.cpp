#include "../../../core/scripting/generated/classes/GParticleAttributeIndex_t.h"
#include "../core.h"

void SetupLuaClassGParticleAttributeIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleAttributeIndex_t>("ParticleAttributeIndex_t")
        .addProperty("Value", &GParticleAttributeIndex_t::GetValue, &GParticleAttributeIndex_t::SetValue)
        .endClass();
}