#include "../../../core/scripting/generated/classes/GCSoundPatch.h"
#include "../core.h"

void SetupLuaClassGCSoundPatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundPatch>("CSoundPatch")
        .addProperty("Pitch", &GCSoundPatch::GetPitch, &GCSoundPatch::SetPitch)
        .addProperty("Volume", &GCSoundPatch::GetVolume, &GCSoundPatch::SetVolume)
        .addProperty("ShutdownTime", &GCSoundPatch::GetShutdownTime, &GCSoundPatch::SetShutdownTime)
        .addProperty("LastTime", &GCSoundPatch::GetLastTime, &GCSoundPatch::SetLastTime)
        .addProperty("SoundScriptName", &GCSoundPatch::GetSoundScriptName, &GCSoundPatch::SetSoundScriptName)
        .addProperty("Ent", &GCSoundPatch::GetEnt, &GCSoundPatch::SetEnt)
        .addProperty("SoundEntityIndex", &GCSoundPatch::GetSoundEntityIndex, &GCSoundPatch::SetSoundEntityIndex)
        .addProperty("SoundOrigin", &GCSoundPatch::GetSoundOrigin, &GCSoundPatch::SetSoundOrigin)
        .addProperty("IsPlaying", &GCSoundPatch::GetIsPlaying, &GCSoundPatch::SetIsPlaying)
        .addProperty("Filter", &GCSoundPatch::GetFilter, &GCSoundPatch::SetFilter)
        .addProperty("CloseCaptionDuration", &GCSoundPatch::GetCloseCaptionDuration, &GCSoundPatch::SetCloseCaptionDuration)
        .addProperty("UpdatedSoundOrigin", &GCSoundPatch::GetUpdatedSoundOrigin, &GCSoundPatch::SetUpdatedSoundOrigin)
        .addProperty("ClassName", &GCSoundPatch::GetClassName, &GCSoundPatch::SetClassName)
        .endClass();
}