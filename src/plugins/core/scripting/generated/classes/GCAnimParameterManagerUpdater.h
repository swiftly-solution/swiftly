class GCAnimParameterManagerUpdater;

#ifndef _gccanimparametermanagerupdater_h
#define _gccanimparametermanagerupdater_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"

class GCAnimParameterManagerUpdater
{
private:
    void *m_ptr;

public:
    GCAnimParameterManagerUpdater() {}
    GCAnimParameterManagerUpdater(void *ptr) : m_ptr(ptr) {}

    std::vector<GCAnimParamHandle> GetIndexToHandle() const { CUtlVector<GCAnimParamHandle>* vec = GetSchemaValue<CUtlVector<GCAnimParamHandle>*>(m_ptr, "CAnimParameterManagerUpdater", "m_indexToHandle"); std::vector<GCAnimParamHandle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetIndexToHandle(std::vector<GCAnimParamHandle> value) { SetSchemaValueCUtlVector<GCAnimParamHandle>(m_ptr, "CAnimParameterManagerUpdater", "m_indexToHandle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif