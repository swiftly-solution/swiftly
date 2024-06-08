class GEventClientSceneSystemThreadStateChange_t;

#ifndef _gceventclientscenesystemthreadstatechange_t_h
#define _gceventclientscenesystemthreadstatechange_t_h

#include "../../../scripting.h"




class GEventClientSceneSystemThreadStateChange_t
{
private:
    void *m_ptr;

public:
    GEventClientSceneSystemThreadStateChange_t() {}
    GEventClientSceneSystemThreadStateChange_t(void *ptr) : m_ptr(ptr) {}

    bool GetThreadsActive() const { return GetSchemaValue<bool>(m_ptr, "EventClientSceneSystemThreadStateChange_t", "m_bThreadsActive"); }
    void SetThreadsActive(bool value) { SetSchemaValue(m_ptr, "EventClientSceneSystemThreadStateChange_t", "m_bThreadsActive", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif