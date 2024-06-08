class Gdynpitchvol_t;

#ifndef _gcdynpitchvol_t_h
#define _gcdynpitchvol_t_h

#include "../../../scripting.h"




class Gdynpitchvol_t
{
private:
    void *m_ptr;

public:
    Gdynpitchvol_t() {}
    Gdynpitchvol_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif