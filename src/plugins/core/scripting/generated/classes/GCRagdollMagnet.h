class GCRagdollMagnet;

#ifndef _gccragdollmagnet_h
#define _gccragdollmagnet_h

#include "../../../scripting.h"




class GCRagdollMagnet
{
private:
    void *m_ptr;

public:
    GCRagdollMagnet() {}
    GCRagdollMagnet(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CRagdollMagnet", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CRagdollMagnet", "m_bDisabled", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CRagdollMagnet", "m_radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CRagdollMagnet", "m_radius", false, value); }
    float GetForce() const { return GetSchemaValue<float>(m_ptr, "CRagdollMagnet", "m_force"); }
    void SetForce(float value) { SetSchemaValue(m_ptr, "CRagdollMagnet", "m_force", false, value); }
    Vector GetAxis() const { return GetSchemaValue<Vector>(m_ptr, "CRagdollMagnet", "m_axis"); }
    void SetAxis(Vector value) { SetSchemaValue(m_ptr, "CRagdollMagnet", "m_axis", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif