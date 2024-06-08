class GFeTaperedCapsuleRigid_t;

#ifndef _gcfetaperedcapsulerigid_t_h
#define _gcfetaperedcapsulerigid_t_h

#include "../../../scripting.h"




class GFeTaperedCapsuleRigid_t
{
private:
    void *m_ptr;

public:
    GFeTaperedCapsuleRigid_t() {}
    GFeTaperedCapsuleRigid_t(void *ptr) : m_ptr(ptr) {}

    std::vector<float> GetSphere() const { float* outValue = GetSchemaValue<float*>(m_ptr, "FeTaperedCapsuleRigid_t", "vSphere"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetSphere(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "FeTaperedCapsuleRigid_t", "vSphere"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "vSphere", true, outValue); }
    uint16_t GetNode() const { return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleRigid_t", "nNode"); }
    void SetNode(uint16_t value) { SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "nNode", true, value); }
    uint16_t GetCollisionMask() const { return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleRigid_t", "nCollisionMask"); }
    void SetCollisionMask(uint16_t value) { SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "nCollisionMask", true, value); }
    uint16_t GetVertexMapIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleRigid_t", "nVertexMapIndex"); }
    void SetVertexMapIndex(uint16_t value) { SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "nVertexMapIndex", true, value); }
    uint16_t GetFlags() const { return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleRigid_t", "nFlags"); }
    void SetFlags(uint16_t value) { SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "nFlags", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif