class GCAnimTagManagerUpdater;

#ifndef _gccanimtagmanagerupdater_h
#define _gccanimtagmanagerupdater_h

#include "../../../scripting.h"




class GCAnimTagManagerUpdater
{
private:
    void *m_ptr;

public:
    GCAnimTagManagerUpdater() {}
    GCAnimTagManagerUpdater(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif