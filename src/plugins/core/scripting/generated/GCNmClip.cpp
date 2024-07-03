#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmClip::GCNmClip(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmClip::GCNmClip(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCNmClip::GetNumFrames() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CNmClip", "m_nNumFrames");
}
void GCNmClip::SetNumFrames(uint32_t value) {
    SetSchemaValue(m_ptr, "CNmClip", "m_nNumFrames", false, value);
}
float GCNmClip::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CNmClip", "m_flDuration");
}
void GCNmClip::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CNmClip", "m_flDuration", false, value);
}
std::vector<GNmCompressionSettings_t> GCNmClip::GetTrackCompressionSettings() const {
    CUtlVector<GNmCompressionSettings_t>* vec = GetSchemaValue<CUtlVector<GNmCompressionSettings_t>*>(m_ptr, "CNmClip", "m_trackCompressionSettings"); std::vector<GNmCompressionSettings_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNmClip::SetTrackCompressionSettings(std::vector<GNmCompressionSettings_t> value) {
    SetSchemaValueCUtlVector<GNmCompressionSettings_t>(m_ptr, "CNmClip", "m_trackCompressionSettings", false, value);
}
std::vector<uint32> GCNmClip::GetCompressedPoseOffsets() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CNmClip", "m_compressedPoseOffsets"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNmClip::SetCompressedPoseOffsets(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CNmClip", "m_compressedPoseOffsets", false, value);
}
GCNmSyncTrack GCNmClip::GetSyncTrack() const {
    GCNmSyncTrack value(GetSchemaPtr(m_ptr, "CNmClip", "m_syncTrack"));
    return value;
}
void GCNmClip::SetSyncTrack(GCNmSyncTrack value) {
    SetSchemaValue(m_ptr, "CNmClip", "m_syncTrack", false, value);
}
GCNmRootMotionData GCNmClip::GetRootMotion() const {
    GCNmRootMotionData value(GetSchemaPtr(m_ptr, "CNmClip", "m_rootMotion"));
    return value;
}
void GCNmClip::SetRootMotion(GCNmRootMotionData value) {
    SetSchemaValue(m_ptr, "CNmClip", "m_rootMotion", false, value);
}
bool GCNmClip::GetIsAdditive() const {
    return GetSchemaValue<bool>(m_ptr, "CNmClip", "m_bIsAdditive");
}
void GCNmClip::SetIsAdditive(bool value) {
    SetSchemaValue(m_ptr, "CNmClip", "m_bIsAdditive", false, value);
}
std::string GCNmClip::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmClip::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmClip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmClip>("CNmClip")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NumFrames", &GCNmClip::GetNumFrames, &GCNmClip::SetNumFrames)
        .addProperty("Duration", &GCNmClip::GetDuration, &GCNmClip::SetDuration)
        .addProperty("TrackCompressionSettings", &GCNmClip::GetTrackCompressionSettings, &GCNmClip::SetTrackCompressionSettings)
        .addProperty("CompressedPoseOffsets", &GCNmClip::GetCompressedPoseOffsets, &GCNmClip::SetCompressedPoseOffsets)
        .addProperty("SyncTrack", &GCNmClip::GetSyncTrack, &GCNmClip::SetSyncTrack)
        .addProperty("RootMotion", &GCNmClip::GetRootMotion, &GCNmClip::SetRootMotion)
        .addProperty("IsAdditive", &GCNmClip::GetIsAdditive, &GCNmClip::SetIsAdditive)
        .addFunction("ToPtr", &GCNmClip::ToPtr)
        .addFunction("IsValid", &GCNmClip::IsValid)
        .endClass();
}