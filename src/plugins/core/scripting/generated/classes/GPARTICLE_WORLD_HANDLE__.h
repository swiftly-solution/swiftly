class GPARTICLE_WORLD_HANDLE__;

#ifndef _gcparticle_world_handle___h
#define _gcparticle_world_handle___h

#include "../../../scripting.h"




class GPARTICLE_WORLD_HANDLE__
{
private:
    void *m_ptr;

public:
    GPARTICLE_WORLD_HANDLE__() {}
    GPARTICLE_WORLD_HANDLE__(void *ptr) : m_ptr(ptr) {}

    int32_t GetUnused() const { return GetSchemaValue<int32_t>(m_ptr, "PARTICLE_WORLD_HANDLE__", "unused"); }
    void SetUnused(int32_t value) { SetSchemaValue(m_ptr, "PARTICLE_WORLD_HANDLE__", "unused", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif