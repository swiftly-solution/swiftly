class GCBoneConstraintPoseSpaceBone__Input_t;

#ifndef _gccboneconstraintposespacebone__input_t_h
#define _gccboneconstraintposespacebone__input_t_h

#include "../../../scripting.h"




class GCBoneConstraintPoseSpaceBone__Input_t
{
private:
    void *m_ptr;

public:
    GCBoneConstraintPoseSpaceBone__Input_t() {}
    GCBoneConstraintPoseSpaceBone__Input_t(void *ptr) : m_ptr(ptr) {}

    Vector GetInputValue() const { return GetSchemaValue<Vector>(m_ptr, "CBoneConstraintPoseSpaceBone__Input_t", "m_inputValue"); }
    void SetInputValue(Vector value) { SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceBone__Input_t", "m_inputValue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif