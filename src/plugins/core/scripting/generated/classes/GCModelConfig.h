class GCModelConfig;

#ifndef _gccmodelconfig_h
#define _gccmodelconfig_h

#include "../../../scripting.h"


#include "GCModelConfigElement.h"
#include "GCModelConfig.h"

class GCModelConfig
{
private:
    void *m_ptr;

public:
    GCModelConfig() {}
    GCModelConfig(void *ptr) : m_ptr(ptr) {}

    CUtlString GetConfigName() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfig", "m_ConfigName"); }
    void SetConfigName(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfig", "m_ConfigName", false, value); }
    std::vector<GCModelConfigElement*> GetElements() const { CUtlVector<GCModelConfigElement*>* vec = GetSchemaValue<CUtlVector<GCModelConfigElement*>*>(m_ptr, "CModelConfig", "m_Elements"); std::vector<GCModelConfigElement*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetElements(std::vector<GCModelConfigElement*> value) { SetSchemaValueCUtlVector<GCModelConfigElement*>(m_ptr, "CModelConfig", "m_Elements", false, value); }
    bool GetTopLevel() const { return GetSchemaValue<bool>(m_ptr, "CModelConfig", "m_bTopLevel"); }
    void SetTopLevel(bool value) { SetSchemaValue(m_ptr, "CModelConfig", "m_bTopLevel", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif