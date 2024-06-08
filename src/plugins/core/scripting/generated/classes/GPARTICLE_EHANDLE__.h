class GPARTICLE_EHANDLE__;

#ifndef _gcparticle_ehandle___h
#define _gcparticle_ehandle___h

#include "../../../scripting.h"




class GPARTICLE_EHANDLE__
{
private:
    void *m_ptr;

public:
    GPARTICLE_EHANDLE__() {}
    GPARTICLE_EHANDLE__(void *ptr) : m_ptr(ptr) {}

    int32_t GetUnused() const { return GetSchemaValue<int32_t>(m_ptr, "PARTICLE_EHANDLE__", "unused"); }
    void SetUnused(int32_t value) { SetSchemaValue(m_ptr, "PARTICLE_EHANDLE__", "unused", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif