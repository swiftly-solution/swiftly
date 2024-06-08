class GFeFollowNode_t;

#ifndef _gcfefollownode_t_h
#define _gcfefollownode_t_h

#include "../../../scripting.h"




class GFeFollowNode_t
{
private:
    void *m_ptr;

public:
    GFeFollowNode_t() {}
    GFeFollowNode_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetParentNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeFollowNode_t", "nParentNode"); }
    void SetParentNode(uint16_t value) { SetSchemaValue(m_ptr, "FeFollowNode_t", "nParentNode", true, value); }
    uint16_t GetChildNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeFollowNode_t", "nChildNode"); }
    void SetChildNode(uint16_t value) { SetSchemaValue(m_ptr, "FeFollowNode_t", "nChildNode", true, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "FeFollowNode_t", "flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "FeFollowNode_t", "flWeight", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif