class GC_OP_PlaneCull;

#ifndef _gcc_op_planecull_h
#define _gcc_op_planecull_h

#include "../../../scripting.h"




class GC_OP_PlaneCull
{
private:
    void *m_ptr;

public:
    GC_OP_PlaneCull() {}
    GC_OP_PlaneCull(void *ptr) : m_ptr(ptr) {}

    int32_t GetPlaneControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PlaneCull", "m_nPlaneControlPoint"); }
    void SetPlaneControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PlaneCull", "m_nPlaneControlPoint", false, value); }
    Vector GetPlaneDirection() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_PlaneCull", "m_vecPlaneDirection"); }
    void SetPlaneDirection(Vector value) { SetSchemaValue(m_ptr, "C_OP_PlaneCull", "m_vecPlaneDirection", false, value); }
    bool GetLocalSpace() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PlaneCull", "m_bLocalSpace"); }
    void SetLocalSpace(bool value) { SetSchemaValue(m_ptr, "C_OP_PlaneCull", "m_bLocalSpace", false, value); }
    float GetPlaneOffset() const { return GetSchemaValue<float>(m_ptr, "C_OP_PlaneCull", "m_flPlaneOffset"); }
    void SetPlaneOffset(float value) { SetSchemaValue(m_ptr, "C_OP_PlaneCull", "m_flPlaneOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif