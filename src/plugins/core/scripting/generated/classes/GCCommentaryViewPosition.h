class GCCommentaryViewPosition;

#ifndef _gcccommentaryviewposition_h
#define _gcccommentaryviewposition_h

#include "../../../scripting.h"




class GCCommentaryViewPosition
{
private:
    void *m_ptr;

public:
    GCCommentaryViewPosition() {}
    GCCommentaryViewPosition(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif