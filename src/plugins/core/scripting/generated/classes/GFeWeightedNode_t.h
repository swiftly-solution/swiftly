class GFeWeightedNode_t;

#ifndef _gcfeweightednode_t_h
#define _gcfeweightednode_t_h

#include "../../../scripting.h"




class GFeWeightedNode_t
{
private:
    void *m_ptr;

public:
    GFeWeightedNode_t() {}
    GFeWeightedNode_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeWeightedNode_t", "nNode"); }
    void SetNode(uint16_t value) { SetSchemaValue(m_ptr, "FeWeightedNode_t", "nNode", true, value); }
    uint16_t GetWeight() const { return GetSchemaValue<uint16_t>(m_ptr, "FeWeightedNode_t", "nWeight"); }
    void SetWeight(uint16_t value) { SetSchemaValue(m_ptr, "FeWeightedNode_t", "nWeight", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif