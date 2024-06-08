#include "../../../core/scripting/generated/classes/GCNmClip.h"
#include "../core.h"

void SetupLuaClassGCNmClip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmClip>("CNmClip")
        .addProperty("NumFrames", &GCNmClip::GetNumFrames, &GCNmClip::SetNumFrames)
        .addProperty("Duration", &GCNmClip::GetDuration, &GCNmClip::SetDuration)
        .addProperty("TrackCompressionSettings", &GCNmClip::GetTrackCompressionSettings, &GCNmClip::SetTrackCompressionSettings)
        .addProperty("CompressedPoseOffsets", &GCNmClip::GetCompressedPoseOffsets, &GCNmClip::SetCompressedPoseOffsets)
        .addProperty("SyncTrack", &GCNmClip::GetSyncTrack, &GCNmClip::SetSyncTrack)
        .addProperty("RootMotion", &GCNmClip::GetRootMotion, &GCNmClip::SetRootMotion)
        .addProperty("IsAdditive", &GCNmClip::GetIsAdditive, &GCNmClip::SetIsAdditive)
        .endClass();
}