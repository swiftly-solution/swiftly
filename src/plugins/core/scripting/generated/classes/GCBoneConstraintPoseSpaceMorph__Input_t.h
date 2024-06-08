class GCBoneConstraintPoseSpaceMorph__Input_t;

#ifndef _gccboneconstraintposespacemorph__input_t_h
#define _gccboneconstraintposespacemorph__input_t_h

#include "../../../scripting.h"




class GCBoneConstraintPoseSpaceMorph__Input_t
{
private:
    void *m_ptr;

public:
    GCBoneConstraintPoseSpaceMorph__Input_t() {}
    GCBoneConstraintPoseSpaceMorph__Input_t(void *ptr) : m_ptr(ptr) {}

    Vector GetInputValue() const { return GetSchemaValue<Vector>(m_ptr, "CBoneConstraintPoseSpaceMorph__Input_t", "m_inputValue"); }
    void SetInputValue(Vector value) { SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceMorph__Input_t", "m_inputValue", true, value); }
    std::vector<float32> GetOutputWeightList() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CBoneConstraintPoseSpaceMorph__Input_t", "m_outputWeightList"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOutputWeightList(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CBoneConstraintPoseSpaceMorph__Input_t", "m_outputWeightList", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif