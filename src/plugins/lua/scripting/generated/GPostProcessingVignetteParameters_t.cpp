#include "../../../core/scripting/generated/classes/GPostProcessingVignetteParameters_t.h"
#include "../core.h"

void SetupLuaClassGPostProcessingVignetteParameters_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingVignetteParameters_t>("PostProcessingVignetteParameters_t")
        .addProperty("VignetteStrength", &GPostProcessingVignetteParameters_t::GetVignetteStrength, &GPostProcessingVignetteParameters_t::SetVignetteStrength)
        .addProperty("Center", &GPostProcessingVignetteParameters_t::GetCenter, &GPostProcessingVignetteParameters_t::SetCenter)
        .addProperty("Radius", &GPostProcessingVignetteParameters_t::GetRadius, &GPostProcessingVignetteParameters_t::SetRadius)
        .addProperty("Roundness", &GPostProcessingVignetteParameters_t::GetRoundness, &GPostProcessingVignetteParameters_t::SetRoundness)
        .addProperty("Feather", &GPostProcessingVignetteParameters_t::GetFeather, &GPostProcessingVignetteParameters_t::SetFeather)
        .addProperty("ColorTint", &GPostProcessingVignetteParameters_t::GetColorTint, &GPostProcessingVignetteParameters_t::SetColorTint)
        .endClass();
}