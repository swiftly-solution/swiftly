class GCVoiceContainerStaticAdditiveSynth;

#ifndef _gccvoicecontainerstaticadditivesynth_h
#define _gccvoicecontainerstaticadditivesynth_h

#include "../../../scripting.h"




class GCVoiceContainerStaticAdditiveSynth
{
private:
    void *m_ptr;

public:
    GCVoiceContainerStaticAdditiveSynth() {}
    GCVoiceContainerStaticAdditiveSynth(void *ptr) : m_ptr(ptr) {}

    float GetMinVolume() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_flMinVolume"); }
    void SetMinVolume(float value) { SetSchemaValue(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_flMinVolume", false, value); }
    int32_t GetInstancesAtMinVolume() const { return GetSchemaValue<int32_t>(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_nInstancesAtMinVolume"); }
    void SetInstancesAtMinVolume(int32_t value) { SetSchemaValue(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_nInstancesAtMinVolume", false, value); }
    float GetMaxVolume() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_flMaxVolume"); }
    void SetMaxVolume(float value) { SetSchemaValue(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_flMaxVolume", false, value); }
    int32_t GetInstancesAtMaxVolume() const { return GetSchemaValue<int32_t>(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_nInstancesAtMaxVolume"); }
    void SetInstancesAtMaxVolume(int32_t value) { SetSchemaValue(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_nInstancesAtMaxVolume", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif