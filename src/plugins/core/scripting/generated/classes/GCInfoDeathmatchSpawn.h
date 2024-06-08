class GCInfoDeathmatchSpawn;

#ifndef _gccinfodeathmatchspawn_h
#define _gccinfodeathmatchspawn_h

#include "../../../scripting.h"




class GCInfoDeathmatchSpawn
{
private:
    void *m_ptr;

public:
    GCInfoDeathmatchSpawn() {}
    GCInfoDeathmatchSpawn(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif