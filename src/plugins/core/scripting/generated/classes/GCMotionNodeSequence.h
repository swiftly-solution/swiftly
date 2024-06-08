class GCMotionNodeSequence;

#ifndef _gccmotionnodesequence_h
#define _gccmotionnodesequence_h

#include "../../../scripting.h"


#include "GTagSpan_t.h"

class GCMotionNodeSequence
{
private:
    void *m_ptr;

public:
    GCMotionNodeSequence() {}
    GCMotionNodeSequence(void *ptr) : m_ptr(ptr) {}

    std::vector<GTagSpan_t> GetTags() const { CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CMotionNodeSequence", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTags(std::vector<GTagSpan_t> value) { SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CMotionNodeSequence", "m_tags", false, value); }
    float GetPlaybackSpeed() const { return GetSchemaValue<float>(m_ptr, "CMotionNodeSequence", "m_flPlaybackSpeed"); }
    void SetPlaybackSpeed(float value) { SetSchemaValue(m_ptr, "CMotionNodeSequence", "m_flPlaybackSpeed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif