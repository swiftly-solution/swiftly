#include "../../../core/scripting/generated/classes/GCPathParticleRopeAlias_path_particle_rope_clientside.h"
#include "../core.h"

void SetupLuaClassGCPathParticleRopeAlias_path_particle_rope_clientside(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathParticleRopeAlias_path_particle_rope_clientside>("CPathParticleRopeAlias_path_particle_rope_clientside")

        .endClass();
}