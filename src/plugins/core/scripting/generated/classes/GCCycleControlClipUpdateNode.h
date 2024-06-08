class GCCycleControlClipUpdateNode;

#ifndef _gcccyclecontrolclipupdatenode_h
#define _gcccyclecontrolclipupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimValueSource.h"
#include "GTagSpan_t.h"
#include "GCAnimParamHandle.h"

class GCCycleControlClipUpdateNode
{
private:
    void *m_ptr;

public:
    GCCycleControlClipUpdateNode() {}
    GCCycleControlClipUpdateNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GTagSpan_t> GetTags() const { CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CCycleControlClipUpdateNode", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTags(std::vector<GTagSpan_t> value) { SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CCycleControlClipUpdateNode", "m_tags", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CCycleControlClipUpdateNode", "m_duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CCycleControlClipUpdateNode", "m_duration", false, value); }
    AnimValueSource GetValueSource() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CCycleControlClipUpdateNode", "m_valueSource"); }
    void SetValueSource(AnimValueSource value) { SetSchemaValue(m_ptr, "CCycleControlClipUpdateNode", "m_valueSource", false, value); }
    GCAnimParamHandle GetParamIndex() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CCycleControlClipUpdateNode", "m_paramIndex"); }
    void SetParamIndex(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CCycleControlClipUpdateNode", "m_paramIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif