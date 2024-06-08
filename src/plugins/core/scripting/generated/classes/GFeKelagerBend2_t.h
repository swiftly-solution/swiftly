class GFeKelagerBend2_t;

#ifndef _gcfekelagerbend2_t_h
#define _gcfekelagerbend2_t_h

#include "../../../scripting.h"




class GFeKelagerBend2_t
{
private:
    void *m_ptr;

public:
    GFeKelagerBend2_t() {}
    GFeKelagerBend2_t(void *ptr) : m_ptr(ptr) {}

    std::vector<float> GetWeight() const { float* outValue = GetSchemaValue<float*>(m_ptr, "FeKelagerBend2_t", "flWeight"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetWeight(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "FeKelagerBend2_t", "flWeight"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeKelagerBend2_t", "flWeight", true, outValue); }
    float GetHeight0() const { return GetSchemaValue<float>(m_ptr, "FeKelagerBend2_t", "flHeight0"); }
    void SetHeight0(float value) { SetSchemaValue(m_ptr, "FeKelagerBend2_t", "flHeight0", true, value); }
    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeKelagerBend2_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeKelagerBend2_t", "nNode"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeKelagerBend2_t", "nNode", true, outValue); }
    uint16_t GetReserved() const { return GetSchemaValue<uint16_t>(m_ptr, "FeKelagerBend2_t", "nReserved"); }
    void SetReserved(uint16_t value) { SetSchemaValue(m_ptr, "FeKelagerBend2_t", "nReserved", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif