class GC_INIT_RandomNamedModelMeshGroup;

#ifndef _gcc_init_randomnamedmodelmeshgroup_h
#define _gcc_init_randomnamedmodelmeshgroup_h

#include "../../../scripting.h"




class GC_INIT_RandomNamedModelMeshGroup
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomNamedModelMeshGroup() {}
    GC_INIT_RandomNamedModelMeshGroup(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif