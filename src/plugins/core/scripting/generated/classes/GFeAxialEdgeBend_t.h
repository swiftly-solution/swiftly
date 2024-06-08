class GFeAxialEdgeBend_t;

#ifndef _gcfeaxialedgebend_t_h
#define _gcfeaxialedgebend_t_h

#include "../../../scripting.h"




class GFeAxialEdgeBend_t
{
private:
    void *m_ptr;

public:
    GFeAxialEdgeBend_t() {}
    GFeAxialEdgeBend_t(void *ptr) : m_ptr(ptr) {}

    float GetTe() const { return GetSchemaValue<float>(m_ptr, "FeAxialEdgeBend_t", "te"); }
    void SetTe(float value) { SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "te", true, value); }
    float GetTv() const { return GetSchemaValue<float>(m_ptr, "FeAxialEdgeBend_t", "tv"); }
    void SetTv(float value) { SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "tv", true, value); }
    float GetDist() const { return GetSchemaValue<float>(m_ptr, "FeAxialEdgeBend_t", "flDist"); }
    void SetDist(float value) { SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "flDist", true, value); }
    std::vector<float> GetWeight() const { float* outValue = GetSchemaValue<float*>(m_ptr, "FeAxialEdgeBend_t", "flWeight"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetWeight(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "FeAxialEdgeBend_t", "flWeight"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "flWeight", true, outValue); }
    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeAxialEdgeBend_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 6; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeAxialEdgeBend_t", "nNode"); for(int i = 0; i < 6; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeAxialEdgeBend_t", "nNode", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif