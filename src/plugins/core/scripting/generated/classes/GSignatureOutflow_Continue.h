class GSignatureOutflow_Continue;

#ifndef _gcsignatureoutflow_continue_h
#define _gcsignatureoutflow_continue_h

#include "../../../scripting.h"




class GSignatureOutflow_Continue
{
private:
    void *m_ptr;

public:
    GSignatureOutflow_Continue() {}
    GSignatureOutflow_Continue(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif