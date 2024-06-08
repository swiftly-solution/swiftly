class GCCSGameRulesProxy;

#ifndef _gcccsgamerulesproxy_h
#define _gcccsgamerulesproxy_h

#include "../../../scripting.h"


#include "GCCSGameRules.h"

class GCCSGameRulesProxy
{
private:
    void *m_ptr;

public:
    GCCSGameRulesProxy() {}
    GCCSGameRulesProxy(void *ptr) : m_ptr(ptr) {}

    GCCSGameRules* GetGameRules() const { return GetSchemaValue<GCCSGameRules*>(m_ptr, "CCSGameRulesProxy", "m_pGameRules"); }
    void SetGameRules(GCCSGameRules* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'GameRules' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif