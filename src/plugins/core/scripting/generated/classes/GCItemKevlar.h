class GCItemKevlar;

#ifndef _gccitemkevlar_h
#define _gccitemkevlar_h

#include "../../../scripting.h"




class GCItemKevlar
{
private:
    void *m_ptr;

public:
    GCItemKevlar() {}
    GCItemKevlar(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif