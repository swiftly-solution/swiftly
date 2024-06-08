class GCServerOnlyModelEntity;

#ifndef _gccserveronlymodelentity_h
#define _gccserveronlymodelentity_h

#include "../../../scripting.h"




class GCServerOnlyModelEntity
{
private:
    void *m_ptr;

public:
    GCServerOnlyModelEntity() {}
    GCServerOnlyModelEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif