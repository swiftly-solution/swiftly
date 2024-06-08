class Gvphysics_save_cphysicsbody_t;

#ifndef _gcvphysics_save_cphysicsbody_t_h
#define _gcvphysics_save_cphysicsbody_t_h

#include "../../../scripting.h"




class Gvphysics_save_cphysicsbody_t
{
private:
    void *m_ptr;

public:
    Gvphysics_save_cphysicsbody_t() {}
    Gvphysics_save_cphysicsbody_t(void *ptr) : m_ptr(ptr) {}

    uint64_t GetOldPointer() const { return GetSchemaValue<uint64_t>(m_ptr, "vphysics_save_cphysicsbody_t", "m_nOldPointer"); }
    void SetOldPointer(uint64_t value) { SetSchemaValue(m_ptr, "vphysics_save_cphysicsbody_t", "m_nOldPointer", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif