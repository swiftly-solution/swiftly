class GCCSSprite;

#ifndef _gcccssprite_h
#define _gcccssprite_h

#include "../../../scripting.h"




class GCCSSprite
{
private:
    void *m_ptr;

public:
    GCCSSprite() {}
    GCCSSprite(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif