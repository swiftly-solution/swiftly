class GFeCtrlOsOffset_t;

#ifndef _gcfectrlosoffset_t_h
#define _gcfectrlosoffset_t_h

#include "../../../scripting.h"




class GFeCtrlOsOffset_t
{
private:
    void *m_ptr;

public:
    GFeCtrlOsOffset_t() {}
    GFeCtrlOsOffset_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetCtrlParent() const { return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlOsOffset_t", "nCtrlParent"); }
    void SetCtrlParent(uint16_t value) { SetSchemaValue(m_ptr, "FeCtrlOsOffset_t", "nCtrlParent", true, value); }
    uint16_t GetCtrlChild() const { return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlOsOffset_t", "nCtrlChild"); }
    void SetCtrlChild(uint16_t value) { SetSchemaValue(m_ptr, "FeCtrlOsOffset_t", "nCtrlChild", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif