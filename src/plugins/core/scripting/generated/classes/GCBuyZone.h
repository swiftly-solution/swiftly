class GCBuyZone;

#ifndef _gccbuyzone_h
#define _gccbuyzone_h

#include "../../../scripting.h"




class GCBuyZone
{
private:
    void *m_ptr;

public:
    GCBuyZone() {}
    GCBuyZone(void *ptr) : m_ptr(ptr) {}

    int32_t GetLegacyTeamNum() const { return GetSchemaValue<int32_t>(m_ptr, "CBuyZone", "m_LegacyTeamNum"); }
    void SetLegacyTeamNum(int32_t value) { SetSchemaValue(m_ptr, "CBuyZone", "m_LegacyTeamNum", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif