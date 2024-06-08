class GFeNodeReverseOffset_t;

#ifndef _gcfenodereverseoffset_t_h
#define _gcfenodereverseoffset_t_h

#include "../../../scripting.h"




class GFeNodeReverseOffset_t
{
private:
    void *m_ptr;

public:
    GFeNodeReverseOffset_t() {}
    GFeNodeReverseOffset_t(void *ptr) : m_ptr(ptr) {}

    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "FeNodeReverseOffset_t", "vOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "FeNodeReverseOffset_t", "vOffset", true, value); }
    uint16_t GetBoneCtrl() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeReverseOffset_t", "nBoneCtrl"); }
    void SetBoneCtrl(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeReverseOffset_t", "nBoneCtrl", true, value); }
    uint16_t GetTargetNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeNodeReverseOffset_t", "nTargetNode"); }
    void SetTargetNode(uint16_t value) { SetSchemaValue(m_ptr, "FeNodeReverseOffset_t", "nTargetNode", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif