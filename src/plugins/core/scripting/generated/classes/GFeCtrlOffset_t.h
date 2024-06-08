class GFeCtrlOffset_t;

#ifndef _gcfectrloffset_t_h
#define _gcfectrloffset_t_h

#include "../../../scripting.h"




class GFeCtrlOffset_t
{
private:
    void *m_ptr;

public:
    GFeCtrlOffset_t() {}
    GFeCtrlOffset_t(void *ptr) : m_ptr(ptr) {}

    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "FeCtrlOffset_t", "vOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "FeCtrlOffset_t", "vOffset", true, value); }
    uint16_t GetCtrlParent() const { return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlOffset_t", "nCtrlParent"); }
    void SetCtrlParent(uint16_t value) { SetSchemaValue(m_ptr, "FeCtrlOffset_t", "nCtrlParent", true, value); }
    uint16_t GetCtrlChild() const { return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlOffset_t", "nCtrlChild"); }
    void SetCtrlChild(uint16_t value) { SetSchemaValue(m_ptr, "FeCtrlOffset_t", "nCtrlChild", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif