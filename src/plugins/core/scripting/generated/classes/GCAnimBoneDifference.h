class GCAnimBoneDifference;

#ifndef _gccanimbonedifference_h
#define _gccanimbonedifference_h

#include "../../../scripting.h"




class GCAnimBoneDifference
{
private:
    void *m_ptr;

public:
    GCAnimBoneDifference() {}
    GCAnimBoneDifference(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimBoneDifference", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_name", false, value); }
    CBufferString GetParent() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimBoneDifference", "m_parent"); }
    void SetParent(CBufferString value) { SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_parent", false, value); }
    Vector GetPosError() const { return GetSchemaValue<Vector>(m_ptr, "CAnimBoneDifference", "m_posError"); }
    void SetPosError(Vector value) { SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_posError", false, value); }
    bool GetHasRotation() const { return GetSchemaValue<bool>(m_ptr, "CAnimBoneDifference", "m_bHasRotation"); }
    void SetHasRotation(bool value) { SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_bHasRotation", false, value); }
    bool GetHasMovement() const { return GetSchemaValue<bool>(m_ptr, "CAnimBoneDifference", "m_bHasMovement"); }
    void SetHasMovement(bool value) { SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_bHasMovement", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif