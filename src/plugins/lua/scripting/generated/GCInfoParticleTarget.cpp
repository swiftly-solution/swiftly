#include "../../../core/scripting/generated/classes/GCInfoParticleTarget.h"
#include "../core.h"

void SetupLuaClassGCInfoParticleTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoParticleTarget>("CInfoParticleTarget")

        .endClass();
}