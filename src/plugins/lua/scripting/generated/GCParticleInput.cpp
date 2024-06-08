#include "../../../core/scripting/generated/classes/GCParticleInput.h"
#include "../core.h"

void SetupLuaClassGCParticleInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleInput>("CParticleInput")

        .endClass();
}