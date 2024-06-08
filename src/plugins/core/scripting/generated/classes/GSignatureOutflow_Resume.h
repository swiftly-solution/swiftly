class GSignatureOutflow_Resume;

#ifndef _gcsignatureoutflow_resume_h
#define _gcsignatureoutflow_resume_h

#include "../../../scripting.h"




class GSignatureOutflow_Resume
{
private:
    void *m_ptr;

public:
    GSignatureOutflow_Resume() {}
    GSignatureOutflow_Resume(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif