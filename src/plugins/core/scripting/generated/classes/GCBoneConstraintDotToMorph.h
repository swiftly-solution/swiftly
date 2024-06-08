class GCBoneConstraintDotToMorph;

#ifndef _gccboneconstraintdottomorph_h
#define _gccboneconstraintdottomorph_h

#include "../../../scripting.h"




class GCBoneConstraintDotToMorph
{
private:
    void *m_ptr;

public:
    GCBoneConstraintDotToMorph() {}
    GCBoneConstraintDotToMorph(void *ptr) : m_ptr(ptr) {}

    CUtlString GetBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintDotToMorph", "m_sBoneName"); }
    void SetBoneName(CUtlString value) { SetSchemaValue(m_ptr, "CBoneConstraintDotToMorph", "m_sBoneName", false, value); }
    CUtlString GetTargetBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintDotToMorph", "m_sTargetBoneName"); }
    void SetTargetBoneName(CUtlString value) { SetSchemaValue(m_ptr, "CBoneConstraintDotToMorph", "m_sTargetBoneName", false, value); }
    CUtlString GetMorphChannelName() const { return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintDotToMorph", "m_sMorphChannelName"); }
    void SetMorphChannelName(CUtlString value) { SetSchemaValue(m_ptr, "CBoneConstraintDotToMorph", "m_sMorphChannelName", false, value); }
    std::vector<float> GetRemap() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CBoneConstraintDotToMorph", "m_flRemap"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetRemap(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CBoneConstraintDotToMorph", "m_flRemap"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CBoneConstraintDotToMorph", "m_flRemap", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif