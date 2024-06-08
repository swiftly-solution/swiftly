class GCBaseEntityAPI;

#ifndef _gccbaseentityapi_h
#define _gccbaseentityapi_h

#include "../../../scripting.h"




class GCBaseEntityAPI
{
private:
    void *m_ptr;

public:
    GCBaseEntityAPI() {}
    GCBaseEntityAPI(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif