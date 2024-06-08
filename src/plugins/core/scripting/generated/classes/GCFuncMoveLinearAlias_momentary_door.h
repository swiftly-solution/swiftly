class GCFuncMoveLinearAlias_momentary_door;

#ifndef _gccfuncmovelinearalias_momentary_door_h
#define _gccfuncmovelinearalias_momentary_door_h

#include "../../../scripting.h"




class GCFuncMoveLinearAlias_momentary_door
{
private:
    void *m_ptr;

public:
    GCFuncMoveLinearAlias_momentary_door() {}
    GCFuncMoveLinearAlias_momentary_door(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif