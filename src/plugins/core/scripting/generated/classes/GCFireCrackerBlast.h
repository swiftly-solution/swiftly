class GCFireCrackerBlast;

#ifndef _gccfirecrackerblast_h
#define _gccfirecrackerblast_h

#include "../../../scripting.h"




class GCFireCrackerBlast
{
private:
    void *m_ptr;

public:
    GCFireCrackerBlast() {}
    GCFireCrackerBlast(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif