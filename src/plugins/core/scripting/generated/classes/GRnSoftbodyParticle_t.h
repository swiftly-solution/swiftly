class GRnSoftbodyParticle_t;

#ifndef _gcrnsoftbodyparticle_t_h
#define _gcrnsoftbodyparticle_t_h

#include "../../../scripting.h"




class GRnSoftbodyParticle_t
{
private:
    void *m_ptr;

public:
    GRnSoftbodyParticle_t() {}
    GRnSoftbodyParticle_t(void *ptr) : m_ptr(ptr) {}

    float GetMassInv() const { return GetSchemaValue<float>(m_ptr, "RnSoftbodyParticle_t", "m_flMassInv"); }
    void SetMassInv(float value) { SetSchemaValue(m_ptr, "RnSoftbodyParticle_t", "m_flMassInv", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif