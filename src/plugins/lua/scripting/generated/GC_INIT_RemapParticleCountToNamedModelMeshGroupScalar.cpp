#include "../../../core/scripting/generated/classes/GC_INIT_RemapParticleCountToNamedModelMeshGroupScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapParticleCountToNamedModelMeshGroupScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapParticleCountToNamedModelMeshGroupScalar>("C_INIT_RemapParticleCountToNamedModelMeshGroupScalar")

        .endClass();
}