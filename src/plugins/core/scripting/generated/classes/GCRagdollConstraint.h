class GCRagdollConstraint;

#ifndef _gccragdollconstraint_h
#define _gccragdollconstraint_h

#include "../../../scripting.h"




class GCRagdollConstraint
{
private:
    void *m_ptr;

public:
    GCRagdollConstraint() {}
    GCRagdollConstraint(void *ptr) : m_ptr(ptr) {}

    float GetXmin() const { return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_xmin"); }
    void SetXmin(float value) { SetSchemaValue(m_ptr, "CRagdollConstraint", "m_xmin", false, value); }
    float GetXmax() const { return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_xmax"); }
    void SetXmax(float value) { SetSchemaValue(m_ptr, "CRagdollConstraint", "m_xmax", false, value); }
    float GetYmin() const { return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_ymin"); }
    void SetYmin(float value) { SetSchemaValue(m_ptr, "CRagdollConstraint", "m_ymin", false, value); }
    float GetYmax() const { return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_ymax"); }
    void SetYmax(float value) { SetSchemaValue(m_ptr, "CRagdollConstraint", "m_ymax", false, value); }
    float GetZmin() const { return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_zmin"); }
    void SetZmin(float value) { SetSchemaValue(m_ptr, "CRagdollConstraint", "m_zmin", false, value); }
    float GetZmax() const { return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_zmax"); }
    void SetZmax(float value) { SetSchemaValue(m_ptr, "CRagdollConstraint", "m_zmax", false, value); }
    float GetXfriction() const { return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_xfriction"); }
    void SetXfriction(float value) { SetSchemaValue(m_ptr, "CRagdollConstraint", "m_xfriction", false, value); }
    float GetYfriction() const { return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_yfriction"); }
    void SetYfriction(float value) { SetSchemaValue(m_ptr, "CRagdollConstraint", "m_yfriction", false, value); }
    float GetZfriction() const { return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_zfriction"); }
    void SetZfriction(float value) { SetSchemaValue(m_ptr, "CRagdollConstraint", "m_zfriction", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif