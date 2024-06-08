class GRnSoftbodySpring_t;

#ifndef _gcrnsoftbodyspring_t_h
#define _gcrnsoftbodyspring_t_h

#include "../../../scripting.h"




class GRnSoftbodySpring_t
{
private:
    void *m_ptr;

public:
    GRnSoftbodySpring_t() {}
    GRnSoftbodySpring_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetParticle() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RnSoftbodySpring_t", "m_nParticle"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetParticle(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RnSoftbodySpring_t", "m_nParticle"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnSoftbodySpring_t", "m_nParticle", true, outValue); }
    float GetLength() const { return GetSchemaValue<float>(m_ptr, "RnSoftbodySpring_t", "m_flLength"); }
    void SetLength(float value) { SetSchemaValue(m_ptr, "RnSoftbodySpring_t", "m_flLength", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif