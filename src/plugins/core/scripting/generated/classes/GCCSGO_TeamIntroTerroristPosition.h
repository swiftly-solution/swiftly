class GCCSGO_TeamIntroTerroristPosition;

#ifndef _gcccsgo_teamintroterroristposition_h
#define _gcccsgo_teamintroterroristposition_h

#include "../../../scripting.h"




class GCCSGO_TeamIntroTerroristPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_TeamIntroTerroristPosition() {}
    GCCSGO_TeamIntroTerroristPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif