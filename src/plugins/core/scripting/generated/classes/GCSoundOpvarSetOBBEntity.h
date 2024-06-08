class GCSoundOpvarSetOBBEntity;

#ifndef _gccsoundopvarsetobbentity_h
#define _gccsoundopvarsetobbentity_h

#include "../../../scripting.h"




class GCSoundOpvarSetOBBEntity
{
private:
    void *m_ptr;

public:
    GCSoundOpvarSetOBBEntity() {}
    GCSoundOpvarSetOBBEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif