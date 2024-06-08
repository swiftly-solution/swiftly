class GFakeEntityDerivedB_tAPI;

#ifndef _gcfakeentityderivedb_tapi_h
#define _gcfakeentityderivedb_tapi_h

#include "../../../scripting.h"




class GFakeEntityDerivedB_tAPI
{
private:
    void *m_ptr;

public:
    GFakeEntityDerivedB_tAPI() {}
    GFakeEntityDerivedB_tAPI(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif