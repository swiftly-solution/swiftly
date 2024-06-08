class GRnSoftbodyCapsule_t;

#ifndef _gcrnsoftbodycapsule_t_h
#define _gcrnsoftbodycapsule_t_h

#include "../../../scripting.h"




class GRnSoftbodyCapsule_t
{
private:
    void *m_ptr;

public:
    GRnSoftbodyCapsule_t() {}
    GRnSoftbodyCapsule_t(void *ptr) : m_ptr(ptr) {}

    std::vector<Vector> GetCenter() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnSoftbodyCapsule_t", "m_vCenter"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetCenter(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnSoftbodyCapsule_t", "m_vCenter"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnSoftbodyCapsule_t", "m_vCenter", true, outValue); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "RnSoftbodyCapsule_t", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "RnSoftbodyCapsule_t", "m_flRadius", true, value); }
    std::vector<uint16_t> GetParticle() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RnSoftbodyCapsule_t", "m_nParticle"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetParticle(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RnSoftbodyCapsule_t", "m_nParticle"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnSoftbodyCapsule_t", "m_nParticle", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif