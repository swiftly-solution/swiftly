class GIPhysicsPlayerController;

#ifndef _gciphysicsplayercontroller_h
#define _gciphysicsplayercontroller_h

#include "../../../scripting.h"




class GIPhysicsPlayerController
{
private:
    void *m_ptr;

public:
    GIPhysicsPlayerController() {}
    GIPhysicsPlayerController(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif