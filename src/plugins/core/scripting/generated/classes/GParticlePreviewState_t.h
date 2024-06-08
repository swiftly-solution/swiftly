class GParticlePreviewState_t;

#ifndef _gcparticlepreviewstate_t_h
#define _gcparticlepreviewstate_t_h

#include "../../../scripting.h"

#include "../types/GPetGroundType_t.h"
#include "GParticlePreviewBodyGroup_t.h"

class GParticlePreviewState_t
{
private:
    void *m_ptr;

public:
    GParticlePreviewState_t() {}
    GParticlePreviewState_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetPreviewModel() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewState_t", "m_previewModel"); }
    void SetPreviewModel(CUtlString value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_previewModel", true, value); }
    uint32_t GetModSpecificData() const { return GetSchemaValue<uint32_t>(m_ptr, "ParticlePreviewState_t", "m_nModSpecificData"); }
    void SetModSpecificData(uint32_t value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_nModSpecificData", true, value); }
    PetGroundType_t GetGroundType() const { return GetSchemaValue<PetGroundType_t>(m_ptr, "ParticlePreviewState_t", "m_groundType"); }
    void SetGroundType(PetGroundType_t value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_groundType", true, value); }
    CUtlString GetSequenceName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewState_t", "m_sequenceName"); }
    void SetSequenceName(CUtlString value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_sequenceName", true, value); }
    int32_t GetFireParticleOnSequenceFrame() const { return GetSchemaValue<int32_t>(m_ptr, "ParticlePreviewState_t", "m_nFireParticleOnSequenceFrame"); }
    void SetFireParticleOnSequenceFrame(int32_t value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_nFireParticleOnSequenceFrame", true, value); }
    CUtlString GetHitboxSetName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewState_t", "m_hitboxSetName"); }
    void SetHitboxSetName(CUtlString value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_hitboxSetName", true, value); }
    CUtlString GetMaterialGroupName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewState_t", "m_materialGroupName"); }
    void SetMaterialGroupName(CUtlString value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_materialGroupName", true, value); }
    std::vector<GParticlePreviewBodyGroup_t> GetBodyGroups() const { CUtlVector<GParticlePreviewBodyGroup_t>* vec = GetSchemaValue<CUtlVector<GParticlePreviewBodyGroup_t>*>(m_ptr, "ParticlePreviewState_t", "m_vecBodyGroups"); std::vector<GParticlePreviewBodyGroup_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBodyGroups(std::vector<GParticlePreviewBodyGroup_t> value) { SetSchemaValueCUtlVector<GParticlePreviewBodyGroup_t>(m_ptr, "ParticlePreviewState_t", "m_vecBodyGroups", true, value); }
    float GetPlaybackSpeed() const { return GetSchemaValue<float>(m_ptr, "ParticlePreviewState_t", "m_flPlaybackSpeed"); }
    void SetPlaybackSpeed(float value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_flPlaybackSpeed", true, value); }
    float GetParticleSimulationRate() const { return GetSchemaValue<float>(m_ptr, "ParticlePreviewState_t", "m_flParticleSimulationRate"); }
    void SetParticleSimulationRate(float value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_flParticleSimulationRate", true, value); }
    bool GetShouldDrawHitboxes() const { return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawHitboxes"); }
    void SetShouldDrawHitboxes(bool value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawHitboxes", true, value); }
    bool GetShouldDrawAttachments() const { return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawAttachments"); }
    void SetShouldDrawAttachments(bool value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawAttachments", true, value); }
    bool GetShouldDrawAttachmentNames() const { return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawAttachmentNames"); }
    void SetShouldDrawAttachmentNames(bool value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawAttachmentNames", true, value); }
    bool GetShouldDrawControlPointAxes() const { return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawControlPointAxes"); }
    void SetShouldDrawControlPointAxes(bool value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bShouldDrawControlPointAxes", true, value); }
    bool GetAnimationNonLooping() const { return GetSchemaValue<bool>(m_ptr, "ParticlePreviewState_t", "m_bAnimationNonLooping"); }
    void SetAnimationNonLooping(bool value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_bAnimationNonLooping", true, value); }
    Vector GetPreviewGravity() const { return GetSchemaValue<Vector>(m_ptr, "ParticlePreviewState_t", "m_vecPreviewGravity"); }
    void SetPreviewGravity(Vector value) { SetSchemaValue(m_ptr, "ParticlePreviewState_t", "m_vecPreviewGravity", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif