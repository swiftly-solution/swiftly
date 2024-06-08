class GCVoiceContainerNull;

#ifndef _gccvoicecontainernull_h
#define _gccvoicecontainernull_h

#include "../../../scripting.h"




class GCVoiceContainerNull
{
private:
    void *m_ptr;

public:
    GCVoiceContainerNull() {}
    GCVoiceContainerNull(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif