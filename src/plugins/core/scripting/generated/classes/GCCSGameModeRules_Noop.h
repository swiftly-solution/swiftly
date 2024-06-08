class GCCSGameModeRules_Noop;

#ifndef _gcccsgamemoderules_noop_h
#define _gcccsgamemoderules_noop_h

#include "../../../scripting.h"




class GCCSGameModeRules_Noop
{
private:
    void *m_ptr;

public:
    GCCSGameModeRules_Noop() {}
    GCCSGameModeRules_Noop(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif