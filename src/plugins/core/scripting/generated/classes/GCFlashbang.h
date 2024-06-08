class GCFlashbang;

#ifndef _gccflashbang_h
#define _gccflashbang_h

#include "../../../scripting.h"




class GCFlashbang
{
private:
    void *m_ptr;

public:
    GCFlashbang() {}
    GCFlashbang(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif