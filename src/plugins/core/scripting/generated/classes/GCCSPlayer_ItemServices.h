class GCCSPlayer_ItemServices;

#ifndef _gcccsplayer_itemservices_h
#define _gcccsplayer_itemservices_h

#include "../../../scripting.h"




class GCCSPlayer_ItemServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_ItemServices() {}
    GCCSPlayer_ItemServices(void *ptr) : m_ptr(ptr) {}

    bool GetHasDefuser() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_ItemServices", "m_bHasDefuser"); }
    void SetHasDefuser(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_ItemServices", "m_bHasDefuser", false, value); }
    bool GetHasHelmet() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_ItemServices", "m_bHasHelmet"); }
    void SetHasHelmet(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_ItemServices", "m_bHasHelmet", false, value); }
    bool GetHasHeavyArmor() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_ItemServices", "m_bHasHeavyArmor"); }
    void SetHasHeavyArmor(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_ItemServices", "m_bHasHeavyArmor", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif