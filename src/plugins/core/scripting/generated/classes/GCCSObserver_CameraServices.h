class GCCSObserver_CameraServices;

#ifndef _gcccsobserver_cameraservices_h
#define _gcccsobserver_cameraservices_h

#include "../../../scripting.h"




class GCCSObserver_CameraServices
{
private:
    void *m_ptr;

public:
    GCCSObserver_CameraServices() {}
    GCCSObserver_CameraServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif