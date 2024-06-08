class GCInfoLadderDismount;

#ifndef _gccinfoladderdismount_h
#define _gccinfoladderdismount_h

#include "../../../scripting.h"




class GCInfoLadderDismount
{
private:
    void *m_ptr;

public:
    GCInfoLadderDismount() {}
    GCInfoLadderDismount(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif