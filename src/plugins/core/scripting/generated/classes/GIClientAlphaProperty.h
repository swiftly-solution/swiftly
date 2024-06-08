class GIClientAlphaProperty;

#ifndef _gciclientalphaproperty_h
#define _gciclientalphaproperty_h

#include "../../../scripting.h"




class GIClientAlphaProperty
{
private:
    void *m_ptr;

public:
    GIClientAlphaProperty() {}
    GIClientAlphaProperty(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif