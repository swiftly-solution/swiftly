class GCBasePlatTrain;

#ifndef _gccbaseplattrain_h
#define _gccbaseplattrain_h

#include "../../../scripting.h"




class GCBasePlatTrain
{
private:
    void *m_ptr;

public:
    GCBasePlatTrain() {}
    GCBasePlatTrain(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetNoiseMoving() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePlatTrain", "m_NoiseMoving"); }
    void SetNoiseMoving(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePlatTrain", "m_NoiseMoving", false, value); }
    CUtlSymbolLarge GetNoiseArrived() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePlatTrain", "m_NoiseArrived"); }
    void SetNoiseArrived(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBasePlatTrain", "m_NoiseArrived", false, value); }
    float GetVolume() const { return GetSchemaValue<float>(m_ptr, "CBasePlatTrain", "m_volume"); }
    void SetVolume(float value) { SetSchemaValue(m_ptr, "CBasePlatTrain", "m_volume", false, value); }
    float GetTWidth() const { return GetSchemaValue<float>(m_ptr, "CBasePlatTrain", "m_flTWidth"); }
    void SetTWidth(float value) { SetSchemaValue(m_ptr, "CBasePlatTrain", "m_flTWidth", false, value); }
    float GetTLength() const { return GetSchemaValue<float>(m_ptr, "CBasePlatTrain", "m_flTLength"); }
    void SetTLength(float value) { SetSchemaValue(m_ptr, "CBasePlatTrain", "m_flTLength", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif