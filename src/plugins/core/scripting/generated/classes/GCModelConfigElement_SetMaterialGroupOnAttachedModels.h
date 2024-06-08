class GCModelConfigElement_SetMaterialGroupOnAttachedModels;

#ifndef _gccmodelconfigelement_setmaterialgrouponattachedmodels_h
#define _gccmodelconfigelement_setmaterialgrouponattachedmodels_h

#include "../../../scripting.h"




class GCModelConfigElement_SetMaterialGroupOnAttachedModels
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_SetMaterialGroupOnAttachedModels() {}
    GCModelConfigElement_SetMaterialGroupOnAttachedModels(void *ptr) : m_ptr(ptr) {}

    CUtlString GetMaterialGroupName() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_SetMaterialGroupOnAttachedModels", "m_MaterialGroupName"); }
    void SetMaterialGroupName(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_SetMaterialGroupOnAttachedModels", "m_MaterialGroupName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif