class GCBoneConstraintPoseSpaceMorph;

#ifndef _gccboneconstraintposespacemorph_h
#define _gccboneconstraintposespacemorph_h

#include "../../../scripting.h"


#include "GCBoneConstraintPoseSpaceMorph.h"

class GCBoneConstraintPoseSpaceMorph
{
private:
    void *m_ptr;

public:
    GCBoneConstraintPoseSpaceMorph() {}
    GCBoneConstraintPoseSpaceMorph(void *ptr) : m_ptr(ptr) {}

    CUtlString GetBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_sBoneName"); }
    void SetBoneName(CUtlString value) { SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_sBoneName", false, value); }
    CUtlString GetAttachmentName() const { return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_sAttachmentName"); }
    void SetAttachmentName(CUtlString value) { SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_sAttachmentName", false, value); }
    std::vector<CUtlString> GetOutputMorph() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_outputMorph"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOutputMorph(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_outputMorph", false, value); }
    std::vector<GCBoneConstraintPoseSpaceMorph> GetInputList() const { CUtlVector<GCBoneConstraintPoseSpaceMorph>* vec = GetSchemaValue<CUtlVector<GCBoneConstraintPoseSpaceMorph>*>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_inputList"); std::vector<GCBoneConstraintPoseSpaceMorph> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInputList(std::vector<GCBoneConstraintPoseSpaceMorph> value) { SetSchemaValueCUtlVector<GCBoneConstraintPoseSpaceMorph>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_inputList", false, value); }
    bool GetClamp() const { return GetSchemaValue<bool>(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_bClamp"); }
    void SetClamp(bool value) { SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceMorph", "m_bClamp", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif