class GRenderProjectedMaterial_t;

#ifndef _gcrenderprojectedmaterial_t_h
#define _gcrenderprojectedmaterial_t_h

#include "../../../scripting.h"




class GRenderProjectedMaterial_t
{
private:
    void *m_ptr;

public:
    GRenderProjectedMaterial_t() {}
    GRenderProjectedMaterial_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif