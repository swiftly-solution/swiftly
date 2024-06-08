class GTagSpan_t;

#ifndef _gctagspan_t_h
#define _gctagspan_t_h

#include "../../../scripting.h"




class GTagSpan_t
{
private:
    void *m_ptr;

public:
    GTagSpan_t() {}
    GTagSpan_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetTagIndex() const { return GetSchemaValue<int32_t>(m_ptr, "TagSpan_t", "m_tagIndex"); }
    void SetTagIndex(int32_t value) { SetSchemaValue(m_ptr, "TagSpan_t", "m_tagIndex", true, value); }
    float GetStartCycle() const { return GetSchemaValue<float>(m_ptr, "TagSpan_t", "m_startCycle"); }
    void SetStartCycle(float value) { SetSchemaValue(m_ptr, "TagSpan_t", "m_startCycle", true, value); }
    float GetEndCycle() const { return GetSchemaValue<float>(m_ptr, "TagSpan_t", "m_endCycle"); }
    void SetEndCycle(float value) { SetSchemaValue(m_ptr, "TagSpan_t", "m_endCycle", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif