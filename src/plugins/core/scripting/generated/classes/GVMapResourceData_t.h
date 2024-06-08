class GVMapResourceData_t;

#ifndef _gcvmapresourcedata_t_h
#define _gcvmapresourcedata_t_h

#include "../../../scripting.h"




class GVMapResourceData_t
{
private:
    void *m_ptr;

public:
    GVMapResourceData_t() {}
    GVMapResourceData_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif