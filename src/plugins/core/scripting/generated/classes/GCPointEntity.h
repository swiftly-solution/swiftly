class GCPointEntity;

#ifndef _gccpointentity_h
#define _gccpointentity_h

#include "../../../scripting.h"




class GCPointEntity
{
private:
    void *m_ptr;

public:
    GCPointEntity() {}
    GCPointEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif