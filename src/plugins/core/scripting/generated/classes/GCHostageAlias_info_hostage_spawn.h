class GCHostageAlias_info_hostage_spawn;

#ifndef _gcchostagealias_info_hostage_spawn_h
#define _gcchostagealias_info_hostage_spawn_h

#include "../../../scripting.h"




class GCHostageAlias_info_hostage_spawn
{
private:
    void *m_ptr;

public:
    GCHostageAlias_info_hostage_spawn() {}
    GCHostageAlias_info_hostage_spawn(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif