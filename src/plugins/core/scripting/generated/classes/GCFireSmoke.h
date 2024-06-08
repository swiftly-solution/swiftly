class GCFireSmoke;

#ifndef _gccfiresmoke_h
#define _gccfiresmoke_h

#include "../../../scripting.h"




class GCFireSmoke
{
private:
    void *m_ptr;

public:
    GCFireSmoke() {}
    GCFireSmoke(void *ptr) : m_ptr(ptr) {}

    int32_t GetFlameModelIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CFireSmoke", "m_nFlameModelIndex"); }
    void SetFlameModelIndex(int32_t value) { SetSchemaValue(m_ptr, "CFireSmoke", "m_nFlameModelIndex", false, value); }
    int32_t GetFlameFromAboveModelIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CFireSmoke", "m_nFlameFromAboveModelIndex"); }
    void SetFlameFromAboveModelIndex(int32_t value) { SetSchemaValue(m_ptr, "CFireSmoke", "m_nFlameFromAboveModelIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif