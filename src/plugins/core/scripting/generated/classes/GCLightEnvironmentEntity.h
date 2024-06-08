class GCLightEnvironmentEntity;

#ifndef _gcclightenvironmententity_h
#define _gcclightenvironmententity_h

#include "../../../scripting.h"




class GCLightEnvironmentEntity
{
private:
    void *m_ptr;

public:
    GCLightEnvironmentEntity() {}
    GCLightEnvironmentEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif