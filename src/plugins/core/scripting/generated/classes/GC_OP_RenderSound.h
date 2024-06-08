class GC_OP_RenderSound;

#ifndef _gcc_op_rendersound_h
#define _gcc_op_rendersound_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderSound
{
private:
    void *m_ptr;

public:
    GC_OP_RenderSound() {}
    GC_OP_RenderSound(void *ptr) : m_ptr(ptr) {}

    float GetDurationScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSound", "m_flDurationScale"); }
    void SetDurationScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_flDurationScale", false, value); }
    float GetSndLvlScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSound", "m_flSndLvlScale"); }
    void SetSndLvlScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_flSndLvlScale", false, value); }
    float GetPitchScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSound", "m_flPitchScale"); }
    void SetPitchScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_flPitchScale", false, value); }
    float GetVolumeScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSound", "m_flVolumeScale"); }
    void SetVolumeScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_flVolumeScale", false, value); }
    GParticleAttributeIndex_t GetSndLvlField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderSound", "m_nSndLvlField"); }
    void SetSndLvlField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_nSndLvlField", false, value); }
    GParticleAttributeIndex_t GetDurationField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderSound", "m_nDurationField"); }
    void SetDurationField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_nDurationField", false, value); }
    GParticleAttributeIndex_t GetPitchField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderSound", "m_nPitchField"); }
    void SetPitchField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_nPitchField", false, value); }
    GParticleAttributeIndex_t GetVolumeField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderSound", "m_nVolumeField"); }
    void SetVolumeField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_nVolumeField", false, value); }
    int32_t GetChannel() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderSound", "m_nChannel"); }
    void SetChannel(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_nChannel", false, value); }
    int32_t GetCPReference() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderSound", "m_nCPReference"); }
    void SetCPReference(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_nCPReference", false, value); }
    std::string GetSoundName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_RenderSound", "m_pszSoundName"); }
    void SetSoundName(std::string value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_pszSoundName", false, value); }
    bool GetSuppressStopSoundEvent() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSound", "m_bSuppressStopSoundEvent"); }
    void SetSuppressStopSoundEvent(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSound", "m_bSuppressStopSoundEvent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif