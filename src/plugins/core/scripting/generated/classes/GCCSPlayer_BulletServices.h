class GCCSPlayer_BulletServices;

#ifndef _gcccsplayer_bulletservices_h
#define _gcccsplayer_bulletservices_h

#include "../../../scripting.h"




class GCCSPlayer_BulletServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_BulletServices() {}
    GCCSPlayer_BulletServices(void *ptr) : m_ptr(ptr) {}

    int32_t GetTotalHitsOnServer() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_BulletServices", "m_totalHitsOnServer"); }
    void SetTotalHitsOnServer(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_BulletServices", "m_totalHitsOnServer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif