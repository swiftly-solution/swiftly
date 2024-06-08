class GCAnimScriptManager;

#ifndef _gccanimscriptmanager_h
#define _gccanimscriptmanager_h

#include "../../../scripting.h"


#include "GScriptInfo_t.h"

class GCAnimScriptManager
{
private:
    void *m_ptr;

public:
    GCAnimScriptManager() {}
    GCAnimScriptManager(void *ptr) : m_ptr(ptr) {}

    std::vector<GScriptInfo_t> GetScriptInfo() const { CUtlVector<GScriptInfo_t>* vec = GetSchemaValue<CUtlVector<GScriptInfo_t>*>(m_ptr, "CAnimScriptManager", "m_scriptInfo"); std::vector<GScriptInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetScriptInfo(std::vector<GScriptInfo_t> value) { SetSchemaValueCUtlVector<GScriptInfo_t>(m_ptr, "CAnimScriptManager", "m_scriptInfo", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif