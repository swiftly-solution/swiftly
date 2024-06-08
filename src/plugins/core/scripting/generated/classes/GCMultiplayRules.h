class GCMultiplayRules;

#ifndef _gccmultiplayrules_h
#define _gccmultiplayrules_h

#include "../../../scripting.h"




class GCMultiplayRules
{
private:
    void *m_ptr;

public:
    GCMultiplayRules() {}
    GCMultiplayRules(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif