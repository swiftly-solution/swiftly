class GFakeEntityDerivedA_tAPI;

#ifndef _gcfakeentityderiveda_tapi_h
#define _gcfakeentityderiveda_tapi_h

#include "../../../scripting.h"




class GFakeEntityDerivedA_tAPI
{
private:
    void *m_ptr;

public:
    GFakeEntityDerivedA_tAPI() {}
    GFakeEntityDerivedA_tAPI(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif