class GCCPPScriptComponentUpdater;

#ifndef _gcccppscriptcomponentupdater_h
#define _gcccppscriptcomponentupdater_h

#include "../../../scripting.h"




class GCCPPScriptComponentUpdater
{
private:
    void *m_ptr;

public:
    GCCPPScriptComponentUpdater() {}
    GCCPPScriptComponentUpdater(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif