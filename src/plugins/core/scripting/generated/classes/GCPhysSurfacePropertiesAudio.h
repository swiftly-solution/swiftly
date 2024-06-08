class GCPhysSurfacePropertiesAudio;

#ifndef _gccphyssurfacepropertiesaudio_h
#define _gccphyssurfacepropertiesaudio_h

#include "../../../scripting.h"




class GCPhysSurfacePropertiesAudio
{
private:
    void *m_ptr;

public:
    GCPhysSurfacePropertiesAudio() {}
    GCPhysSurfacePropertiesAudio(void *ptr) : m_ptr(ptr) {}

    float GetReflectivity() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_reflectivity"); }
    void SetReflectivity(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_reflectivity", false, value); }
    float GetHardnessFactor() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardnessFactor"); }
    void SetHardnessFactor(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardnessFactor", false, value); }
    float GetRoughnessFactor() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_roughnessFactor"); }
    void SetRoughnessFactor(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_roughnessFactor", false, value); }
    float GetRoughThreshold() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_roughThreshold"); }
    void SetRoughThreshold(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_roughThreshold", false, value); }
    float GetHardThreshold() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardThreshold"); }
    void SetHardThreshold(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardThreshold", false, value); }
    float GetHardVelocityThreshold() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardVelocityThreshold"); }
    void SetHardVelocityThreshold(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardVelocityThreshold", false, value); }
    float GetStaticImpactVolume() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_flStaticImpactVolume"); }
    void SetStaticImpactVolume(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_flStaticImpactVolume", false, value); }
    float GetOcclusionFactor() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_flOcclusionFactor"); }
    void SetOcclusionFactor(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_flOcclusionFactor", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif