class GCMotorController;

#ifndef _gccmotorcontroller_h
#define _gccmotorcontroller_h

#include "../../../scripting.h"




class GCMotorController
{
private:
    void *m_ptr;

public:
    GCMotorController() {}
    GCMotorController(void *ptr) : m_ptr(ptr) {}

    float GetSpeed() const { return GetSchemaValue<float>(m_ptr, "CMotorController", "m_speed"); }
    void SetSpeed(float value) { SetSchemaValue(m_ptr, "CMotorController", "m_speed", false, value); }
    float GetMaxTorque() const { return GetSchemaValue<float>(m_ptr, "CMotorController", "m_maxTorque"); }
    void SetMaxTorque(float value) { SetSchemaValue(m_ptr, "CMotorController", "m_maxTorque", false, value); }
    Vector GetAxis() const { return GetSchemaValue<Vector>(m_ptr, "CMotorController", "m_axis"); }
    void SetAxis(Vector value) { SetSchemaValue(m_ptr, "CMotorController", "m_axis", false, value); }
    float GetInertiaFactor() const { return GetSchemaValue<float>(m_ptr, "CMotorController", "m_inertiaFactor"); }
    void SetInertiaFactor(float value) { SetSchemaValue(m_ptr, "CMotorController", "m_inertiaFactor", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif