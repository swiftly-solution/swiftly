class GC_OP_DistanceCull;

#ifndef _gcc_op_distancecull_h
#define _gcc_op_distancecull_h

#include "../../../scripting.h"




class GC_OP_DistanceCull
{
private:
    void *m_ptr;

public:
    GC_OP_DistanceCull() {}
    GC_OP_DistanceCull(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DistanceCull", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceCull", "m_nControlPoint", false, value); }
    Vector GetPointOffset() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_DistanceCull", "m_vecPointOffset"); }
    void SetPointOffset(Vector value) { SetSchemaValue(m_ptr, "C_OP_DistanceCull", "m_vecPointOffset", false, value); }
    float GetDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceCull", "m_flDistance"); }
    void SetDistance(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceCull", "m_flDistance", false, value); }
    bool GetCullInside() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DistanceCull", "m_bCullInside"); }
    void SetCullInside(bool value) { SetSchemaValue(m_ptr, "C_OP_DistanceCull", "m_bCullInside", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif