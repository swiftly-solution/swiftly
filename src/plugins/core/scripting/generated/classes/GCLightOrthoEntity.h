class GCLightOrthoEntity;

#ifndef _gcclightorthoentity_h
#define _gcclightorthoentity_h

#include "../../../scripting.h"




class GCLightOrthoEntity
{
private:
    void *m_ptr;

public:
    GCLightOrthoEntity() {}
    GCLightOrthoEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif