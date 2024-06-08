class GCCSGO_WingmanIntroTerroristPosition;

#ifndef _gcccsgo_wingmanintroterroristposition_h
#define _gcccsgo_wingmanintroterroristposition_h

#include "../../../scripting.h"




class GCCSGO_WingmanIntroTerroristPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_WingmanIntroTerroristPosition() {}
    GCCSGO_WingmanIntroTerroristPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif