#include "../../../core/scripting/generated/classes/GCParticleRemapFloatInput.h"
#include "../core.h"

void SetupLuaClassGCParticleRemapFloatInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleRemapFloatInput>("CParticleRemapFloatInput")

        .endClass();
}