class GFeBoxRigid_t;

#ifndef _gcfeboxrigid_t_h
#define _gcfeboxrigid_t_h

#include "../../../scripting.h"




class GFeBoxRigid_t
{
private:
    void *m_ptr;

public:
    GFeBoxRigid_t() {}
    GFeBoxRigid_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeBoxRigid_t", "nNode"); }
    void SetNode(uint16_t value) { SetSchemaValue(m_ptr, "FeBoxRigid_t", "nNode", true, value); }
    uint16_t GetCollisionMask() const { return GetSchemaValue<uint16_t>(m_ptr, "FeBoxRigid_t", "nCollisionMask"); }
    void SetCollisionMask(uint16_t value) { SetSchemaValue(m_ptr, "FeBoxRigid_t", "nCollisionMask", true, value); }
    Vector GetSize() const { return GetSchemaValue<Vector>(m_ptr, "FeBoxRigid_t", "vSize"); }
    void SetSize(Vector value) { SetSchemaValue(m_ptr, "FeBoxRigid_t", "vSize", true, value); }
    uint16_t GetVertexMapIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "FeBoxRigid_t", "nVertexMapIndex"); }
    void SetVertexMapIndex(uint16_t value) { SetSchemaValue(m_ptr, "FeBoxRigid_t", "nVertexMapIndex", true, value); }
    uint16_t GetFlags() const { return GetSchemaValue<uint16_t>(m_ptr, "FeBoxRigid_t", "nFlags"); }
    void SetFlags(uint16_t value) { SetSchemaValue(m_ptr, "FeBoxRigid_t", "nFlags", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif