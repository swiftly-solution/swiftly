class GCModelPointEntity;

#ifndef _gccmodelpointentity_h
#define _gccmodelpointentity_h

#include "../../../scripting.h"




class GCModelPointEntity
{
private:
    void *m_ptr;

public:
    GCModelPointEntity() {}
    GCModelPointEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif