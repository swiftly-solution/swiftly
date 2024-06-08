class GCCSPlayer_CameraServices;

#ifndef _gcccsplayer_cameraservices_h
#define _gcccsplayer_cameraservices_h

#include "../../../scripting.h"




class GCCSPlayer_CameraServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_CameraServices() {}
    GCCSPlayer_CameraServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif