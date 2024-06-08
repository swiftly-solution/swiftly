class GFeNodeWindBase_t;

#ifndef _gcfenodewindbase_t_h
#define _gcfenodewindbase_t_h

#include "../../../scripting.h"




class GFeNodeWindBase_t
{
private:
    void *m_ptr;

public:
    GFeNodeWindBase_t() {}
    GFeNodeWindBase_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetNodeX0() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeWindBase_t", "nNodeX0"); }
    void SetNodeX0(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeWindBase_t", "nNodeX0", true, value); }
    uint16_t GetNodeX1() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeWindBase_t", "nNodeX1"); }
    void SetNodeX1(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeWindBase_t", "nNodeX1", true, value); }
    uint16_t GetNodeY0() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeWindBase_t", "nNodeY0"); }
    void SetNodeY0(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeWindBase_t", "nNodeY0", true, value); }
    uint16_t GetNodeY1() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeWindBase_t", "nNodeY1"); }
    void SetNodeY1(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeWindBase_t", "nNodeY1", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif