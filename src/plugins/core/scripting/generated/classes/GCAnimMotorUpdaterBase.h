class GCAnimMotorUpdaterBase;

#ifndef _gccanimmotorupdaterbase_h
#define _gccanimmotorupdaterbase_h

#include "../../../scripting.h"




class GCAnimMotorUpdaterBase
{
private:
    void *m_ptr;

public:
    GCAnimMotorUpdaterBase() {}
    GCAnimMotorUpdaterBase(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimMotorUpdaterBase", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CAnimMotorUpdaterBase", "m_name", false, value); }
    bool GetDefault() const { return GetSchemaValue<bool>(m_ptr, "CAnimMotorUpdaterBase", "m_bDefault"); }
    void SetDefault(bool value) { SetSchemaValue(m_ptr, "CAnimMotorUpdaterBase", "m_bDefault", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif