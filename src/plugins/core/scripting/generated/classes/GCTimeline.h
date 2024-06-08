class GCTimeline;

#ifndef _gcctimeline_h
#define _gcctimeline_h

#include "../../../scripting.h"

#include "../types/GTimelineCompression_t.h"


class GCTimeline
{
private:
    void *m_ptr;

public:
    GCTimeline() {}
    GCTimeline(void *ptr) : m_ptr(ptr) {}

    std::vector<float> GetValues() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CTimeline", "m_flValues"); std::vector<float> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetValues(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CTimeline", "m_flValues"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CTimeline", "m_flValues", false, outValue); }
    std::vector<int32_t> GetValueCounts() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CTimeline", "m_nValueCounts"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetValueCounts(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CTimeline", "m_nValueCounts"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CTimeline", "m_nValueCounts", false, outValue); }
    int32_t GetBucketCount() const { return GetSchemaValue<int32_t>(m_ptr, "CTimeline", "m_nBucketCount"); }
    void SetBucketCount(int32_t value) { SetSchemaValue(m_ptr, "CTimeline", "m_nBucketCount", false, value); }
    float GetInterval() const { return GetSchemaValue<float>(m_ptr, "CTimeline", "m_flInterval"); }
    void SetInterval(float value) { SetSchemaValue(m_ptr, "CTimeline", "m_flInterval", false, value); }
    float GetFinalValue() const { return GetSchemaValue<float>(m_ptr, "CTimeline", "m_flFinalValue"); }
    void SetFinalValue(float value) { SetSchemaValue(m_ptr, "CTimeline", "m_flFinalValue", false, value); }
    TimelineCompression_t GetCompressionType() const { return GetSchemaValue<TimelineCompression_t>(m_ptr, "CTimeline", "m_nCompressionType"); }
    void SetCompressionType(TimelineCompression_t value) { SetSchemaValue(m_ptr, "CTimeline", "m_nCompressionType", false, value); }
    bool GetStopped() const { return GetSchemaValue<bool>(m_ptr, "CTimeline", "m_bStopped"); }
    void SetStopped(bool value) { SetSchemaValue(m_ptr, "CTimeline", "m_bStopped", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif