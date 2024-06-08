#include "../../../core/scripting/generated/classes/GCEnvSoundscape.h"
#include "../core.h"

void SetupLuaClassGCEnvSoundscape(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscape>("CEnvSoundscape")
        .addProperty("OnPlay", &GCEnvSoundscape::GetOnPlay, &GCEnvSoundscape::SetOnPlay)
        .addProperty("Radius", &GCEnvSoundscape::GetRadius, &GCEnvSoundscape::SetRadius)
        .addProperty("SoundscapeName", &GCEnvSoundscape::GetSoundscapeName, &GCEnvSoundscape::SetSoundscapeName)
        .addProperty("SoundEventName", &GCEnvSoundscape::GetSoundEventName, &GCEnvSoundscape::SetSoundEventName)
        .addProperty("OverrideWithEvent", &GCEnvSoundscape::GetOverrideWithEvent, &GCEnvSoundscape::SetOverrideWithEvent)
        .addProperty("SoundscapeIndex", &GCEnvSoundscape::GetSoundscapeIndex, &GCEnvSoundscape::SetSoundscapeIndex)
        .addProperty("SoundscapeEntityListId", &GCEnvSoundscape::GetSoundscapeEntityListId, &GCEnvSoundscape::SetSoundscapeEntityListId)
        .addProperty("SoundEventHash", &GCEnvSoundscape::GetSoundEventHash, &GCEnvSoundscape::SetSoundEventHash)
        .addProperty("PositionNames", &GCEnvSoundscape::GetPositionNames, &GCEnvSoundscape::SetPositionNames)
        .addProperty("ProxySoundscape", &GCEnvSoundscape::GetProxySoundscape, &GCEnvSoundscape::SetProxySoundscape)
        .addProperty("Disabled", &GCEnvSoundscape::GetDisabled, &GCEnvSoundscape::SetDisabled)
        .endClass();
}