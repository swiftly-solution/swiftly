class GCLightSpotEntity;

#ifndef _gcclightspotentity_h
#define _gcclightspotentity_h

#include "../../../scripting.h"




class GCLightSpotEntity
{
private:
    void *m_ptr;

public:
    GCLightSpotEntity() {}
    GCLightSpotEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif