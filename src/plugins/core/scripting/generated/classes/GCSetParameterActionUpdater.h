class GCSetParameterActionUpdater;

#ifndef _gccsetparameteractionupdater_h
#define _gccsetparameteractionupdater_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"

class GCSetParameterActionUpdater
{
private:
    void *m_ptr;

public:
    GCSetParameterActionUpdater() {}
    GCSetParameterActionUpdater(void *ptr) : m_ptr(ptr) {}

    GCAnimParamHandle GetParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSetParameterActionUpdater", "m_hParam"); }
    void SetParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSetParameterActionUpdater", "m_hParam", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif