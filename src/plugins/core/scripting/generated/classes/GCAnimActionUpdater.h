class GCAnimActionUpdater;

#ifndef _gccanimactionupdater_h
#define _gccanimactionupdater_h

#include "../../../scripting.h"




class GCAnimActionUpdater
{
private:
    void *m_ptr;

public:
    GCAnimActionUpdater() {}
    GCAnimActionUpdater(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif