class GCSoundEventPathCornerEntity;

#ifndef _gccsoundeventpathcornerentity_h
#define _gccsoundeventpathcornerentity_h

#include "../../../scripting.h"




class GCSoundEventPathCornerEntity
{
private:
    void *m_ptr;

public:
    GCSoundEventPathCornerEntity() {}
    GCSoundEventPathCornerEntity(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetPathCorner() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventPathCornerEntity", "m_iszPathCorner"); }
    void SetPathCorner(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_iszPathCorner", false, value); }
    int32_t GetCountMax() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundEventPathCornerEntity", "m_iCountMax"); }
    void SetCountMax(int32_t value) { SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_iCountMax", false, value); }
    float GetDistanceMax() const { return GetSchemaValue<float>(m_ptr, "CSoundEventPathCornerEntity", "m_flDistanceMax"); }
    void SetDistanceMax(float value) { SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_flDistanceMax", false, value); }
    float GetDistMaxSqr() const { return GetSchemaValue<float>(m_ptr, "CSoundEventPathCornerEntity", "m_flDistMaxSqr"); }
    void SetDistMaxSqr(float value) { SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_flDistMaxSqr", false, value); }
    float GetDotProductMax() const { return GetSchemaValue<float>(m_ptr, "CSoundEventPathCornerEntity", "m_flDotProductMax"); }
    void SetDotProductMax(float value) { SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_flDotProductMax", false, value); }
    bool GetPlaying() const { return GetSchemaValue<bool>(m_ptr, "CSoundEventPathCornerEntity", "m_bPlaying"); }
    void SetPlaying(bool value) { SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_bPlaying", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif