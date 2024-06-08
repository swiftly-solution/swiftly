class GCPrecipitationVData;

#ifndef _gccprecipitationvdata_h
#define _gccprecipitationvdata_h

#include "../../../scripting.h"

#include "../types/GParticleAttachment_t.h"


class GCPrecipitationVData
{
private:
    void *m_ptr;

public:
    GCPrecipitationVData() {}
    GCPrecipitationVData(void *ptr) : m_ptr(ptr) {}

    float GetInnerDistance() const { return GetSchemaValue<float>(m_ptr, "CPrecipitationVData", "m_flInnerDistance"); }
    void SetInnerDistance(float value) { SetSchemaValue(m_ptr, "CPrecipitationVData", "m_flInnerDistance", false, value); }
    ParticleAttachment_t GetAttachType() const { return GetSchemaValue<ParticleAttachment_t>(m_ptr, "CPrecipitationVData", "m_nAttachType"); }
    void SetAttachType(ParticleAttachment_t value) { SetSchemaValue(m_ptr, "CPrecipitationVData", "m_nAttachType", false, value); }
    bool GetBatchSameVolumeType() const { return GetSchemaValue<bool>(m_ptr, "CPrecipitationVData", "m_bBatchSameVolumeType"); }
    void SetBatchSameVolumeType(bool value) { SetSchemaValue(m_ptr, "CPrecipitationVData", "m_bBatchSameVolumeType", false, value); }
    int32_t GetRTEnvCP() const { return GetSchemaValue<int32_t>(m_ptr, "CPrecipitationVData", "m_nRTEnvCP"); }
    void SetRTEnvCP(int32_t value) { SetSchemaValue(m_ptr, "CPrecipitationVData", "m_nRTEnvCP", false, value); }
    int32_t GetRTEnvCPComponent() const { return GetSchemaValue<int32_t>(m_ptr, "CPrecipitationVData", "m_nRTEnvCPComponent"); }
    void SetRTEnvCPComponent(int32_t value) { SetSchemaValue(m_ptr, "CPrecipitationVData", "m_nRTEnvCPComponent", false, value); }
    CUtlString GetModifier() const { return GetSchemaValue<CUtlString>(m_ptr, "CPrecipitationVData", "m_szModifier"); }
    void SetModifier(CUtlString value) { SetSchemaValue(m_ptr, "CPrecipitationVData", "m_szModifier", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif