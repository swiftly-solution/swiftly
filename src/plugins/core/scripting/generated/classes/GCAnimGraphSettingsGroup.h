class GCAnimGraphSettingsGroup;

#ifndef _gccanimgraphsettingsgroup_h
#define _gccanimgraphsettingsgroup_h

#include "../../../scripting.h"




class GCAnimGraphSettingsGroup
{
private:
    void *m_ptr;

public:
    GCAnimGraphSettingsGroup() {}
    GCAnimGraphSettingsGroup(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif