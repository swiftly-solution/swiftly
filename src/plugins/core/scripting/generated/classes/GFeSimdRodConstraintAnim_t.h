class GFeSimdRodConstraintAnim_t;

#ifndef _gcfesimdrodconstraintanim_t_h
#define _gcfesimdrodconstraintanim_t_h

#include "../../../scripting.h"




class GFeSimdRodConstraintAnim_t
{
private:
    void *m_ptr;

public:
    GFeSimdRodConstraintAnim_t() {}
    GFeSimdRodConstraintAnim_t(void *ptr) : m_ptr(ptr) {}

    float Get4Weight0() const { return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraintAnim_t", "f4Weight0"); }
    void Set4Weight0(float value) { SetSchemaValue(m_ptr, "FeSimdRodConstraintAnim_t", "f4Weight0", true, value); }
    float Get4RelaxationFactor() const { return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraintAnim_t", "f4RelaxationFactor"); }
    void Set4RelaxationFactor(float value) { SetSchemaValue(m_ptr, "FeSimdRodConstraintAnim_t", "f4RelaxationFactor", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif