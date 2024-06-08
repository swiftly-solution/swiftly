class GCConstraintSlave;

#ifndef _gccconstraintslave_h
#define _gccconstraintslave_h

#include "../../../scripting.h"




class GCConstraintSlave
{
private:
    void *m_ptr;

public:
    GCConstraintSlave() {}
    GCConstraintSlave(void *ptr) : m_ptr(ptr) {}

    Quaternion GetBaseOrientation() const { return GetSchemaValue<Quaternion>(m_ptr, "CConstraintSlave", "m_qBaseOrientation"); }
    void SetBaseOrientation(Quaternion value) { SetSchemaValue(m_ptr, "CConstraintSlave", "m_qBaseOrientation", false, value); }
    Vector GetBasePosition() const { return GetSchemaValue<Vector>(m_ptr, "CConstraintSlave", "m_vBasePosition"); }
    void SetBasePosition(Vector value) { SetSchemaValue(m_ptr, "CConstraintSlave", "m_vBasePosition", false, value); }
    uint32_t GetBoneHash() const { return GetSchemaValue<uint32_t>(m_ptr, "CConstraintSlave", "m_nBoneHash"); }
    void SetBoneHash(uint32_t value) { SetSchemaValue(m_ptr, "CConstraintSlave", "m_nBoneHash", false, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "CConstraintSlave", "m_flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "CConstraintSlave", "m_flWeight", false, value); }
    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CConstraintSlave", "m_sName"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CConstraintSlave", "m_sName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif