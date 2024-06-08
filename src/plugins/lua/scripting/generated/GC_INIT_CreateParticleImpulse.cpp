#include "../../../core/scripting/generated/classes/GC_INIT_CreateParticleImpulse.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateParticleImpulse(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateParticleImpulse>("C_INIT_CreateParticleImpulse")
        .addProperty("InputRadius", &GC_INIT_CreateParticleImpulse::GetInputRadius, &GC_INIT_CreateParticleImpulse::SetInputRadius)
        .addProperty("InputMagnitude", &GC_INIT_CreateParticleImpulse::GetInputMagnitude, &GC_INIT_CreateParticleImpulse::SetInputMagnitude)
        .addProperty("FalloffFunction", &GC_INIT_CreateParticleImpulse::GetFalloffFunction, &GC_INIT_CreateParticleImpulse::SetFalloffFunction)
        .addProperty("InputFalloffExp", &GC_INIT_CreateParticleImpulse::GetInputFalloffExp, &GC_INIT_CreateParticleImpulse::SetInputFalloffExp)
        .addProperty("ImpulseType", &GC_INIT_CreateParticleImpulse::GetImpulseType, &GC_INIT_CreateParticleImpulse::SetImpulseType)
        .endClass();
}