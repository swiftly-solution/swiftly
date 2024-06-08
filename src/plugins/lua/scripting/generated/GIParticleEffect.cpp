#include "../../../core/scripting/generated/classes/GIParticleEffect.h"
#include "../core.h"

void SetupLuaClassGIParticleEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIParticleEffect>("IParticleEffect")

        .endClass();
}