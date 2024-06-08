class GFeNodeIntegrator_t;

#ifndef _gcfenodeintegrator_t_h
#define _gcfenodeintegrator_t_h

#include "../../../scripting.h"




class GFeNodeIntegrator_t
{
private:
    void *m_ptr;

public:
    GFeNodeIntegrator_t() {}
    GFeNodeIntegrator_t(void *ptr) : m_ptr(ptr) {}

    float GetPointDamping() const { return GetSchemaValue<float>(m_ptr, "FeNodeIntegrator_t", "flPointDamping"); }
    void SetPointDamping(float value) { SetSchemaValue(m_ptr, "FeNodeIntegrator_t", "flPointDamping", true, value); }
    float GetAnimationForceAttraction() const { return GetSchemaValue<float>(m_ptr, "FeNodeIntegrator_t", "flAnimationForceAttraction"); }
    void SetAnimationForceAttraction(float value) { SetSchemaValue(m_ptr, "FeNodeIntegrator_t", "flAnimationForceAttraction", true, value); }
    float GetAnimationVertexAttraction() const { return GetSchemaValue<float>(m_ptr, "FeNodeIntegrator_t", "flAnimationVertexAttraction"); }
    void SetAnimationVertexAttraction(float value) { SetSchemaValue(m_ptr, "FeNodeIntegrator_t", "flAnimationVertexAttraction", true, value); }
    float GetGravity() const { return GetSchemaValue<float>(m_ptr, "FeNodeIntegrator_t", "flGravity"); }
    void SetGravity(float value) { SetSchemaValue(m_ptr, "FeNodeIntegrator_t", "flGravity", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif