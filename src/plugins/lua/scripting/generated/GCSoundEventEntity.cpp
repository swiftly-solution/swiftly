#include "../../../core/scripting/generated/classes/GCSoundEventEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundEventEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventEntity>("CSoundEventEntity")
        .addProperty("StartOnSpawn", &GCSoundEventEntity::GetStartOnSpawn, &GCSoundEventEntity::SetStartOnSpawn)
        .addProperty("ToLocalPlayer", &GCSoundEventEntity::GetToLocalPlayer, &GCSoundEventEntity::SetToLocalPlayer)
        .addProperty("StopOnNew", &GCSoundEventEntity::GetStopOnNew, &GCSoundEventEntity::SetStopOnNew)
        .addProperty("SaveRestore", &GCSoundEventEntity::GetSaveRestore, &GCSoundEventEntity::SetSaveRestore)
        .addProperty("SavedIsPlaying", &GCSoundEventEntity::GetSavedIsPlaying, &GCSoundEventEntity::SetSavedIsPlaying)
        .addProperty("SavedElapsedTime", &GCSoundEventEntity::GetSavedElapsedTime, &GCSoundEventEntity::SetSavedElapsedTime)
        .addProperty("SourceEntityName", &GCSoundEventEntity::GetSourceEntityName, &GCSoundEventEntity::SetSourceEntityName)
        .addProperty("AttachmentName", &GCSoundEventEntity::GetAttachmentName, &GCSoundEventEntity::SetAttachmentName)
        .addProperty("OnSoundFinished", &GCSoundEventEntity::GetOnSoundFinished, &GCSoundEventEntity::SetOnSoundFinished)
        .addProperty("SoundName", &GCSoundEventEntity::GetSoundName, &GCSoundEventEntity::SetSoundName)
        .addProperty("Source", &GCSoundEventEntity::GetSource, &GCSoundEventEntity::SetSource)
        .addProperty("EntityIndexSelection", &GCSoundEventEntity::GetEntityIndexSelection, &GCSoundEventEntity::SetEntityIndexSelection)
        .endClass();
}