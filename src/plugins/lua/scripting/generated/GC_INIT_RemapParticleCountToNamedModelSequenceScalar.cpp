#include "../../../core/scripting/generated/classes/GC_INIT_RemapParticleCountToNamedModelSequenceScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapParticleCountToNamedModelSequenceScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapParticleCountToNamedModelSequenceScalar>("C_INIT_RemapParticleCountToNamedModelSequenceScalar")

        .endClass();
}