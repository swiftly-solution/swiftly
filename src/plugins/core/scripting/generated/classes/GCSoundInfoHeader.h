class GCSoundInfoHeader;

#ifndef _gccsoundinfoheader_h
#define _gccsoundinfoheader_h

#include "../../../scripting.h"




class GCSoundInfoHeader
{
private:
    void *m_ptr;

public:
    GCSoundInfoHeader() {}
    GCSoundInfoHeader(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif