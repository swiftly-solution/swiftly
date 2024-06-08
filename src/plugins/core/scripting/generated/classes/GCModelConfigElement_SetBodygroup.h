class GCModelConfigElement_SetBodygroup;

#ifndef _gccmodelconfigelement_setbodygroup_h
#define _gccmodelconfigelement_setbodygroup_h

#include "../../../scripting.h"




class GCModelConfigElement_SetBodygroup
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_SetBodygroup() {}
    GCModelConfigElement_SetBodygroup(void *ptr) : m_ptr(ptr) {}

    CUtlString GetGroupName() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_SetBodygroup", "m_GroupName"); }
    void SetGroupName(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_SetBodygroup", "m_GroupName", false, value); }
    int32_t GetChoice() const { return GetSchemaValue<int32_t>(m_ptr, "CModelConfigElement_SetBodygroup", "m_nChoice"); }
    void SetChoice(int32_t value) { SetSchemaValue(m_ptr, "CModelConfigElement_SetBodygroup", "m_nChoice", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif