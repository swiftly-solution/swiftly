class GCLogicalEntity;

#ifndef _gcclogicalentity_h
#define _gcclogicalentity_h

#include "../../../scripting.h"




class GCLogicalEntity
{
private:
    void *m_ptr;

public:
    GCLogicalEntity() {}
    GCLogicalEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif