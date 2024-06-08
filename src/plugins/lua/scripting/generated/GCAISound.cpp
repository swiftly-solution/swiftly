#include "../../../core/scripting/generated/classes/GCAISound.h"
#include "../core.h"

void SetupLuaClassGCAISound(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAISound>("CAISound")
        .addProperty("SoundType", &GCAISound::GetSoundType, &GCAISound::SetSoundType)
        .addProperty("SoundFlags", &GCAISound::GetSoundFlags, &GCAISound::SetSoundFlags)
        .addProperty("Volume", &GCAISound::GetVolume, &GCAISound::SetVolume)
        .addProperty("SoundIndex", &GCAISound::GetSoundIndex, &GCAISound::SetSoundIndex)
        .addProperty("Duration", &GCAISound::GetDuration, &GCAISound::SetDuration)
        .addProperty("ProxyEntityName", &GCAISound::GetProxyEntityName, &GCAISound::SetProxyEntityName)
        .endClass();
}