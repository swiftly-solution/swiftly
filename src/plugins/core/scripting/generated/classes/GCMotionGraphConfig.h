class GCMotionGraphConfig;

#ifndef _gccmotiongraphconfig_h
#define _gccmotiongraphconfig_h

#include "../../../scripting.h"


#include "GMotionIndex.h"

class GCMotionGraphConfig
{
private:
    void *m_ptr;

public:
    GCMotionGraphConfig() {}
    GCMotionGraphConfig(void *ptr) : m_ptr(ptr) {}

    std::vector<float> GetParamValues() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CMotionGraphConfig", "m_paramValues"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetParamValues(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CMotionGraphConfig", "m_paramValues"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_paramValues", false, outValue); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CMotionGraphConfig", "m_flDuration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_flDuration", false, value); }
    GMotionIndex GetMotionIndex() const { return GetSchemaValue<GMotionIndex>(m_ptr, "CMotionGraphConfig", "m_nMotionIndex"); }
    void SetMotionIndex(GMotionIndex value) { SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_nMotionIndex", false, value); }
    int32_t GetSampleStart() const { return GetSchemaValue<int32_t>(m_ptr, "CMotionGraphConfig", "m_nSampleStart"); }
    void SetSampleStart(int32_t value) { SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_nSampleStart", false, value); }
    int32_t GetSampleCount() const { return GetSchemaValue<int32_t>(m_ptr, "CMotionGraphConfig", "m_nSampleCount"); }
    void SetSampleCount(int32_t value) { SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_nSampleCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif