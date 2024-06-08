class GFeSpringIntegrator_t;

#ifndef _gcfespringintegrator_t_h
#define _gcfespringintegrator_t_h

#include "../../../scripting.h"




class GFeSpringIntegrator_t
{
private:
    void *m_ptr;

public:
    GFeSpringIntegrator_t() {}
    GFeSpringIntegrator_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSpringIntegrator_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSpringIntegrator_t", "nNode"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "nNode", true, outValue); }
    float GetSpringRestLength() const { return GetSchemaValue<float>(m_ptr, "FeSpringIntegrator_t", "flSpringRestLength"); }
    void SetSpringRestLength(float value) { SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "flSpringRestLength", true, value); }
    float GetSpringConstant() const { return GetSchemaValue<float>(m_ptr, "FeSpringIntegrator_t", "flSpringConstant"); }
    void SetSpringConstant(float value) { SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "flSpringConstant", true, value); }
    float GetSpringDamping() const { return GetSchemaValue<float>(m_ptr, "FeSpringIntegrator_t", "flSpringDamping"); }
    void SetSpringDamping(float value) { SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "flSpringDamping", true, value); }
    float GetNodeWeight0() const { return GetSchemaValue<float>(m_ptr, "FeSpringIntegrator_t", "flNodeWeight0"); }
    void SetNodeWeight0(float value) { SetSchemaValue(m_ptr, "FeSpringIntegrator_t", "flNodeWeight0", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif