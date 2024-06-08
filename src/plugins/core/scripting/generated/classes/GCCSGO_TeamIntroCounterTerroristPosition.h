class GCCSGO_TeamIntroCounterTerroristPosition;

#ifndef _gcccsgo_teamintrocounterterroristposition_h
#define _gcccsgo_teamintrocounterterroristposition_h

#include "../../../scripting.h"




class GCCSGO_TeamIntroCounterTerroristPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_TeamIntroCounterTerroristPosition() {}
    GCCSGO_TeamIntroCounterTerroristPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif