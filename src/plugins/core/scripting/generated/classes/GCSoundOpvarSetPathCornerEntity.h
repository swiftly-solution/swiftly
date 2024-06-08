class GCSoundOpvarSetPathCornerEntity;

#ifndef _gccsoundopvarsetpathcornerentity_h
#define _gccsoundopvarsetpathcornerentity_h

#include "../../../scripting.h"




class GCSoundOpvarSetPathCornerEntity
{
private:
    void *m_ptr;

public:
    GCSoundOpvarSetPathCornerEntity() {}
    GCSoundOpvarSetPathCornerEntity(void *ptr) : m_ptr(ptr) {}

    float GetDistMinSqr() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_flDistMinSqr"); }
    void SetDistMinSqr(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_flDistMinSqr", false, value); }
    float GetDistMaxSqr() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_flDistMaxSqr"); }
    void SetDistMaxSqr(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_flDistMaxSqr", false, value); }
    CUtlSymbolLarge GetPathCornerEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_iszPathCornerEntityName"); }
    void SetPathCornerEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_iszPathCornerEntityName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif