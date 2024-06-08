class GCItemGenericTriggerHelper;

#ifndef _gccitemgenerictriggerhelper_h
#define _gccitemgenerictriggerhelper_h

#include "../../../scripting.h"




class GCItemGenericTriggerHelper
{
private:
    void *m_ptr;

public:
    GCItemGenericTriggerHelper() {}
    GCItemGenericTriggerHelper(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif