#include "../../../core/scripting/generated/classes/GCParticleFunctionConstraint.h"
#include "../core.h"

void SetupLuaClassGCParticleFunctionConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionConstraint>("CParticleFunctionConstraint")

        .endClass();
}