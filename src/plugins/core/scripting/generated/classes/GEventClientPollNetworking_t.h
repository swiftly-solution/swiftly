class GEventClientPollNetworking_t;

#ifndef _gceventclientpollnetworking_t_h
#define _gceventclientpollnetworking_t_h

#include "../../../scripting.h"




class GEventClientPollNetworking_t
{
private:
    void *m_ptr;

public:
    GEventClientPollNetworking_t() {}
    GEventClientPollNetworking_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetTickCount() const { return GetSchemaValue<int32_t>(m_ptr, "EventClientPollNetworking_t", "m_nTickCount"); }
    void SetTickCount(int32_t value) { SetSchemaValue(m_ptr, "EventClientPollNetworking_t", "m_nTickCount", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif