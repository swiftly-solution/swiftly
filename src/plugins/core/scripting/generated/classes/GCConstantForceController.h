class GCConstantForceController;

#ifndef _gccconstantforcecontroller_h
#define _gccconstantforcecontroller_h

#include "../../../scripting.h"




class GCConstantForceController
{
private:
    void *m_ptr;

public:
    GCConstantForceController() {}
    GCConstantForceController(void *ptr) : m_ptr(ptr) {}

    Vector GetLinear() const { return GetSchemaValue<Vector>(m_ptr, "CConstantForceController", "m_linear"); }
    void SetLinear(Vector value) { SetSchemaValue(m_ptr, "CConstantForceController", "m_linear", false, value); }
    Vector GetAngular() const { return GetSchemaValue<Vector>(m_ptr, "CConstantForceController", "m_angular"); }
    void SetAngular(Vector value) { SetSchemaValue(m_ptr, "CConstantForceController", "m_angular", false, value); }
    Vector GetLinearSave() const { return GetSchemaValue<Vector>(m_ptr, "CConstantForceController", "m_linearSave"); }
    void SetLinearSave(Vector value) { SetSchemaValue(m_ptr, "CConstantForceController", "m_linearSave", false, value); }
    Vector GetAngularSave() const { return GetSchemaValue<Vector>(m_ptr, "CConstantForceController", "m_angularSave"); }
    void SetAngularSave(Vector value) { SetSchemaValue(m_ptr, "CConstantForceController", "m_angularSave", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif