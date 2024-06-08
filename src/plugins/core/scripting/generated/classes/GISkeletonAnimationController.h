class GISkeletonAnimationController;

#ifndef _gciskeletonanimationcontroller_h
#define _gciskeletonanimationcontroller_h

#include "../../../scripting.h"




class GISkeletonAnimationController
{
private:
    void *m_ptr;

public:
    GISkeletonAnimationController() {}
    GISkeletonAnimationController(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif