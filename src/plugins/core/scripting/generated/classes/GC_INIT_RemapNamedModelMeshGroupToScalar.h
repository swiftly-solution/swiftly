class GC_INIT_RemapNamedModelMeshGroupToScalar;

#ifndef _gcc_init_remapnamedmodelmeshgrouptoscalar_h
#define _gcc_init_remapnamedmodelmeshgrouptoscalar_h

#include "../../../scripting.h"




class GC_INIT_RemapNamedModelMeshGroupToScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapNamedModelMeshGroupToScalar() {}
    GC_INIT_RemapNamedModelMeshGroupToScalar(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif