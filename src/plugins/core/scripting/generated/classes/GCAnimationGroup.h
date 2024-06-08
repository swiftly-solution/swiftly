class GCAnimationGroup;

#ifndef _gccanimationgroup_h
#define _gccanimationgroup_h

#include "../../../scripting.h"


#include "GCAnimKeyData.h"

class GCAnimationGroup
{
private:
    void *m_ptr;

public:
    GCAnimationGroup() {}
    GCAnimationGroup(void *ptr) : m_ptr(ptr) {}

    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CAnimationGroup", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "CAnimationGroup", "m_nFlags", false, value); }
    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimationGroup", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimationGroup", "m_name", false, value); }
    GCAnimKeyData GetDecodeKey() const { return GetSchemaValue<GCAnimKeyData>(m_ptr, "CAnimationGroup", "m_decodeKey"); }
    void SetDecodeKey(GCAnimKeyData value) { SetSchemaValue(m_ptr, "CAnimationGroup", "m_decodeKey", false, value); }
    std::vector<CBufferString> GetScripts() const { CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CAnimationGroup", "m_szScripts"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetScripts(std::vector<CBufferString> value) { SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CAnimationGroup", "m_szScripts", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif