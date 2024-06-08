class GCFuncVehicleClip;

#ifndef _gccfuncvehicleclip_h
#define _gccfuncvehicleclip_h

#include "../../../scripting.h"




class GCFuncVehicleClip
{
private:
    void *m_ptr;

public:
    GCFuncVehicleClip() {}
    GCFuncVehicleClip(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif