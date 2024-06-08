class GCNullEntity;

#ifndef _gccnullentity_h
#define _gccnullentity_h

#include "../../../scripting.h"




class GCNullEntity
{
private:
    void *m_ptr;

public:
    GCNullEntity() {}
    GCNullEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif