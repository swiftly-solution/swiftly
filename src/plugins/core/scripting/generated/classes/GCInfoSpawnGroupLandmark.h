class GCInfoSpawnGroupLandmark;

#ifndef _gccinfospawngrouplandmark_h
#define _gccinfospawngrouplandmark_h

#include "../../../scripting.h"




class GCInfoSpawnGroupLandmark
{
private:
    void *m_ptr;

public:
    GCInfoSpawnGroupLandmark() {}
    GCInfoSpawnGroupLandmark(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif