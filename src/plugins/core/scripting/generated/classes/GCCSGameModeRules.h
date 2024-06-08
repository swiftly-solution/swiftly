class GCCSGameModeRules;

#ifndef _gcccsgamemoderules_h
#define _gcccsgamemoderules_h

#include "../../../scripting.h"


#include "GCNetworkVarChainer.h"

class GCCSGameModeRules
{
private:
    void *m_ptr;

public:
    GCCSGameModeRules() {}
    GCCSGameModeRules(void *ptr) : m_ptr(ptr) {}

    GCNetworkVarChainer Get__pChainEntity() const { return GetSchemaValue<GCNetworkVarChainer>(m_ptr, "CCSGameModeRules", "__m_pChainEntity"); }
    void Set__pChainEntity(GCNetworkVarChainer value) { SetSchemaValue(m_ptr, "CCSGameModeRules", "__m_pChainEntity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif