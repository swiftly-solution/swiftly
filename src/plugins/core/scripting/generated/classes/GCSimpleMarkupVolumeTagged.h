class GCSimpleMarkupVolumeTagged;

#ifndef _gccsimplemarkupvolumetagged_h
#define _gccsimplemarkupvolumetagged_h

#include "../../../scripting.h"




class GCSimpleMarkupVolumeTagged
{
private:
    void *m_ptr;

public:
    GCSimpleMarkupVolumeTagged() {}
    GCSimpleMarkupVolumeTagged(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif