#include "../../../core/scripting/generated/classes/GCParticleCollectionFloatInput.h"
#include "../core.h"

void SetupLuaClassGCParticleCollectionFloatInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleCollectionFloatInput>("CParticleCollectionFloatInput")

        .endClass();
}