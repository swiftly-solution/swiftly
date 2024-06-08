class GCMarkupVolumeTagged_Nav;

#ifndef _gccmarkupvolumetagged_nav_h
#define _gccmarkupvolumetagged_nav_h

#include "../../../scripting.h"




class GCMarkupVolumeTagged_Nav
{
private:
    void *m_ptr;

public:
    GCMarkupVolumeTagged_Nav() {}
    GCMarkupVolumeTagged_Nav(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif