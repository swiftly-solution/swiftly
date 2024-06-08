class GCNavWalkable;

#ifndef _gccnavwalkable_h
#define _gccnavwalkable_h

#include "../../../scripting.h"




class GCNavWalkable
{
private:
    void *m_ptr;

public:
    GCNavWalkable() {}
    GCNavWalkable(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif