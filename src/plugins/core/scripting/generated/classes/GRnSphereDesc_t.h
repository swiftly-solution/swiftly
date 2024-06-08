class GRnSphereDesc_t;

#ifndef _gcrnspheredesc_t_h
#define _gcrnspheredesc_t_h

#include "../../../scripting.h"




class GRnSphereDesc_t
{
private:
    void *m_ptr;

public:
    GRnSphereDesc_t() {}
    GRnSphereDesc_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif