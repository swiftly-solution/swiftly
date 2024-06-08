class GCTriggerToggleSave;

#ifndef _gcctriggertogglesave_h
#define _gcctriggertogglesave_h

#include "../../../scripting.h"




class GCTriggerToggleSave
{
private:
    void *m_ptr;

public:
    GCTriggerToggleSave() {}
    GCTriggerToggleSave(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif