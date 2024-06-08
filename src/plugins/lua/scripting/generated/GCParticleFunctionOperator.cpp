#include "../../../core/scripting/generated/classes/GCParticleFunctionOperator.h"
#include "../core.h"

void SetupLuaClassGCParticleFunctionOperator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionOperator>("CParticleFunctionOperator")

        .endClass();
}