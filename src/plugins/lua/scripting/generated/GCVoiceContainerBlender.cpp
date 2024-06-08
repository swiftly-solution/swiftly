#include "../../../core/scripting/generated/classes/GCVoiceContainerBlender.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerBlender(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerBlender>("CVoiceContainerBlender")
        .addProperty("BlendFactor", &GCVoiceContainerBlender::GetBlendFactor, &GCVoiceContainerBlender::SetBlendFactor)
        .endClass();
}