class GFeSimdRodConstraint_t;

#ifndef _gcfesimdrodconstraint_t_h
#define _gcfesimdrodconstraint_t_h

#include "../../../scripting.h"




class GFeSimdRodConstraint_t
{
private:
    void *m_ptr;

public:
    GFeSimdRodConstraint_t() {}
    GFeSimdRodConstraint_t(void *ptr) : m_ptr(ptr) {}

    float Get4MaxDist() const { return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraint_t", "f4MaxDist"); }
    void Set4MaxDist(float value) { SetSchemaValue(m_ptr, "FeSimdRodConstraint_t", "f4MaxDist", true, value); }
    float Get4MinDist() const { return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraint_t", "f4MinDist"); }
    void Set4MinDist(float value) { SetSchemaValue(m_ptr, "FeSimdRodConstraint_t", "f4MinDist", true, value); }
    float Get4Weight0() const { return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraint_t", "f4Weight0"); }
    void Set4Weight0(float value) { SetSchemaValue(m_ptr, "FeSimdRodConstraint_t", "f4Weight0", true, value); }
    float Get4RelaxationFactor() const { return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraint_t", "f4RelaxationFactor"); }
    void Set4RelaxationFactor(float value) { SetSchemaValue(m_ptr, "FeSimdRodConstraint_t", "f4RelaxationFactor", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif