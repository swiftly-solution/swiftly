#include "../../../core/scripting/generated/classes/GC_OP_FadeAndKillForTracers.h"
#include "../core.h"

void SetupLuaClassGC_OP_FadeAndKillForTracers(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_FadeAndKillForTracers>("C_OP_FadeAndKillForTracers")
        .addProperty("StartFadeInTime", &GC_OP_FadeAndKillForTracers::GetStartFadeInTime, &GC_OP_FadeAndKillForTracers::SetStartFadeInTime)
        .addProperty("EndFadeInTime", &GC_OP_FadeAndKillForTracers::GetEndFadeInTime, &GC_OP_FadeAndKillForTracers::SetEndFadeInTime)
        .addProperty("StartFadeOutTime", &GC_OP_FadeAndKillForTracers::GetStartFadeOutTime, &GC_OP_FadeAndKillForTracers::SetStartFadeOutTime)
        .addProperty("EndFadeOutTime", &GC_OP_FadeAndKillForTracers::GetEndFadeOutTime, &GC_OP_FadeAndKillForTracers::SetEndFadeOutTime)
        .addProperty("StartAlpha", &GC_OP_FadeAndKillForTracers::GetStartAlpha, &GC_OP_FadeAndKillForTracers::SetStartAlpha)
        .addProperty("EndAlpha", &GC_OP_FadeAndKillForTracers::GetEndAlpha, &GC_OP_FadeAndKillForTracers::SetEndAlpha)
        .endClass();
}