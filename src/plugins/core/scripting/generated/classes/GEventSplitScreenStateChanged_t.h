class GEventSplitScreenStateChanged_t;

#ifndef _gceventsplitscreenstatechanged_t_h
#define _gceventsplitscreenstatechanged_t_h

#include "../../../scripting.h"




class GEventSplitScreenStateChanged_t
{
private:
    void *m_ptr;

public:
    GEventSplitScreenStateChanged_t() {}
    GEventSplitScreenStateChanged_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif