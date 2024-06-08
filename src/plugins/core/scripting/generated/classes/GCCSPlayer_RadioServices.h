class GCCSPlayer_RadioServices;

#ifndef _gcccsplayer_radioservices_h
#define _gcccsplayer_radioservices_h

#include "../../../scripting.h"




class GCCSPlayer_RadioServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_RadioServices() {}
    GCCSPlayer_RadioServices(void *ptr) : m_ptr(ptr) {}

    bool GetIgnoreRadio() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_RadioServices", "m_bIgnoreRadio"); }
    void SetIgnoreRadio(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_RadioServices", "m_bIgnoreRadio", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif