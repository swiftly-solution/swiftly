class GCModelConfigElement_SetBodygroupOnAttachedModels;

#ifndef _gccmodelconfigelement_setbodygrouponattachedmodels_h
#define _gccmodelconfigelement_setbodygrouponattachedmodels_h

#include "../../../scripting.h"




class GCModelConfigElement_SetBodygroupOnAttachedModels
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_SetBodygroupOnAttachedModels() {}
    GCModelConfigElement_SetBodygroupOnAttachedModels(void *ptr) : m_ptr(ptr) {}

    CUtlString GetGroupName() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_SetBodygroupOnAttachedModels", "m_GroupName"); }
    void SetGroupName(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_SetBodygroupOnAttachedModels", "m_GroupName", false, value); }
    int32_t GetChoice() const { return GetSchemaValue<int32_t>(m_ptr, "CModelConfigElement_SetBodygroupOnAttachedModels", "m_nChoice"); }
    void SetChoice(int32_t value) { SetSchemaValue(m_ptr, "CModelConfigElement_SetBodygroupOnAttachedModels", "m_nChoice", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif