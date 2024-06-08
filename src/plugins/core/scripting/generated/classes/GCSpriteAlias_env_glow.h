class GCSpriteAlias_env_glow;

#ifndef _gccspritealias_env_glow_h
#define _gccspritealias_env_glow_h

#include "../../../scripting.h"




class GCSpriteAlias_env_glow
{
private:
    void *m_ptr;

public:
    GCSpriteAlias_env_glow() {}
    GCSpriteAlias_env_glow(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif