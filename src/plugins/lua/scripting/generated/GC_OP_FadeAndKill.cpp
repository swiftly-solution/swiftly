#include "../../../core/scripting/generated/classes/GC_OP_FadeAndKill.h"
#include "../core.h"

void SetupLuaClassGC_OP_FadeAndKill(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_FadeAndKill>("C_OP_FadeAndKill")
        .addProperty("StartFadeInTime", &GC_OP_FadeAndKill::GetStartFadeInTime, &GC_OP_FadeAndKill::SetStartFadeInTime)
        .addProperty("EndFadeInTime", &GC_OP_FadeAndKill::GetEndFadeInTime, &GC_OP_FadeAndKill::SetEndFadeInTime)
        .addProperty("StartFadeOutTime", &GC_OP_FadeAndKill::GetStartFadeOutTime, &GC_OP_FadeAndKill::SetStartFadeOutTime)
        .addProperty("EndFadeOutTime", &GC_OP_FadeAndKill::GetEndFadeOutTime, &GC_OP_FadeAndKill::SetEndFadeOutTime)
        .addProperty("StartAlpha", &GC_OP_FadeAndKill::GetStartAlpha, &GC_OP_FadeAndKill::SetStartAlpha)
        .addProperty("EndAlpha", &GC_OP_FadeAndKill::GetEndAlpha, &GC_OP_FadeAndKill::SetEndAlpha)
        .addProperty("ForcePreserveParticleOrder", &GC_OP_FadeAndKill::GetForcePreserveParticleOrder, &GC_OP_FadeAndKill::SetForcePreserveParticleOrder)
        .endClass();
}