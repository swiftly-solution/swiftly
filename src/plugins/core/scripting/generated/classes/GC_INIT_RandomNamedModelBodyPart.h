class GC_INIT_RandomNamedModelBodyPart;

#ifndef _gcc_init_randomnamedmodelbodypart_h
#define _gcc_init_randomnamedmodelbodypart_h

#include "../../../scripting.h"




class GC_INIT_RandomNamedModelBodyPart
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomNamedModelBodyPart() {}
    GC_INIT_RandomNamedModelBodyPart(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif