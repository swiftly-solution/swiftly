#include "../../../core/scripting/generated/classes/GC_OP_FadeOut.h"
#include "../core.h"

void SetupLuaClassGC_OP_FadeOut(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_FadeOut>("C_OP_FadeOut")
        .addProperty("FadeOutTimeMin", &GC_OP_FadeOut::GetFadeOutTimeMin, &GC_OP_FadeOut::SetFadeOutTimeMin)
        .addProperty("FadeOutTimeMax", &GC_OP_FadeOut::GetFadeOutTimeMax, &GC_OP_FadeOut::SetFadeOutTimeMax)
        .addProperty("FadeOutTimeExp", &GC_OP_FadeOut::GetFadeOutTimeExp, &GC_OP_FadeOut::SetFadeOutTimeExp)
        .addProperty("FadeBias", &GC_OP_FadeOut::GetFadeBias, &GC_OP_FadeOut::SetFadeBias)
        .addProperty("Proportional", &GC_OP_FadeOut::GetProportional, &GC_OP_FadeOut::SetProportional)
        .addProperty("EaseInAndOut", &GC_OP_FadeOut::GetEaseInAndOut, &GC_OP_FadeOut::SetEaseInAndOut)
        .endClass();
}