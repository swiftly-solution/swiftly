class GFeSimdQuad_t;

#ifndef _gcfesimdquad_t_h
#define _gcfesimdquad_t_h

#include "../../../scripting.h"




class GFeSimdQuad_t
{
private:
    void *m_ptr;

public:
    GFeSimdQuad_t() {}
    GFeSimdQuad_t(void *ptr) : m_ptr(ptr) {}

    float Get4Slack() const { return GetSchemaValue<float>(m_ptr, "FeSimdQuad_t", "f4Slack"); }
    void Set4Slack(float value) { SetSchemaValue(m_ptr, "FeSimdQuad_t", "f4Slack", true, value); }
    std::vector<float> Get4Weights() const { float* outValue = GetSchemaValue<float*>(m_ptr, "FeSimdQuad_t", "f4Weights"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void Set4Weights(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "FeSimdQuad_t", "f4Weights"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdQuad_t", "f4Weights", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif