class GCVoiceContainerDefault;

#ifndef _gccvoicecontainerdefault_h
#define _gccvoicecontainerdefault_h

#include "../../../scripting.h"




class GCVoiceContainerDefault
{
private:
    void *m_ptr;

public:
    GCVoiceContainerDefault() {}
    GCVoiceContainerDefault(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif