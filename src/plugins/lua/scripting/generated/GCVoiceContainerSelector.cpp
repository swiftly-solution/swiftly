#include "../../../core/scripting/generated/classes/GCVoiceContainerSelector.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerSelector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerSelector>("CVoiceContainerSelector")
        .addProperty("Mode", &GCVoiceContainerSelector::GetMode, &GCVoiceContainerSelector::SetMode)
        .addProperty("Retrigger", &GCVoiceContainerSelector::GetRetrigger, &GCVoiceContainerSelector::SetRetrigger)
        .endClass();
}