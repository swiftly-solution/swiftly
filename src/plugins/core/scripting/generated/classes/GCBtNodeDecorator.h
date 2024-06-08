class GCBtNodeDecorator;

#ifndef _gccbtnodedecorator_h
#define _gccbtnodedecorator_h

#include "../../../scripting.h"




class GCBtNodeDecorator
{
private:
    void *m_ptr;

public:
    GCBtNodeDecorator() {}
    GCBtNodeDecorator(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif