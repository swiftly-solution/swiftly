#include "../../../core/scripting/generated/classes/GCVoiceContainerSwitch.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerSwitch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerSwitch>("CVoiceContainerSwitch")
        .addProperty("SoundsToPlay", &GCVoiceContainerSwitch::GetSoundsToPlay, &GCVoiceContainerSwitch::SetSoundsToPlay)
        .endClass();
}