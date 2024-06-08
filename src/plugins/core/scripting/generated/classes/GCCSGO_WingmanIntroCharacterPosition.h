class GCCSGO_WingmanIntroCharacterPosition;

#ifndef _gcccsgo_wingmanintrocharacterposition_h
#define _gcccsgo_wingmanintrocharacterposition_h

#include "../../../scripting.h"




class GCCSGO_WingmanIntroCharacterPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_WingmanIntroCharacterPosition() {}
    GCCSGO_WingmanIntroCharacterPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif