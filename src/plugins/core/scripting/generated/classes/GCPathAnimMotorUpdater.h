class GCPathAnimMotorUpdater;

#ifndef _gccpathanimmotorupdater_h
#define _gccpathanimmotorupdater_h

#include "../../../scripting.h"




class GCPathAnimMotorUpdater
{
private:
    void *m_ptr;

public:
    GCPathAnimMotorUpdater() {}
    GCPathAnimMotorUpdater(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif