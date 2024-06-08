class GCItemDefuser;

#ifndef _gccitemdefuser_h
#define _gccitemdefuser_h

#include "../../../scripting.h"


#include "GEntitySpottedState_t.h"

class GCItemDefuser
{
private:
    void *m_ptr;

public:
    GCItemDefuser() {}
    GCItemDefuser(void *ptr) : m_ptr(ptr) {}

    GEntitySpottedState_t GetEntitySpottedState() const { return GetSchemaValue<GEntitySpottedState_t>(m_ptr, "CItemDefuser", "m_entitySpottedState"); }
    void SetEntitySpottedState(GEntitySpottedState_t value) { SetSchemaValue(m_ptr, "CItemDefuser", "m_entitySpottedState", false, value); }
    int32_t GetSpotRules() const { return GetSchemaValue<int32_t>(m_ptr, "CItemDefuser", "m_nSpotRules"); }
    void SetSpotRules(int32_t value) { SetSchemaValue(m_ptr, "CItemDefuser", "m_nSpotRules", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif