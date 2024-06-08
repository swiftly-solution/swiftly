#include "../../../core/scripting/generated/classes/GC_OP_FadeIn.h"
#include "../core.h"

void SetupLuaClassGC_OP_FadeIn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_FadeIn>("C_OP_FadeIn")
        .addProperty("FadeInTimeMin", &GC_OP_FadeIn::GetFadeInTimeMin, &GC_OP_FadeIn::SetFadeInTimeMin)
        .addProperty("FadeInTimeMax", &GC_OP_FadeIn::GetFadeInTimeMax, &GC_OP_FadeIn::SetFadeInTimeMax)
        .addProperty("FadeInTimeExp", &GC_OP_FadeIn::GetFadeInTimeExp, &GC_OP_FadeIn::SetFadeInTimeExp)
        .addProperty("Proportional", &GC_OP_FadeIn::GetProportional, &GC_OP_FadeIn::SetProportional)
        .endClass();
}