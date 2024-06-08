class GConfigIndex;

#ifndef _gcconfigindex_h
#define _gcconfigindex_h

#include "../../../scripting.h"




class GConfigIndex
{
private:
    void *m_ptr;

public:
    GConfigIndex() {}
    GConfigIndex(void *ptr) : m_ptr(ptr) {}

    uint16_t GetGroup() const { return GetSchemaValue<uint16_t>(m_ptr, "ConfigIndex", "m_nGroup"); }
    void SetGroup(uint16_t value) { SetSchemaValue(m_ptr, "ConfigIndex", "m_nGroup", false, value); }
    uint16_t GetConfig() const { return GetSchemaValue<uint16_t>(m_ptr, "ConfigIndex", "m_nConfig"); }
    void SetConfig(uint16_t value) { SetSchemaValue(m_ptr, "ConfigIndex", "m_nConfig", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif