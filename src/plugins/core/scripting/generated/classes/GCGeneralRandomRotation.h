class GCGeneralRandomRotation;

#ifndef _gccgeneralrandomrotation_h
#define _gccgeneralrandomrotation_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GCGeneralRandomRotation
{
private:
    void *m_ptr;

public:
    GCGeneralRandomRotation() {}
    GCGeneralRandomRotation(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "CGeneralRandomRotation", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_nFieldOutput", false, value); }
    float GetDegrees() const { return GetSchemaValue<float>(m_ptr, "CGeneralRandomRotation", "m_flDegrees"); }
    void SetDegrees(float value) { SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_flDegrees", false, value); }
    float GetDegreesMin() const { return GetSchemaValue<float>(m_ptr, "CGeneralRandomRotation", "m_flDegreesMin"); }
    void SetDegreesMin(float value) { SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_flDegreesMin", false, value); }
    float GetDegreesMax() const { return GetSchemaValue<float>(m_ptr, "CGeneralRandomRotation", "m_flDegreesMax"); }
    void SetDegreesMax(float value) { SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_flDegreesMax", false, value); }
    float GetRotationRandExponent() const { return GetSchemaValue<float>(m_ptr, "CGeneralRandomRotation", "m_flRotationRandExponent"); }
    void SetRotationRandExponent(float value) { SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_flRotationRandExponent", false, value); }
    bool GetRandomlyFlipDirection() const { return GetSchemaValue<bool>(m_ptr, "CGeneralRandomRotation", "m_bRandomlyFlipDirection"); }
    void SetRandomlyFlipDirection(bool value) { SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_bRandomlyFlipDirection", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif