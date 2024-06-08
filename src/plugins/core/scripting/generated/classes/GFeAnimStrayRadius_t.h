class GFeAnimStrayRadius_t;

#ifndef _gcfeanimstrayradius_t_h
#define _gcfeanimstrayradius_t_h

#include "../../../scripting.h"




class GFeAnimStrayRadius_t
{
private:
    void *m_ptr;

public:
    GFeAnimStrayRadius_t() {}
    GFeAnimStrayRadius_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeAnimStrayRadius_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeAnimStrayRadius_t", "nNode"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeAnimStrayRadius_t", "nNode", true, outValue); }
    float GetMaxDist() const { return GetSchemaValue<float>(m_ptr, "FeAnimStrayRadius_t", "flMaxDist"); }
    void SetMaxDist(float value) { SetSchemaValue(m_ptr, "FeAnimStrayRadius_t", "flMaxDist", true, value); }
    float GetRelaxationFactor() const { return GetSchemaValue<float>(m_ptr, "FeAnimStrayRadius_t", "flRelaxationFactor"); }
    void SetRelaxationFactor(float value) { SetSchemaValue(m_ptr, "FeAnimStrayRadius_t", "flRelaxationFactor", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif