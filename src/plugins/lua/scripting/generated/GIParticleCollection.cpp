#include "../../../core/scripting/generated/classes/GIParticleCollection.h"
#include "../core.h"

void SetupLuaClassGIParticleCollection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIParticleCollection>("IParticleCollection")

        .endClass();
}