#include "../../../core/scripting/generated/classes/GC_INIT_RemapParticleCountToNamedModelBodyPartScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapParticleCountToNamedModelBodyPartScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapParticleCountToNamedModelBodyPartScalar>("C_INIT_RemapParticleCountToNamedModelBodyPartScalar")

        .endClass();
}