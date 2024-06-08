class GCAnimLocalHierarchy;

#ifndef _gccanimlocalhierarchy_h
#define _gccanimlocalhierarchy_h

#include "../../../scripting.h"




class GCAnimLocalHierarchy
{
private:
    void *m_ptr;

public:
    GCAnimLocalHierarchy() {}
    GCAnimLocalHierarchy(void *ptr) : m_ptr(ptr) {}

    CBufferString GetBone() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimLocalHierarchy", "m_sBone"); }
    void SetBone(CBufferString value) { SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_sBone", false, value); }
    CBufferString GetNewParent() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimLocalHierarchy", "m_sNewParent"); }
    void SetNewParent(CBufferString value) { SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_sNewParent", false, value); }
    int32_t GetStartFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimLocalHierarchy", "m_nStartFrame"); }
    void SetStartFrame(int32_t value) { SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_nStartFrame", false, value); }
    int32_t GetPeakFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimLocalHierarchy", "m_nPeakFrame"); }
    void SetPeakFrame(int32_t value) { SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_nPeakFrame", false, value); }
    int32_t GetTailFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimLocalHierarchy", "m_nTailFrame"); }
    void SetTailFrame(int32_t value) { SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_nTailFrame", false, value); }
    int32_t GetEndFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimLocalHierarchy", "m_nEndFrame"); }
    void SetEndFrame(int32_t value) { SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_nEndFrame", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif