class GCEnvCubemapBox;

#ifndef _gccenvcubemapbox_h
#define _gccenvcubemapbox_h

#include "../../../scripting.h"




class GCEnvCubemapBox
{
private:
    void *m_ptr;

public:
    GCEnvCubemapBox() {}
    GCEnvCubemapBox(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif