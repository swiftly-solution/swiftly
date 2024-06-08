#include "../../../core/scripting/generated/classes/GCAmbientGeneric.h"
#include "../core.h"

void SetupLuaClassGCAmbientGeneric(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAmbientGeneric>("CAmbientGeneric")
        .addProperty("Radius", &GCAmbientGeneric::GetRadius, &GCAmbientGeneric::SetRadius)
        .addProperty("MaxRadius", &GCAmbientGeneric::GetMaxRadius, &GCAmbientGeneric::SetMaxRadius)
        .addProperty("SoundLevel", &GCAmbientGeneric::GetSoundLevel, &GCAmbientGeneric::SetSoundLevel)
        .addProperty("Dpv", &GCAmbientGeneric::GetDpv, &GCAmbientGeneric::SetDpv)
        .addProperty("Active", &GCAmbientGeneric::GetActive, &GCAmbientGeneric::SetActive)
        .addProperty("Looping", &GCAmbientGeneric::GetLooping, &GCAmbientGeneric::SetLooping)
        .addProperty("Sound", &GCAmbientGeneric::GetSound, &GCAmbientGeneric::SetSound)
        .addProperty("SourceEntName", &GCAmbientGeneric::GetSourceEntName, &GCAmbientGeneric::SetSourceEntName)
        .addProperty("SoundSource", &GCAmbientGeneric::GetSoundSource, &GCAmbientGeneric::SetSoundSource)
        .addProperty("SoundSourceEntIndex", &GCAmbientGeneric::GetSoundSourceEntIndex, &GCAmbientGeneric::SetSoundSourceEntIndex)
        .endClass();
}