class GIHasAttributes;

#ifndef _gcihasattributes_h
#define _gcihasattributes_h

#include "../../../scripting.h"




class GIHasAttributes
{
private:
    void *m_ptr;

public:
    GIHasAttributes() {}
    GIHasAttributes(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif