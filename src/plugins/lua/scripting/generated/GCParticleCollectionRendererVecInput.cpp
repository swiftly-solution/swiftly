#include "../../../core/scripting/generated/classes/GCParticleCollectionRendererVecInput.h"
#include "../core.h"

void SetupLuaClassGCParticleCollectionRendererVecInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleCollectionRendererVecInput>("CParticleCollectionRendererVecInput")

        .endClass();
}