class GEventClientAdvanceNonRenderedFrame_t;

#ifndef _gceventclientadvancenonrenderedframe_t_h
#define _gceventclientadvancenonrenderedframe_t_h

#include "../../../scripting.h"




class GEventClientAdvanceNonRenderedFrame_t
{
private:
    void *m_ptr;

public:
    GEventClientAdvanceNonRenderedFrame_t() {}
    GEventClientAdvanceNonRenderedFrame_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif