class GMaterialParamTexture_t;

#ifndef _gcmaterialparamtexture_t_h
#define _gcmaterialparamtexture_t_h

#include "../../../scripting.h"




class GMaterialParamTexture_t
{
private:
    void *m_ptr;

public:
    GMaterialParamTexture_t() {}
    GMaterialParamTexture_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif