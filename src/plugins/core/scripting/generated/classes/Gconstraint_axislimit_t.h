class Gconstraint_axislimit_t;

#ifndef _gcconstraint_axislimit_t_h
#define _gcconstraint_axislimit_t_h

#include "../../../scripting.h"




class Gconstraint_axislimit_t
{
private:
    void *m_ptr;

public:
    Gconstraint_axislimit_t() {}
    Gconstraint_axislimit_t(void *ptr) : m_ptr(ptr) {}

    float GetMinRotation() const { return GetSchemaValue<float>(m_ptr, "constraint_axislimit_t", "flMinRotation"); }
    void SetMinRotation(float value) { SetSchemaValue(m_ptr, "constraint_axislimit_t", "flMinRotation", true, value); }
    float GetMaxRotation() const { return GetSchemaValue<float>(m_ptr, "constraint_axislimit_t", "flMaxRotation"); }
    void SetMaxRotation(float value) { SetSchemaValue(m_ptr, "constraint_axislimit_t", "flMaxRotation", true, value); }
    float GetMotorTargetAngSpeed() const { return GetSchemaValue<float>(m_ptr, "constraint_axislimit_t", "flMotorTargetAngSpeed"); }
    void SetMotorTargetAngSpeed(float value) { SetSchemaValue(m_ptr, "constraint_axislimit_t", "flMotorTargetAngSpeed", true, value); }
    float GetMotorMaxTorque() const { return GetSchemaValue<float>(m_ptr, "constraint_axislimit_t", "flMotorMaxTorque"); }
    void SetMotorMaxTorque(float value) { SetSchemaValue(m_ptr, "constraint_axislimit_t", "flMotorMaxTorque", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif