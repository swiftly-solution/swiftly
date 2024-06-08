class GC_INIT_RemapNamedModelSequenceToScalar;

#ifndef _gcc_init_remapnamedmodelsequencetoscalar_h
#define _gcc_init_remapnamedmodelsequencetoscalar_h

#include "../../../scripting.h"




class GC_INIT_RemapNamedModelSequenceToScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapNamedModelSequenceToScalar() {}
    GC_INIT_RemapNamedModelSequenceToScalar(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif