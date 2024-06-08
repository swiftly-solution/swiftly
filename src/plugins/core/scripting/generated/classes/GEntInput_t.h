class GEntInput_t;

#ifndef _gcentinput_t_h
#define _gcentinput_t_h

#include "../../../scripting.h"




class GEntInput_t
{
private:
    void *m_ptr;

public:
    GEntInput_t() {}
    GEntInput_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif