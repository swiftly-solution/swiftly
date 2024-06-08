class GCNavVolume;

#ifndef _gccnavvolume_h
#define _gccnavvolume_h

#include "../../../scripting.h"




class GCNavVolume
{
private:
    void *m_ptr;

public:
    GCNavVolume() {}
    GCNavVolume(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif