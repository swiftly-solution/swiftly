#include "../../../core/scripting/generated/classes/GCParticleProperty.h"
#include "../core.h"

void SetupLuaClassGCParticleProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleProperty>("CParticleProperty")

        .endClass();
}