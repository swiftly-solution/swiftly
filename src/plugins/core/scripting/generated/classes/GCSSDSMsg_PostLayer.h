class GCSSDSMsg_PostLayer;

#ifndef _gccssdsmsg_postlayer_h
#define _gccssdsmsg_postlayer_h

#include "../../../scripting.h"




class GCSSDSMsg_PostLayer
{
private:
    void *m_ptr;

public:
    GCSSDSMsg_PostLayer() {}
    GCSSDSMsg_PostLayer(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif