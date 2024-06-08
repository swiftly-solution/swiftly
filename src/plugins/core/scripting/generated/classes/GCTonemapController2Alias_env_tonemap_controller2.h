class GCTonemapController2Alias_env_tonemap_controller2;

#ifndef _gcctonemapcontroller2alias_env_tonemap_controller2_h
#define _gcctonemapcontroller2alias_env_tonemap_controller2_h

#include "../../../scripting.h"




class GCTonemapController2Alias_env_tonemap_controller2
{
private:
    void *m_ptr;

public:
    GCTonemapController2Alias_env_tonemap_controller2() {}
    GCTonemapController2Alias_env_tonemap_controller2(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif