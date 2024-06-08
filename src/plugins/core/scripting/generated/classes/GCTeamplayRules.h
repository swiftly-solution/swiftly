class GCTeamplayRules;

#ifndef _gccteamplayrules_h
#define _gccteamplayrules_h

#include "../../../scripting.h"




class GCTeamplayRules
{
private:
    void *m_ptr;

public:
    GCTeamplayRules() {}
    GCTeamplayRules(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif