#include "../../../core/scripting/generated/classes/GCParticleFunctionForce.h"
#include "../core.h"

void SetupLuaClassGCParticleFunctionForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionForce>("CParticleFunctionForce")

        .endClass();
}