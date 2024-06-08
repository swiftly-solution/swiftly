class GCPhysFixed;

#ifndef _gccphysfixed_h
#define _gccphysfixed_h

#include "../../../scripting.h"




class GCPhysFixed
{
private:
    void *m_ptr;

public:
    GCPhysFixed() {}
    GCPhysFixed(void *ptr) : m_ptr(ptr) {}

    float GetLinearFrequency() const { return GetSchemaValue<float>(m_ptr, "CPhysFixed", "m_flLinearFrequency"); }
    void SetLinearFrequency(float value) { SetSchemaValue(m_ptr, "CPhysFixed", "m_flLinearFrequency", false, value); }
    float GetLinearDampingRatio() const { return GetSchemaValue<float>(m_ptr, "CPhysFixed", "m_flLinearDampingRatio"); }
    void SetLinearDampingRatio(float value) { SetSchemaValue(m_ptr, "CPhysFixed", "m_flLinearDampingRatio", false, value); }
    float GetAngularFrequency() const { return GetSchemaValue<float>(m_ptr, "CPhysFixed", "m_flAngularFrequency"); }
    void SetAngularFrequency(float value) { SetSchemaValue(m_ptr, "CPhysFixed", "m_flAngularFrequency", false, value); }
    float GetAngularDampingRatio() const { return GetSchemaValue<float>(m_ptr, "CPhysFixed", "m_flAngularDampingRatio"); }
    void SetAngularDampingRatio(float value) { SetSchemaValue(m_ptr, "CPhysFixed", "m_flAngularDampingRatio", false, value); }
    bool GetEnableLinearConstraint() const { return GetSchemaValue<bool>(m_ptr, "CPhysFixed", "m_bEnableLinearConstraint"); }
    void SetEnableLinearConstraint(bool value) { SetSchemaValue(m_ptr, "CPhysFixed", "m_bEnableLinearConstraint", false, value); }
    bool GetEnableAngularConstraint() const { return GetSchemaValue<bool>(m_ptr, "CPhysFixed", "m_bEnableAngularConstraint"); }
    void SetEnableAngularConstraint(bool value) { SetSchemaValue(m_ptr, "CPhysFixed", "m_bEnableAngularConstraint", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif