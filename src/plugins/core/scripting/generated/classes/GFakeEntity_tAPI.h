class GFakeEntity_tAPI;

#ifndef _gcfakeentity_tapi_h
#define _gcfakeentity_tapi_h

#include "../../../scripting.h"




class GFakeEntity_tAPI
{
private:
    void *m_ptr;

public:
    GFakeEntity_tAPI() {}
    GFakeEntity_tAPI(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif