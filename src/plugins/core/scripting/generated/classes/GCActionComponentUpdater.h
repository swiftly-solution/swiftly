class GCActionComponentUpdater;

#ifndef _gccactioncomponentupdater_h
#define _gccactioncomponentupdater_h

#include "../../../scripting.h"




class GCActionComponentUpdater
{
private:
    void *m_ptr;

public:
    GCActionComponentUpdater() {}
    GCActionComponentUpdater(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif