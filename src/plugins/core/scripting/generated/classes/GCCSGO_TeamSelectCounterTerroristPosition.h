class GCCSGO_TeamSelectCounterTerroristPosition;

#ifndef _gcccsgo_teamselectcounterterroristposition_h
#define _gcccsgo_teamselectcounterterroristposition_h

#include "../../../scripting.h"




class GCCSGO_TeamSelectCounterTerroristPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_TeamSelectCounterTerroristPosition() {}
    GCCSGO_TeamSelectCounterTerroristPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif