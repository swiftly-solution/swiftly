class GCBtNodeComposite;

#ifndef _gccbtnodecomposite_h
#define _gccbtnodecomposite_h

#include "../../../scripting.h"




class GCBtNodeComposite
{
private:
    void *m_ptr;

public:
    GCBtNodeComposite() {}
    GCBtNodeComposite(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif