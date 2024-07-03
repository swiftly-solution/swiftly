#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParticlePreviewState_t::GParticlePreviewState_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParticlePreviewState_t::GParticlePreviewState_t(void *ptr) {
    m_ptr = ptr;
}
std::string GParticlePreviewState_t::GetPreviewModel() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewState_t", "m_previewModel").Get();
}
void GParticlePreviewState_t::SetPreviewModel(std::string value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_previewModel", true, CUtlString(value.c_str()));
}
uint32_t GParticlePreviewState_t::GetModSpecificData() const {
    return GetSchemaValue<uint32_t>(m_ptr, "ParticlePreviewState_t", "m_nModSpecificData");
}
void GParticlePreviewState_t::SetModSpecificData(uint32_t value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_nModSpecificData", true, value);
}
uint64_t GParticlePreviewState_t::GetGroundType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ParticlePreviewState_t", "m_groundType");
}
void GParticlePreviewState_t::SetGroundType(uint64_t value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_groundType", true, value);
}
std::string GParticlePreviewState_t::GetSequenceName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewState_t", "m_sequenceName").Get();
}
void GParticlePreviewState_t::SetSequenceName(std::string value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_sequenceName", true, CUtlString(value.c_str()));
}
int32_t GParticlePreviewState_t::GetFireParticleOnSequenceFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "ParticlePreviewState_t", "m_nFireParticleOnSequenceFrame");
}
void GParticlePreviewState_t::SetFireParticleOnSequenceFrame(int32_t value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_nFireParticleOnSequenceFrame", true, value);
}
std::string GParticlePreviewState_t::GetHitboxSetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewState_t", "m_hitboxSetName").Get();
}
void GParticlePreviewState_t::SetHitboxSetName(std::string value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_hitboxSetName", true, CUtlString(value.c_str()));
}
std::string GParticlePreviewState_t::GetMaterialGroupName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewState_t", "m_materialGroupName").Get();
}
void GParticlePreviewState_t::SetMaterialGroupName(std::string value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_materialGroupName", true, CUtlString(value.c_str()));
}
std::vector<GParticlePreviewBodyGroup_t> GParticlePreviewState_t::GetBodyGroups() const {
    CUtlVector<GParticlePreviewBodyGroup_t>* vec = GetSchemaValue<CUtlVector<GParticlePreviewBodyGroup_t>*>(m_ptr, "ParticlePreviewState_t", "m_vecBodyGroups"); std::vector<GParticlePreviewBodyGroup_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GParticlePreviewState_t::SetBodyGroups(std::vector<GParticlePreviewBodyGroup_t> value) {
    SetSchemaValueCUtlVector<GParticlePreviewBodyGroup_t>(m_ptr, "ParticlePreviewState_t", "m_vecBodyGroups", true, value);
}
float GParticlePreviewState_t::GetPlaybackSpeed() const {
    return GetSchemaValue<float>(m_ptr, "ParticlePreviewState_t", "m_flPlaybackSpeed");
}
void GParticlePreviewState_t::SetPlaybackSpeed(float value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_flPlaybackSpeed", true, value);
}
float GParticlePreviewState_t::GetParticleSimulationRate() const {
    return GetSchemaValue<float>(m_ptr, "ParticlePreviewState_t", "m_flParticleSimulationRate");
}
void GParticlePreviewState_t::SetParticleSimulationRate(float value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_flParticleSimulationRate", true, value);
}
bool GParticlePreviewState_t::GetShouldDrawHitboxes() const {
    return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawHitboxes");
}
void GParticlePreviewState_t::SetShouldDrawHitboxes(bool value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawHitboxes", true, value);
}
bool GParticlePreviewState_t::GetShouldDrawAttachments() const {
    return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawAttachments");
}
void GParticlePreviewState_t::SetShouldDrawAttachments(bool value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawAttachments", true, value);
}
bool GParticlePreviewState_t::GetShouldDrawAttachmentNames() const {
    return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawAttachmentNames");
}
void GParticlePreviewState_t::SetShouldDrawAttachmentNames(bool value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawAttachmentNames", true, value);
}
bool GParticlePreviewState_t::GetShouldDrawControlPointAxes() const {
    return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawControlPointAxes");
}
void GParticlePreviewState_t::SetShouldDrawControlPointAxes(bool value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawControlPointAxes", true, value);
}
bool GParticlePreviewState_t::GetAnimationNonLooping() const {
    return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bAnimationNonLooping");
}
void GParticlePreviewState_t::SetAnimationNonLooping(bool value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bAnimationNonLooping", true, value);
}
Vector GParticlePreviewState_t::GetPreviewGravity() const {
    return GetSchemaValue<Vector>(m_ptr, "ParticlePreviewState_t", "m_vecPreviewGravity");
}
void GParticlePreviewState_t::SetPreviewGravity(Vector value) {
    SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_vecPreviewGravity", true, value);
}
std::string GParticlePreviewState_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParticlePreviewState_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParticlePreviewState_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticlePreviewState_t>("ParticlePreviewState_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PreviewModel", &GParticlePreviewState_t::GetPreviewModel, &GParticlePreviewState_t::SetPreviewModel)
        .addProperty("ModSpecificData", &GParticlePreviewState_t::GetModSpecificData, &GParticlePreviewState_t::SetModSpecificData)
        .addProperty("GroundType", &GParticlePreviewState_t::GetGroundType, &GParticlePreviewState_t::SetGroundType)
        .addProperty("SequenceName", &GParticlePreviewState_t::GetSequenceName, &GParticlePreviewState_t::SetSequenceName)
        .addProperty("FireParticleOnSequenceFrame", &GParticlePreviewState_t::GetFireParticleOnSequenceFrame, &GParticlePreviewState_t::SetFireParticleOnSequenceFrame)
        .addProperty("HitboxSetName", &GParticlePreviewState_t::GetHitboxSetName, &GParticlePreviewState_t::SetHitboxSetName)
        .addProperty("MaterialGroupName", &GParticlePreviewState_t::GetMaterialGroupName, &GParticlePreviewState_t::SetMaterialGroupName)
        .addProperty("BodyGroups", &GParticlePreviewState_t::GetBodyGroups, &GParticlePreviewState_t::SetBodyGroups)
        .addProperty("PlaybackSpeed", &GParticlePreviewState_t::GetPlaybackSpeed, &GParticlePreviewState_t::SetPlaybackSpeed)
        .addProperty("ParticleSimulationRate", &GParticlePreviewState_t::GetParticleSimulationRate, &GParticlePreviewState_t::SetParticleSimulationRate)
        .addProperty("ShouldDrawHitboxes", &GParticlePreviewState_t::GetShouldDrawHitboxes, &GParticlePreviewState_t::SetShouldDrawHitboxes)
        .addProperty("ShouldDrawAttachments", &GParticlePreviewState_t::GetShouldDrawAttachments, &GParticlePreviewState_t::SetShouldDrawAttachments)
        .addProperty("ShouldDrawAttachmentNames", &GParticlePreviewState_t::GetShouldDrawAttachmentNames, &GParticlePreviewState_t::SetShouldDrawAttachmentNames)
        .addProperty("ShouldDrawControlPointAxes", &GParticlePreviewState_t::GetShouldDrawControlPointAxes, &GParticlePreviewState_t::SetShouldDrawControlPointAxes)
        .addProperty("AnimationNonLooping", &GParticlePreviewState_t::GetAnimationNonLooping, &GParticlePreviewState_t::SetAnimationNonLooping)
        .addProperty("PreviewGravity", &GParticlePreviewState_t::GetPreviewGravity, &GParticlePreviewState_t::SetPreviewGravity)
        .addFunction("ToPtr", &GParticlePreviewState_t::ToPtr)
        .addFunction("IsValid", &GParticlePreviewState_t::IsValid)
        .endClass();
}