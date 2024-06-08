class GFeNodeBase_t;

#ifndef _gcfenodebase_t_h
#define _gcfenodebase_t_h

#include "../../../scripting.h"




class GFeNodeBase_t
{
private:
    void *m_ptr;

public:
    GFeNodeBase_t() {}
    GFeNodeBase_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNode"); }
    void SetNode(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeBase_t", "nNode", true, value); }
    std::vector<uint16_t> GetDummy() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeNodeBase_t", "nDummy"); std::vector<uint16_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetDummy(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeNodeBase_t", "nDummy"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeNodeBase_t", "nDummy", true, outValue); }
    uint16_t GetNodeX0() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNodeX0"); }
    void SetNodeX0(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeBase_t", "nNodeX0", true, value); }
    uint16_t GetNodeX1() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNodeX1"); }
    void SetNodeX1(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeBase_t", "nNodeX1", true, value); }
    uint16_t GetNodeY0() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNodeY0"); }
    void SetNodeY0(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeBase_t", "nNodeY0", true, value); }
    uint16_t GetNodeY1() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeBase_t", "nNodeY1"); }
    void SetNodeY1(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeBase_t", "nNodeY1", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif