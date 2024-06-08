class GCModelConfigList;

#ifndef _gccmodelconfiglist_h
#define _gccmodelconfiglist_h

#include "../../../scripting.h"


#include "GCModelConfig.h"

class GCModelConfigList
{
private:
    void *m_ptr;

public:
    GCModelConfigList() {}
    GCModelConfigList(void *ptr) : m_ptr(ptr) {}

    bool GetHideMaterialGroupInTools() const { return GetSchemaValue<bool>(m_ptr, "CModelConfigList", "m_bHideMaterialGroupInTools"); }
    void SetHideMaterialGroupInTools(bool value) { SetSchemaValue(m_ptr, "CModelConfigList", "m_bHideMaterialGroupInTools", false, value); }
    bool GetHideRenderColorInTools() const { return GetSchemaValue<bool>(m_ptr, "CModelConfigList", "m_bHideRenderColorInTools"); }
    void SetHideRenderColorInTools(bool value) { SetSchemaValue(m_ptr, "CModelConfigList", "m_bHideRenderColorInTools", false, value); }
    std::vector<GCModelConfig*> GetConfigs() const { CUtlVector<GCModelConfig*>* vec = GetSchemaValue<CUtlVector<GCModelConfig*>*>(m_ptr, "CModelConfigList", "m_Configs"); std::vector<GCModelConfig*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetConfigs(std::vector<GCModelConfig*> value) { SetSchemaValueCUtlVector<GCModelConfig*>(m_ptr, "CModelConfigList", "m_Configs", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif