class GParamSpan_t;

#ifndef _gcparamspan_t_h
#define _gcparamspan_t_h

#include "../../../scripting.h"

#include "../types/GAnimParamType_t.h"
#include "GParamSpanSample_t.h"
#include "GCAnimParamHandle.h"

class GParamSpan_t
{
private:
    void *m_ptr;

public:
    GParamSpan_t() {}
    GParamSpan_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GParamSpanSample_t> GetSamples() const { CUtlVector<GParamSpanSample_t>* vec = GetSchemaValue<CUtlVector<GParamSpanSample_t>*>(m_ptr, "ParamSpan_t", "m_samples"); std::vector<GParamSpanSample_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSamples(std::vector<GParamSpanSample_t> value) { SetSchemaValueCUtlVector<GParamSpanSample_t>(m_ptr, "ParamSpan_t", "m_samples", true, value); }
    GCAnimParamHandle GetParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "ParamSpan_t", "m_hParam"); }
    void SetParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "ParamSpan_t", "m_hParam", true, value); }
    AnimParamType_t GetParamType() const { return GetSchemaValue<AnimParamType_t>(m_ptr, "ParamSpan_t", "m_eParamType"); }
    void SetParamType(AnimParamType_t value) { SetSchemaValue(m_ptr, "ParamSpan_t", "m_eParamType", true, value); }
    float GetStartCycle() const { return GetSchemaValue<float>(m_ptr, "ParamSpan_t", "m_flStartCycle"); }
    void SetStartCycle(float value) { SetSchemaValue(m_ptr, "ParamSpan_t", "m_flStartCycle", true, value); }
    float GetEndCycle() const { return GetSchemaValue<float>(m_ptr, "ParamSpan_t", "m_flEndCycle"); }
    void SetEndCycle(float value) { SetSchemaValue(m_ptr, "ParamSpan_t", "m_flEndCycle", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif