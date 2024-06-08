class GEntOutput_t;

#ifndef _gcentoutput_t_h
#define _gcentoutput_t_h

#include "../../../scripting.h"




class GEntOutput_t
{
private:
    void *m_ptr;

public:
    GEntOutput_t() {}
    GEntOutput_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif