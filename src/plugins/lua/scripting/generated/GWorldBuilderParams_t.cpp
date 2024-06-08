#include "../../../core/scripting/generated/classes/GWorldBuilderParams_t.h"
#include "../core.h"

void SetupLuaClassGWorldBuilderParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWorldBuilderParams_t>("WorldBuilderParams_t")
        .addProperty("MinDrawVolumeSize", &GWorldBuilderParams_t::GetMinDrawVolumeSize, &GWorldBuilderParams_t::SetMinDrawVolumeSize)
        .addProperty("BuildBakedLighting", &GWorldBuilderParams_t::GetBuildBakedLighting, &GWorldBuilderParams_t::SetBuildBakedLighting)
        .addProperty("BakedLightingInfo", &GWorldBuilderParams_t::GetBakedLightingInfo, &GWorldBuilderParams_t::SetBakedLightingInfo)
        .addProperty("CompileTimestamp", &GWorldBuilderParams_t::GetCompileTimestamp, &GWorldBuilderParams_t::SetCompileTimestamp)
        .addProperty("CompileFingerprint", &GWorldBuilderParams_t::GetCompileFingerprint, &GWorldBuilderParams_t::SetCompileFingerprint)
        .endClass();
}