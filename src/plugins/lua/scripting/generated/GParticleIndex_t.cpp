#include "../../../core/scripting/generated/classes/GParticleIndex_t.h"
#include "../core.h"

void SetupLuaClassGParticleIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleIndex_t>("ParticleIndex_t")
        .addProperty("Value", &GParticleIndex_t::GetValue, &GParticleIndex_t::SetValue)
        .endClass();
}