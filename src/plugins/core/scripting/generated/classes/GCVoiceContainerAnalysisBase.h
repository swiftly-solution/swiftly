class GCVoiceContainerAnalysisBase;

#ifndef _gccvoicecontaineranalysisbase_h
#define _gccvoicecontaineranalysisbase_h

#include "../../../scripting.h"




class GCVoiceContainerAnalysisBase
{
private:
    void *m_ptr;

public:
    GCVoiceContainerAnalysisBase() {}
    GCVoiceContainerAnalysisBase(void *ptr) : m_ptr(ptr) {}

    bool GetRegenerateCurveOnCompile() const { return GetSchemaValue<bool>(m_ptr, "CVoiceContainerAnalysisBase", "m_bRegenerateCurveOnCompile"); }
    void SetRegenerateCurveOnCompile(bool value) { SetSchemaValue(m_ptr, "CVoiceContainerAnalysisBase", "m_bRegenerateCurveOnCompile", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif