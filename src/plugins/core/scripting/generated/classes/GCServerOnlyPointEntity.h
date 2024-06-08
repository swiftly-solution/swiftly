class GCServerOnlyPointEntity;

#ifndef _gccserveronlypointentity_h
#define _gccserveronlypointentity_h

#include "../../../scripting.h"




class GCServerOnlyPointEntity
{
private:
    void *m_ptr;

public:
    GCServerOnlyPointEntity() {}
    GCServerOnlyPointEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif