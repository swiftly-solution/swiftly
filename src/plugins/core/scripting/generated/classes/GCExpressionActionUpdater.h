class GCExpressionActionUpdater;

#ifndef _gccexpressionactionupdater_h
#define _gccexpressionactionupdater_h

#include "../../../scripting.h"

#include "../types/GAnimParamType_t.h"
#include "GCAnimParamHandle.h"
#include "GAnimScriptHandle.h"

class GCExpressionActionUpdater
{
private:
    void *m_ptr;

public:
    GCExpressionActionUpdater() {}
    GCExpressionActionUpdater(void *ptr) : m_ptr(ptr) {}

    GCAnimParamHandle GetParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CExpressionActionUpdater", "m_hParam"); }
    void SetParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CExpressionActionUpdater", "m_hParam", false, value); }
    AnimParamType_t GetParamType() const { return GetSchemaValue<AnimParamType_t>(m_ptr, "CExpressionActionUpdater", "m_eParamType"); }
    void SetParamType(AnimParamType_t value) { SetSchemaValue(m_ptr, "CExpressionActionUpdater", "m_eParamType", false, value); }
    GAnimScriptHandle GetScript() const { return GetSchemaValue<GAnimScriptHandle>(m_ptr, "CExpressionActionUpdater", "m_hScript"); }
    void SetScript(GAnimScriptHandle value) { SetSchemaValue(m_ptr, "CExpressionActionUpdater", "m_hScript", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif