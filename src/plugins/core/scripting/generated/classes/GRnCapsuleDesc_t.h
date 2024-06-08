class GRnCapsuleDesc_t;

#ifndef _gcrncapsuledesc_t_h
#define _gcrncapsuledesc_t_h

#include "../../../scripting.h"


#include "GRnCapsule_t.h"

class GRnCapsuleDesc_t
{
private:
    void *m_ptr;

public:
    GRnCapsuleDesc_t() {}
    GRnCapsuleDesc_t(void *ptr) : m_ptr(ptr) {}

    GRnCapsule_t GetCapsule() const { return GetSchemaValue<GRnCapsule_t>(m_ptr, "RnCapsuleDesc_t", "m_Capsule"); }
    void SetCapsule(GRnCapsule_t value) { SetSchemaValue(m_ptr, "RnCapsuleDesc_t", "m_Capsule", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif