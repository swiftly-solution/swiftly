class GCServerOnlyEntity;

#ifndef _gccserveronlyentity_h
#define _gccserveronlyentity_h

#include "../../../scripting.h"




class GCServerOnlyEntity
{
private:
    void *m_ptr;

public:
    GCServerOnlyEntity() {}
    GCServerOnlyEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif