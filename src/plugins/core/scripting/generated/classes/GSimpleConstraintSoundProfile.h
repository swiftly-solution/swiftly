class GSimpleConstraintSoundProfile;

#ifndef _gcsimpleconstraintsoundprofile_h
#define _gcsimpleconstraintsoundprofile_h

#include "../../../scripting.h"


#include "GSimpleConstraintSoundProfile.h"

class GSimpleConstraintSoundProfile
{
private:
    void *m_ptr;

public:
    GSimpleConstraintSoundProfile() {}
    GSimpleConstraintSoundProfile(void *ptr) : m_ptr(ptr) {}

    GSimpleConstraintSoundProfile GetKeypoints() const { return GetSchemaValue<GSimpleConstraintSoundProfile>(m_ptr, "SimpleConstraintSoundProfile", "eKeypoints"); }
    void SetKeypoints(GSimpleConstraintSoundProfile value) { SetSchemaValue(m_ptr, "SimpleConstraintSoundProfile", "eKeypoints", false, value); }
    std::vector<float> GetKeyPoints() const { float* outValue = GetSchemaValue<float*>(m_ptr, "SimpleConstraintSoundProfile", "m_keyPoints"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetKeyPoints(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "SimpleConstraintSoundProfile", "m_keyPoints"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "SimpleConstraintSoundProfile", "m_keyPoints", false, outValue); }
    std::vector<float> GetReversalSoundThresholds() const { float* outValue = GetSchemaValue<float*>(m_ptr, "SimpleConstraintSoundProfile", "m_reversalSoundThresholds"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetReversalSoundThresholds(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "SimpleConstraintSoundProfile", "m_reversalSoundThresholds"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "SimpleConstraintSoundProfile", "m_reversalSoundThresholds", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif