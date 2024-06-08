class GCSSDSMsg_PreLayer;

#ifndef _gccssdsmsg_prelayer_h
#define _gccssdsmsg_prelayer_h

#include "../../../scripting.h"




class GCSSDSMsg_PreLayer
{
private:
    void *m_ptr;

public:
    GCSSDSMsg_PreLayer() {}
    GCSSDSMsg_PreLayer(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif