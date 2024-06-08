class GCPointTemplateAPI;

#ifndef _gccpointtemplateapi_h
#define _gccpointtemplateapi_h

#include "../../../scripting.h"




class GCPointTemplateAPI
{
private:
    void *m_ptr;

public:
    GCPointTemplateAPI() {}
    GCPointTemplateAPI(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif