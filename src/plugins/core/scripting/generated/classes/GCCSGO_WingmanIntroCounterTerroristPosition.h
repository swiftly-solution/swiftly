class GCCSGO_WingmanIntroCounterTerroristPosition;

#ifndef _gcccsgo_wingmanintrocounterterroristposition_h
#define _gcccsgo_wingmanintrocounterterroristposition_h

#include "../../../scripting.h"




class GCCSGO_WingmanIntroCounterTerroristPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_WingmanIntroCounterTerroristPosition() {}
    GCCSGO_WingmanIntroCounterTerroristPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif