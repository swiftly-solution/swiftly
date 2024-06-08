class GCBasePlayerControllerAPI;

#ifndef _gccbaseplayercontrollerapi_h
#define _gccbaseplayercontrollerapi_h

#include "../../../scripting.h"




class GCBasePlayerControllerAPI
{
private:
    void *m_ptr;

public:
    GCBasePlayerControllerAPI() {}
    GCBasePlayerControllerAPI(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif