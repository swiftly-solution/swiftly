class GParamSpanSample_t;

#ifndef _gcparamspansample_t_h
#define _gcparamspansample_t_h

#include "../../../scripting.h"




class GParamSpanSample_t
{
private:
    void *m_ptr;

public:
    GParamSpanSample_t() {}
    GParamSpanSample_t(void *ptr) : m_ptr(ptr) {}

    float GetCycle() const { return GetSchemaValue<float>(m_ptr, "ParamSpanSample_t", "m_flCycle"); }
    void SetCycle(float value) { SetSchemaValue(m_ptr, "ParamSpanSample_t", "m_flCycle", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif