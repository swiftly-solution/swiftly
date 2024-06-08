class GCBoneConstraintPoseSpaceBone;

#ifndef _gccboneconstraintposespacebone_h
#define _gccboneconstraintposespacebone_h

#include "../../../scripting.h"


#include "GCBoneConstraintPoseSpaceBone.h"

class GCBoneConstraintPoseSpaceBone
{
private:
    void *m_ptr;

public:
    GCBoneConstraintPoseSpaceBone() {}
    GCBoneConstraintPoseSpaceBone(void *ptr) : m_ptr(ptr) {}

    std::vector<GCBoneConstraintPoseSpaceBone> GetInputList() const { CUtlVector<GCBoneConstraintPoseSpaceBone>* vec = GetSchemaValue<CUtlVector<GCBoneConstraintPoseSpaceBone>*>(m_ptr, "CBoneConstraintPoseSpaceBone", "m_inputList"); std::vector<GCBoneConstraintPoseSpaceBone> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInputList(std::vector<GCBoneConstraintPoseSpaceBone> value) { SetSchemaValueCUtlVector<GCBoneConstraintPoseSpaceBone>(m_ptr, "CBoneConstraintPoseSpaceBone", "m_inputList", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif