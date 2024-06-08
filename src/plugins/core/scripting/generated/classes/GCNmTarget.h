class GCNmTarget;

#ifndef _gccnmtarget_h
#define _gccnmtarget_h

#include "../../../scripting.h"




class GCNmTarget
{
private:
    void *m_ptr;

public:
    GCNmTarget() {}
    GCNmTarget(void *ptr) : m_ptr(ptr) {}

    bool GetIsBoneTarget() const { return GetSchemaValue<bool>(m_ptr, "CNmTarget", "m_bIsBoneTarget"); }
    void SetIsBoneTarget(bool value) { SetSchemaValue(m_ptr, "CNmTarget", "m_bIsBoneTarget", false, value); }
    bool GetIsUsingBoneSpaceOffsets() const { return GetSchemaValue<bool>(m_ptr, "CNmTarget", "m_bIsUsingBoneSpaceOffsets"); }
    void SetIsUsingBoneSpaceOffsets(bool value) { SetSchemaValue(m_ptr, "CNmTarget", "m_bIsUsingBoneSpaceOffsets", false, value); }
    bool GetHasOffsets() const { return GetSchemaValue<bool>(m_ptr, "CNmTarget", "m_bHasOffsets"); }
    void SetHasOffsets(bool value) { SetSchemaValue(m_ptr, "CNmTarget", "m_bHasOffsets", false, value); }
    bool GetIsSet() const { return GetSchemaValue<bool>(m_ptr, "CNmTarget", "m_bIsSet"); }
    void SetIsSet(bool value) { SetSchemaValue(m_ptr, "CNmTarget", "m_bIsSet", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif