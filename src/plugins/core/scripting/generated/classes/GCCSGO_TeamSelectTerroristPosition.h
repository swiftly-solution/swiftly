class GCCSGO_TeamSelectTerroristPosition;

#ifndef _gcccsgo_teamselectterroristposition_h
#define _gcccsgo_teamselectterroristposition_h

#include "../../../scripting.h"




class GCCSGO_TeamSelectTerroristPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_TeamSelectTerroristPosition() {}
    GCCSGO_TeamSelectTerroristPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif