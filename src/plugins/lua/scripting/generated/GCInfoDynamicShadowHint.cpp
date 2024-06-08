#include "../../../core/scripting/generated/classes/GCInfoDynamicShadowHint.h"
#include "../core.h"

void SetupLuaClassGCInfoDynamicShadowHint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoDynamicShadowHint>("CInfoDynamicShadowHint")
        .addProperty("Disabled", &GCInfoDynamicShadowHint::GetDisabled, &GCInfoDynamicShadowHint::SetDisabled)
        .addProperty("Range", &GCInfoDynamicShadowHint::GetRange, &GCInfoDynamicShadowHint::SetRange)
        .addProperty("Importance", &GCInfoDynamicShadowHint::GetImportance, &GCInfoDynamicShadowHint::SetImportance)
        .addProperty("LightChoice", &GCInfoDynamicShadowHint::GetLightChoice, &GCInfoDynamicShadowHint::SetLightChoice)
        .addProperty("Light", &GCInfoDynamicShadowHint::GetLight, &GCInfoDynamicShadowHint::SetLight)
        .endClass();
}