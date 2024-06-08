class GC_INIT_AgeNoise;

#ifndef _gcc_init_agenoise_h
#define _gcc_init_agenoise_h

#include "../../../scripting.h"




class GC_INIT_AgeNoise
{
private:
    void *m_ptr;

public:
    GC_INIT_AgeNoise() {}
    GC_INIT_AgeNoise(void *ptr) : m_ptr(ptr) {}

    bool GetAbsVal() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_AgeNoise", "m_bAbsVal"); }
    void SetAbsVal(bool value) { SetSchemaValue(m_ptr, "C_INIT_AgeNoise", "m_bAbsVal", false, value); }
    bool GetAbsValInv() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_AgeNoise", "m_bAbsValInv"); }
    void SetAbsValInv(bool value) { SetSchemaValue(m_ptr, "C_INIT_AgeNoise", "m_bAbsValInv", false, value); }
    float GetOffset() const { return GetSchemaValue<float>(m_ptr, "C_INIT_AgeNoise", "m_flOffset"); }
    void SetOffset(float value) { SetSchemaValue(m_ptr, "C_INIT_AgeNoise", "m_flOffset", false, value); }
    float GetAgeMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_AgeNoise", "m_flAgeMin"); }
    void SetAgeMin(float value) { SetSchemaValue(m_ptr, "C_INIT_AgeNoise", "m_flAgeMin", false, value); }
    float GetAgeMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_AgeNoise", "m_flAgeMax"); }
    void SetAgeMax(float value) { SetSchemaValue(m_ptr, "C_INIT_AgeNoise", "m_flAgeMax", false, value); }
    float GetNoiseScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_AgeNoise", "m_flNoiseScale"); }
    void SetNoiseScale(float value) { SetSchemaValue(m_ptr, "C_INIT_AgeNoise", "m_flNoiseScale", false, value); }
    float GetNoiseScaleLoc() const { return GetSchemaValue<float>(m_ptr, "C_INIT_AgeNoise", "m_flNoiseScaleLoc"); }
    void SetNoiseScaleLoc(float value) { SetSchemaValue(m_ptr, "C_INIT_AgeNoise", "m_flNoiseScaleLoc", false, value); }
    Vector GetOffsetLoc() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_AgeNoise", "m_vecOffsetLoc"); }
    void SetOffsetLoc(Vector value) { SetSchemaValue(m_ptr, "C_INIT_AgeNoise", "m_vecOffsetLoc", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif