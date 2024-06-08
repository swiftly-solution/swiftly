#include "../../../core/scripting/generated/classes/GC_INIT_RemapParticleCountToNamedModelElementScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapParticleCountToNamedModelElementScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapParticleCountToNamedModelElementScalar>("C_INIT_RemapParticleCountToNamedModelElementScalar")
        .addProperty("OutputMinName", &GC_INIT_RemapParticleCountToNamedModelElementScalar::GetOutputMinName, &GC_INIT_RemapParticleCountToNamedModelElementScalar::SetOutputMinName)
        .addProperty("OutputMaxName", &GC_INIT_RemapParticleCountToNamedModelElementScalar::GetOutputMaxName, &GC_INIT_RemapParticleCountToNamedModelElementScalar::SetOutputMaxName)
        .addProperty("ModelFromRenderer", &GC_INIT_RemapParticleCountToNamedModelElementScalar::GetModelFromRenderer, &GC_INIT_RemapParticleCountToNamedModelElementScalar::SetModelFromRenderer)
        .endClass();
}