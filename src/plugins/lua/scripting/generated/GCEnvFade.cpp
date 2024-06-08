#include "../../../core/scripting/generated/classes/GCEnvFade.h"
#include "../core.h"

void SetupLuaClassGCEnvFade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvFade>("CEnvFade")
        .addProperty("FadeColor", &GCEnvFade::GetFadeColor, &GCEnvFade::SetFadeColor)
        .addProperty("Duration", &GCEnvFade::GetDuration, &GCEnvFade::SetDuration)
        .addProperty("HoldDuration", &GCEnvFade::GetHoldDuration, &GCEnvFade::SetHoldDuration)
        .addProperty("OnBeginFade", &GCEnvFade::GetOnBeginFade, &GCEnvFade::SetOnBeginFade)
        .endClass();
}