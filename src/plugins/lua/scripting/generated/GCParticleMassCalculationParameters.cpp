#include "../../../core/scripting/generated/classes/GCParticleMassCalculationParameters.h"
#include "../core.h"

void SetupLuaClassGCParticleMassCalculationParameters(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleMassCalculationParameters>("CParticleMassCalculationParameters")
        .addProperty("MassMode", &GCParticleMassCalculationParameters::GetMassMode, &GCParticleMassCalculationParameters::SetMassMode)
        .addProperty("Radius", &GCParticleMassCalculationParameters::GetRadius, &GCParticleMassCalculationParameters::SetRadius)
        .addProperty("NominalRadius", &GCParticleMassCalculationParameters::GetNominalRadius, &GCParticleMassCalculationParameters::SetNominalRadius)
        .addProperty("Scale", &GCParticleMassCalculationParameters::GetScale, &GCParticleMassCalculationParameters::SetScale)
        .endClass();
}