class GCSequenceUpdateNode;

#ifndef _gccsequenceupdatenode_h
#define _gccsequenceupdatenode_h

#include "../../../scripting.h"


#include "GCParamSpanUpdater.h"
#include "GTagSpan_t.h"

class GCSequenceUpdateNode
{
private:
    void *m_ptr;

public:
    GCSequenceUpdateNode() {}
    GCSequenceUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCParamSpanUpdater GetParamSpans() const { return GetSchemaValue<GCParamSpanUpdater>(m_ptr, "CSequenceUpdateNode", "m_paramSpans"); }
    void SetParamSpans(GCParamSpanUpdater value) { SetSchemaValue(m_ptr, "CSequenceUpdateNode", "m_paramSpans", false, value); }
    std::vector<GTagSpan_t> GetTags() const { CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CSequenceUpdateNode", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTags(std::vector<GTagSpan_t> value) { SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CSequenceUpdateNode", "m_tags", false, value); }
    float GetPlaybackSpeed() const { return GetSchemaValue<float>(m_ptr, "CSequenceUpdateNode", "m_playbackSpeed"); }
    void SetPlaybackSpeed(float value) { SetSchemaValue(m_ptr, "CSequenceUpdateNode", "m_playbackSpeed", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CSequenceUpdateNode", "m_duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CSequenceUpdateNode", "m_duration", false, value); }
    bool GetLoop() const { return GetSchemaValue<bool>(m_ptr, "CSequenceUpdateNode", "m_bLoop"); }
    void SetLoop(bool value) { SetSchemaValue(m_ptr, "CSequenceUpdateNode", "m_bLoop", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif