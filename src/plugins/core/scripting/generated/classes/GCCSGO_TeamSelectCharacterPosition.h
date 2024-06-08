class GCCSGO_TeamSelectCharacterPosition;

#ifndef _gcccsgo_teamselectcharacterposition_h
#define _gcccsgo_teamselectcharacterposition_h

#include "../../../scripting.h"




class GCCSGO_TeamSelectCharacterPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_TeamSelectCharacterPosition() {}
    GCCSGO_TeamSelectCharacterPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif