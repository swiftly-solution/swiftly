class GMaterialParamBuffer_t;

#ifndef _gcmaterialparambuffer_t_h
#define _gcmaterialparambuffer_t_h

#include "../../../scripting.h"




class GMaterialParamBuffer_t
{
private:
    void *m_ptr;

public:
    GMaterialParamBuffer_t() {}
    GMaterialParamBuffer_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif