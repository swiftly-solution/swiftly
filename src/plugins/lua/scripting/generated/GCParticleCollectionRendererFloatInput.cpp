#include "../../../core/scripting/generated/classes/GCParticleCollectionRendererFloatInput.h"
#include "../core.h"

void SetupLuaClassGCParticleCollectionRendererFloatInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleCollectionRendererFloatInput>("CParticleCollectionRendererFloatInput")

        .endClass();
}