class GFeSimdSpringIntegrator_t;

#ifndef _gcfesimdspringintegrator_t_h
#define _gcfesimdspringintegrator_t_h

#include "../../../scripting.h"




class GFeSimdSpringIntegrator_t
{
private:
    void *m_ptr;

public:
    GFeSimdSpringIntegrator_t() {}
    GFeSimdSpringIntegrator_t(void *ptr) : m_ptr(ptr) {}

    float GetSpringRestLength() const { return GetSchemaValue<float>(m_ptr, "FeSimdSpringIntegrator_t", "flSpringRestLength"); }
    void SetSpringRestLength(float value) { SetSchemaValue(m_ptr, "FeSimdSpringIntegrator_t", "flSpringRestLength", true, value); }
    float GetSpringConstant() const { return GetSchemaValue<float>(m_ptr, "FeSimdSpringIntegrator_t", "flSpringConstant"); }
    void SetSpringConstant(float value) { SetSchemaValue(m_ptr, "FeSimdSpringIntegrator_t", "flSpringConstant", true, value); }
    float GetSpringDamping() const { return GetSchemaValue<float>(m_ptr, "FeSimdSpringIntegrator_t", "flSpringDamping"); }
    void SetSpringDamping(float value) { SetSchemaValue(m_ptr, "FeSimdSpringIntegrator_t", "flSpringDamping", true, value); }
    float GetNodeWeight0() const { return GetSchemaValue<float>(m_ptr, "FeSimdSpringIntegrator_t", "flNodeWeight0"); }
    void SetNodeWeight0(float value) { SetSchemaValue(m_ptr, "FeSimdSpringIntegrator_t", "flNodeWeight0", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif