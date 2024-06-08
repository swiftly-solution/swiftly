class GCInfoData;

#ifndef _gccinfodata_h
#define _gccinfodata_h

#include "../../../scripting.h"




class GCInfoData
{
private:
    void *m_ptr;

public:
    GCInfoData() {}
    GCInfoData(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif