class GFeCollisionPlane_t;

#ifndef _gcfecollisionplane_t_h
#define _gcfecollisionplane_t_h

#include "../../../scripting.h"


#include "GRnPlane_t.h"

class GFeCollisionPlane_t
{
private:
    void *m_ptr;

public:
    GFeCollisionPlane_t() {}
    GFeCollisionPlane_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetCtrlParent() const { return GetSchemaValue<uint16_t>(m_ptr, "FeCollisionPlane_t", "nCtrlParent"); }
    void SetCtrlParent(uint16_t value) { SetSchemaValue(m_ptr, "FeCollisionPlane_t", "nCtrlParent", true, value); }
    uint16_t GetChildNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeCollisionPlane_t", "nChildNode"); }
    void SetChildNode(uint16_t value) { SetSchemaValue(m_ptr, "FeCollisionPlane_t", "nChildNode", true, value); }
    GRnPlane_t GetPlane() const { return GetSchemaValue<GRnPlane_t>(m_ptr, "FeCollisionPlane_t", "m_Plane"); }
    void SetPlane(GRnPlane_t value) { SetSchemaValue(m_ptr, "FeCollisionPlane_t", "m_Plane", true, value); }
    float GetStrength() const { return GetSchemaValue<float>(m_ptr, "FeCollisionPlane_t", "flStrength"); }
    void SetStrength(float value) { SetSchemaValue(m_ptr, "FeCollisionPlane_t", "flStrength", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif