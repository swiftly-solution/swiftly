class GCBodyComponentBaseModelEntity;

#ifndef _gccbodycomponentbasemodelentity_h
#define _gccbodycomponentbasemodelentity_h

#include "../../../scripting.h"




class GCBodyComponentBaseModelEntity
{
private:
    void *m_ptr;

public:
    GCBodyComponentBaseModelEntity() {}
    GCBodyComponentBaseModelEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif