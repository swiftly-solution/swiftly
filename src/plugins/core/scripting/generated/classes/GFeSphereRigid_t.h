class GFeSphereRigid_t;

#ifndef _gcfesphererigid_t_h
#define _gcfesphererigid_t_h

#include "../../../scripting.h"




class GFeSphereRigid_t
{
private:
    void *m_ptr;

public:
    GFeSphereRigid_t() {}
    GFeSphereRigid_t(void *ptr) : m_ptr(ptr) {}

    float GetSphere() const { return GetSchemaValue<float>(m_ptr, "FeSphereRigid_t", "vSphere"); }
    void SetSphere(float value) { SetSchemaValue(m_ptr, "FeSphereRigid_t", "vSphere", true, value); }
    uint16_t GetNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeSphereRigid_t", "nNode"); }
    void SetNode(uint16_t value) { SetSchemaValue(m_ptr, "FeSphereRigid_t", "nNode", true, value); }
    uint16_t GetCollisionMask() const { return GetSchemaValue<uint16_t>(m_ptr, "FeSphereRigid_t", "nCollisionMask"); }
    void SetCollisionMask(uint16_t value) { SetSchemaValue(m_ptr, "FeSphereRigid_t", "nCollisionMask", true, value); }
    uint16_t GetVertexMapIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "FeSphereRigid_t", "nVertexMapIndex"); }
    void SetVertexMapIndex(uint16_t value) { SetSchemaValue(m_ptr, "FeSphereRigid_t", "nVertexMapIndex", true, value); }
    uint16_t GetFlags() const { return GetSchemaValue<uint16_t>(m_ptr, "FeSphereRigid_t", "nFlags"); }
    void SetFlags(uint16_t value) { SetSchemaValue(m_ptr, "FeSphereRigid_t", "nFlags", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif