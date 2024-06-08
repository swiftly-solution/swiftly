class GCAnimGraphSettingsManager;

#ifndef _gccanimgraphsettingsmanager_h
#define _gccanimgraphsettingsmanager_h

#include "../../../scripting.h"




class GCAnimGraphSettingsManager
{
private:
    void *m_ptr;

public:
    GCAnimGraphSettingsManager() {}
    GCAnimGraphSettingsManager(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif