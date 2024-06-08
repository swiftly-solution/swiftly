class GC_OP_SetParentControlPointsToChildCP;

#ifndef _gcc_op_setparentcontrolpointstochildcp_h
#define _gcc_op_setparentcontrolpointstochildcp_h

#include "../../../scripting.h"




class GC_OP_SetParentControlPointsToChildCP
{
private:
    void *m_ptr;

public:
    GC_OP_SetParentControlPointsToChildCP() {}
    GC_OP_SetParentControlPointsToChildCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_nChildGroupID", false, value); }
    int32_t GetChildControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_nChildControlPoint"); }
    void SetChildControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_nChildControlPoint", false, value); }
    int32_t GetNumControlPoints() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_nNumControlPoints"); }
    void SetNumControlPoints(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_nNumControlPoints", false, value); }
    int32_t GetFirstSourcePoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_nFirstSourcePoint"); }
    void SetFirstSourcePoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_nFirstSourcePoint", false, value); }
    bool GetSetOrientation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_bSetOrientation"); }
    void SetSetOrientation(bool value) { SetSchemaValue(m_ptr, "C_OP_SetParentControlPointsToChildCP", "m_bSetOrientation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif