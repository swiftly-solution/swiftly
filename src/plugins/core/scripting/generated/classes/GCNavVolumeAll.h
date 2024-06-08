class GCNavVolumeAll;

#ifndef _gccnavvolumeall_h
#define _gccnavvolumeall_h

#include "../../../scripting.h"




class GCNavVolumeAll
{
private:
    void *m_ptr;

public:
    GCNavVolumeAll() {}
    GCNavVolumeAll(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif