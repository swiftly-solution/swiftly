class GCTakeDamageInfoAPI;

#ifndef _gcctakedamageinfoapi_h
#define _gcctakedamageinfoapi_h

#include "../../../scripting.h"




class GCTakeDamageInfoAPI
{
private:
    void *m_ptr;

public:
    GCTakeDamageInfoAPI() {}
    GCTakeDamageInfoAPI(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif