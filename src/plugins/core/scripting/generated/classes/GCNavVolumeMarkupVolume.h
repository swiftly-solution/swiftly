class GCNavVolumeMarkupVolume;

#ifndef _gccnavvolumemarkupvolume_h
#define _gccnavvolumemarkupvolume_h

#include "../../../scripting.h"




class GCNavVolumeMarkupVolume
{
private:
    void *m_ptr;

public:
    GCNavVolumeMarkupVolume() {}
    GCNavVolumeMarkupVolume(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif