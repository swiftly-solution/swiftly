class GRnNode_t;

#ifndef _gcrnnode_t_h
#define _gcrnnode_t_h

#include "../../../scripting.h"




class GRnNode_t
{
private:
    void *m_ptr;

public:
    GRnNode_t() {}
    GRnNode_t(void *ptr) : m_ptr(ptr) {}

    Vector GetMin() const { return GetSchemaValue<Vector>(m_ptr, "RnNode_t", "m_vMin"); }
    void SetMin(Vector value) { SetSchemaValue(m_ptr, "RnNode_t", "m_vMin", true, value); }
    uint32_t GetChildren() const { return GetSchemaValue<uint32_t>(m_ptr, "RnNode_t", "m_nChildren"); }
    void SetChildren(uint32_t value) { SetSchemaValue(m_ptr, "RnNode_t", "m_nChildren", true, value); }
    Vector GetMax() const { return GetSchemaValue<Vector>(m_ptr, "RnNode_t", "m_vMax"); }
    void SetMax(Vector value) { SetSchemaValue(m_ptr, "RnNode_t", "m_vMax", true, value); }
    uint32_t GetTriangleOffset() const { return GetSchemaValue<uint32_t>(m_ptr, "RnNode_t", "m_nTriangleOffset"); }
    void SetTriangleOffset(uint32_t value) { SetSchemaValue(m_ptr, "RnNode_t", "m_nTriangleOffset", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif