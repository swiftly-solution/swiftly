class GCVoiceContainerBase;

#ifndef _gccvoicecontainerbase_h
#define _gccvoicecontainerbase_h

#include "../../../scripting.h"


#include "GCVoiceContainerAnalysisBase.h"

class GCVoiceContainerBase
{
private:
    void *m_ptr;

public:
    GCVoiceContainerBase() {}
    GCVoiceContainerBase(void *ptr) : m_ptr(ptr) {}

    bool GetHideAnalyzers() const { return GetSchemaValue<bool>(m_ptr, "CVoiceContainerBase", "m_bHideAnalyzers"); }
    void SetHideAnalyzers(bool value) { SetSchemaValue(m_ptr, "CVoiceContainerBase", "m_bHideAnalyzers", false, value); }
    std::vector<GCVoiceContainerAnalysisBase*> GetAnalysisContainers() const { CUtlVector<GCVoiceContainerAnalysisBase*>* vec = GetSchemaValue<CUtlVector<GCVoiceContainerAnalysisBase*>*>(m_ptr, "CVoiceContainerBase", "m_analysisContainers"); std::vector<GCVoiceContainerAnalysisBase*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAnalysisContainers(std::vector<GCVoiceContainerAnalysisBase*> value) { SetSchemaValueCUtlVector<GCVoiceContainerAnalysisBase*>(m_ptr, "CVoiceContainerBase", "m_analysisContainers", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif