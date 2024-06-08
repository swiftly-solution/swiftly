#include "../../../core/scripting/generated/classes/GPostProcessingLocalContrastParameters_t.h"
#include "../core.h"

void SetupLuaClassGPostProcessingLocalContrastParameters_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingLocalContrastParameters_t>("PostProcessingLocalContrastParameters_t")
        .addProperty("LocalContrastStrength", &GPostProcessingLocalContrastParameters_t::GetLocalContrastStrength, &GPostProcessingLocalContrastParameters_t::SetLocalContrastStrength)
        .addProperty("LocalContrastEdgeStrength", &GPostProcessingLocalContrastParameters_t::GetLocalContrastEdgeStrength, &GPostProcessingLocalContrastParameters_t::SetLocalContrastEdgeStrength)
        .addProperty("LocalContrastVignetteStart", &GPostProcessingLocalContrastParameters_t::GetLocalContrastVignetteStart, &GPostProcessingLocalContrastParameters_t::SetLocalContrastVignetteStart)
        .addProperty("LocalContrastVignetteEnd", &GPostProcessingLocalContrastParameters_t::GetLocalContrastVignetteEnd, &GPostProcessingLocalContrastParameters_t::SetLocalContrastVignetteEnd)
        .addProperty("LocalContrastVignetteBlur", &GPostProcessingLocalContrastParameters_t::GetLocalContrastVignetteBlur, &GPostProcessingLocalContrastParameters_t::SetLocalContrastVignetteBlur)
        .endClass();
}