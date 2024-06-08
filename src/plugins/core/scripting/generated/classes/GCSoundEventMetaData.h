class GCSoundEventMetaData;

#ifndef _gccsoundeventmetadata_h
#define _gccsoundeventmetadata_h

#include "../../../scripting.h"




class GCSoundEventMetaData
{
private:
    void *m_ptr;

public:
    GCSoundEventMetaData() {}
    GCSoundEventMetaData(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif