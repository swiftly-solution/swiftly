class GRnBlendVertex_t;

#ifndef _gcrnblendvertex_t_h
#define _gcrnblendvertex_t_h

#include "../../../scripting.h"




class GRnBlendVertex_t
{
private:
    void *m_ptr;

public:
    GRnBlendVertex_t() {}
    GRnBlendVertex_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetWeight0() const { return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nWeight0"); }
    void SetWeight0(uint16_t value) { SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nWeight0", true, value); }
    uint16_t GetIndex0() const { return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nIndex0"); }
    void SetIndex0(uint16_t value) { SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nIndex0", true, value); }
    uint16_t GetWeight1() const { return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nWeight1"); }
    void SetWeight1(uint16_t value) { SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nWeight1", true, value); }
    uint16_t GetIndex1() const { return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nIndex1"); }
    void SetIndex1(uint16_t value) { SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nIndex1", true, value); }
    uint16_t GetWeight2() const { return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nWeight2"); }
    void SetWeight2(uint16_t value) { SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nWeight2", true, value); }
    uint16_t GetIndex2() const { return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nIndex2"); }
    void SetIndex2(uint16_t value) { SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nIndex2", true, value); }
    uint16_t GetFlags() const { return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nFlags"); }
    void SetFlags(uint16_t value) { SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nFlags", true, value); }
    uint16_t GetTargetIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nTargetIndex"); }
    void SetTargetIndex(uint16_t value) { SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nTargetIndex", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif