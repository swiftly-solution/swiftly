class GCInfoPlayerTerrorist;

#ifndef _gccinfoplayerterrorist_h
#define _gccinfoplayerterrorist_h

#include "../../../scripting.h"




class GCInfoPlayerTerrorist
{
private:
    void *m_ptr;

public:
    GCInfoPlayerTerrorist() {}
    GCInfoPlayerTerrorist(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif