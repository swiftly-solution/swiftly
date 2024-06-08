class GCModelConfigElement_SetMaterialGroup;

#ifndef _gccmodelconfigelement_setmaterialgroup_h
#define _gccmodelconfigelement_setmaterialgroup_h

#include "../../../scripting.h"




class GCModelConfigElement_SetMaterialGroup
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_SetMaterialGroup() {}
    GCModelConfigElement_SetMaterialGroup(void *ptr) : m_ptr(ptr) {}

    CUtlString GetMaterialGroupName() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_SetMaterialGroup", "m_MaterialGroupName"); }
    void SetMaterialGroupName(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_SetMaterialGroup", "m_MaterialGroupName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif