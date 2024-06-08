class GCLightDirectionalEntity;

#ifndef _gcclightdirectionalentity_h
#define _gcclightdirectionalentity_h

#include "../../../scripting.h"




class GCLightDirectionalEntity
{
private:
    void *m_ptr;

public:
    GCLightDirectionalEntity() {}
    GCLightDirectionalEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif