class GCSoundAreaEntityBase;

#ifndef _gccsoundareaentitybase_h
#define _gccsoundareaentitybase_h

#include "../../../scripting.h"




class GCSoundAreaEntityBase
{
private:
    void *m_ptr;

public:
    GCSoundAreaEntityBase() {}
    GCSoundAreaEntityBase(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CSoundAreaEntityBase", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CSoundAreaEntityBase", "m_bDisabled", false, value); }
    CUtlSymbolLarge GetSoundAreaType() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundAreaEntityBase", "m_iszSoundAreaType"); }
    void SetSoundAreaType(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundAreaEntityBase", "m_iszSoundAreaType", false, value); }
    Vector GetPos() const { return GetSchemaValue<Vector>(m_ptr, "CSoundAreaEntityBase", "m_vPos"); }
    void SetPos(Vector value) { SetSchemaValue(m_ptr, "CSoundAreaEntityBase", "m_vPos", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif