class GCInfoLandmark;

#ifndef _gccinfolandmark_h
#define _gccinfolandmark_h

#include "../../../scripting.h"




class GCInfoLandmark
{
private:
    void *m_ptr;

public:
    GCInfoLandmark() {}
    GCInfoLandmark(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif