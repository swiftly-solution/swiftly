class GCMotionGraph;

#ifndef _gccmotiongraph_h
#define _gccmotiongraph_h

#include "../../../scripting.h"


#include "GCParamSpanUpdater.h"
#include "GTagSpan_t.h"

class GCMotionGraph
{
private:
    void *m_ptr;

public:
    GCMotionGraph() {}
    GCMotionGraph(void *ptr) : m_ptr(ptr) {}

    GCParamSpanUpdater GetParamSpans() const { return GetSchemaValue<GCParamSpanUpdater>(m_ptr, "CMotionGraph", "m_paramSpans"); }
    void SetParamSpans(GCParamSpanUpdater value) { SetSchemaValue(m_ptr, "CMotionGraph", "m_paramSpans", false, value); }
    std::vector<GTagSpan_t> GetTags() const { CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CMotionGraph", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTags(std::vector<GTagSpan_t> value) { SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CMotionGraph", "m_tags", false, value); }
    int32_t GetParameterCount() const { return GetSchemaValue<int32_t>(m_ptr, "CMotionGraph", "m_nParameterCount"); }
    void SetParameterCount(int32_t value) { SetSchemaValue(m_ptr, "CMotionGraph", "m_nParameterCount", false, value); }
    int32_t GetConfigStartIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CMotionGraph", "m_nConfigStartIndex"); }
    void SetConfigStartIndex(int32_t value) { SetSchemaValue(m_ptr, "CMotionGraph", "m_nConfigStartIndex", false, value); }
    int32_t GetConfigCount() const { return GetSchemaValue<int32_t>(m_ptr, "CMotionGraph", "m_nConfigCount"); }
    void SetConfigCount(int32_t value) { SetSchemaValue(m_ptr, "CMotionGraph", "m_nConfigCount", false, value); }
    bool GetLoop() const { return GetSchemaValue<bool>(m_ptr, "CMotionGraph", "m_bLoop"); }
    void SetLoop(bool value) { SetSchemaValue(m_ptr, "CMotionGraph", "m_bLoop", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif