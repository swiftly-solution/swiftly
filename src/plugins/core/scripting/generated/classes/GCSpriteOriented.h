class GCSpriteOriented;

#ifndef _gccspriteoriented_h
#define _gccspriteoriented_h

#include "../../../scripting.h"




class GCSpriteOriented
{
private:
    void *m_ptr;

public:
    GCSpriteOriented() {}
    GCSpriteOriented(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif