class GCPhysMotor;

#ifndef _gccphysmotor_h
#define _gccphysmotor_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCMotorController.h"

class GCPhysMotor
{
private:
    void *m_ptr;

public:
    GCPhysMotor() {}
    GCPhysMotor(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetNameAttach() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysMotor", "m_nameAttach"); }
    void SetNameAttach(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysMotor", "m_nameAttach", false, value); }
    GCBaseEntity* GetAttachedObject() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPhysMotor", "m_hAttachedObject"); }
    void SetAttachedObject(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'AttachedObject' is not possible.\n"); }
    float GetSpinUp() const { return GetSchemaValue<float>(m_ptr, "CPhysMotor", "m_spinUp"); }
    void SetSpinUp(float value) { SetSchemaValue(m_ptr, "CPhysMotor", "m_spinUp", false, value); }
    float GetAdditionalAcceleration() const { return GetSchemaValue<float>(m_ptr, "CPhysMotor", "m_additionalAcceleration"); }
    void SetAdditionalAcceleration(float value) { SetSchemaValue(m_ptr, "CPhysMotor", "m_additionalAcceleration", false, value); }
    float GetAngularAcceleration() const { return GetSchemaValue<float>(m_ptr, "CPhysMotor", "m_angularAcceleration"); }
    void SetAngularAcceleration(float value) { SetSchemaValue(m_ptr, "CPhysMotor", "m_angularAcceleration", false, value); }
    GCMotorController GetMotor() const { return GetSchemaValue<GCMotorController>(m_ptr, "CPhysMotor", "m_motor"); }
    void SetMotor(GCMotorController value) { SetSchemaValue(m_ptr, "CPhysMotor", "m_motor", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif