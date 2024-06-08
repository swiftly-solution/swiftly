class GC_OP_SetChildControlPoints;

#ifndef _gcc_op_setchildcontrolpoints_h
#define _gcc_op_setchildcontrolpoints_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetChildControlPoints
{
private:
    void *m_ptr;

public:
    GC_OP_SetChildControlPoints() {}
    GC_OP_SetChildControlPoints(void *ptr) : m_ptr(ptr) {}

    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetChildControlPoints", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetChildControlPoints", "m_nChildGroupID", false, value); }
    int32_t GetFirstControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetChildControlPoints", "m_nFirstControlPoint"); }
    void SetFirstControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetChildControlPoints", "m_nFirstControlPoint", false, value); }
    int32_t GetNumControlPoints() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetChildControlPoints", "m_nNumControlPoints"); }
    void SetNumControlPoints(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetChildControlPoints", "m_nNumControlPoints", false, value); }
    GCParticleCollectionFloatInput GetFirstSourcePoint() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetChildControlPoints", "m_nFirstSourcePoint"); }
    void SetFirstSourcePoint(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetChildControlPoints", "m_nFirstSourcePoint", false, value); }
    bool GetReverse() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetChildControlPoints", "m_bReverse"); }
    void SetReverse(bool value) { SetSchemaValue(m_ptr, "C_OP_SetChildControlPoints", "m_bReverse", false, value); }
    bool GetSetOrientation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetChildControlPoints", "m_bSetOrientation"); }
    void SetSetOrientation(bool value) { SetSchemaValue(m_ptr, "C_OP_SetChildControlPoints", "m_bSetOrientation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif