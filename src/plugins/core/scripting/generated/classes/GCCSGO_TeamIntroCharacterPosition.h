class GCCSGO_TeamIntroCharacterPosition;

#ifndef _gcccsgo_teamintrocharacterposition_h
#define _gcccsgo_teamintrocharacterposition_h

#include "../../../scripting.h"




class GCCSGO_TeamIntroCharacterPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_TeamIntroCharacterPosition() {}
    GCCSGO_TeamIntroCharacterPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif