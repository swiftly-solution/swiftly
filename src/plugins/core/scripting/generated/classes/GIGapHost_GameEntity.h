class GIGapHost_GameEntity;

#ifndef _gcigaphost_gameentity_h
#define _gcigaphost_gameentity_h

#include "../../../scripting.h"




class GIGapHost_GameEntity
{
private:
    void *m_ptr;

public:
    GIGapHost_GameEntity() {}
    GIGapHost_GameEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif