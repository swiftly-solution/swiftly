class GC_INIT_RemapNamedModelBodyPartToScalar;

#ifndef _gcc_init_remapnamedmodelbodyparttoscalar_h
#define _gcc_init_remapnamedmodelbodyparttoscalar_h

#include "../../../scripting.h"




class GC_INIT_RemapNamedModelBodyPartToScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapNamedModelBodyPartToScalar() {}
    GC_INIT_RemapNamedModelBodyPartToScalar(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif