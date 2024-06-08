class GCConstraintTarget;

#ifndef _gccconstrainttarget_h
#define _gccconstrainttarget_h

#include "../../../scripting.h"




class GCConstraintTarget
{
private:
    void *m_ptr;

public:
    GCConstraintTarget() {}
    GCConstraintTarget(void *ptr) : m_ptr(ptr) {}

    Quaternion GetOffset() const { return GetSchemaValue<Quaternion>(m_ptr, "CConstraintTarget", "m_qOffset"); }
    void SetOffset(Quaternion value) { SetSchemaValue(m_ptr, "CConstraintTarget", "m_qOffset", false, value); }
    Vector GetOffset1() const { return GetSchemaValue<Vector>(m_ptr, "CConstraintTarget", "m_vOffset"); }
    void SetOffset1(Vector value) { SetSchemaValue(m_ptr, "CConstraintTarget", "m_vOffset", false, value); }
    uint32_t GetBoneHash() const { return GetSchemaValue<uint32_t>(m_ptr, "CConstraintTarget", "m_nBoneHash"); }
    void SetBoneHash(uint32_t value) { SetSchemaValue(m_ptr, "CConstraintTarget", "m_nBoneHash", false, value); }
    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CConstraintTarget", "m_sName"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CConstraintTarget", "m_sName", false, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "CConstraintTarget", "m_flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "CConstraintTarget", "m_flWeight", false, value); }
    bool GetIsAttachment() const { return GetSchemaValue<bool>(m_ptr, "CConstraintTarget", "m_bIsAttachment"); }
    void SetIsAttachment(bool value) { SetSchemaValue(m_ptr, "CConstraintTarget", "m_bIsAttachment", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif