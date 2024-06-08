class GCRopeKeyframeAlias_move_rope;

#ifndef _gccropekeyframealias_move_rope_h
#define _gccropekeyframealias_move_rope_h

#include "../../../scripting.h"




class GCRopeKeyframeAlias_move_rope
{
private:
    void *m_ptr;

public:
    GCRopeKeyframeAlias_move_rope() {}
    GCRopeKeyframeAlias_move_rope(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif