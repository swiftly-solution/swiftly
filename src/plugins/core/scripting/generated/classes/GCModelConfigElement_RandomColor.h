class GCModelConfigElement_RandomColor;

#ifndef _gccmodelconfigelement_randomcolor_h
#define _gccmodelconfigelement_randomcolor_h

#include "../../../scripting.h"




class GCModelConfigElement_RandomColor
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_RandomColor() {}
    GCModelConfigElement_RandomColor(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif