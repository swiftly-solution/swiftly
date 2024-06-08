#include "../../../core/scripting/generated/classes/GCParticleCollectionBindingInstance.h"
#include "../core.h"

void SetupLuaClassGCParticleCollectionBindingInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleCollectionBindingInstance>("CParticleCollectionBindingInstance")

        .endClass();
}