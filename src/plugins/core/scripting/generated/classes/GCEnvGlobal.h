class GCEnvGlobal;

#ifndef _gccenvglobal_h
#define _gccenvglobal_h

#include "../../../scripting.h"




class GCEnvGlobal
{
private:
    void *m_ptr;

public:
    GCEnvGlobal() {}
    GCEnvGlobal(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetGlobalstate() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvGlobal", "m_globalstate"); }
    void SetGlobalstate(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvGlobal", "m_globalstate", false, value); }
    int32_t GetTriggermode() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvGlobal", "m_triggermode"); }
    void SetTriggermode(int32_t value) { SetSchemaValue(m_ptr, "CEnvGlobal", "m_triggermode", false, value); }
    int32_t GetInitialstate() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvGlobal", "m_initialstate"); }
    void SetInitialstate(int32_t value) { SetSchemaValue(m_ptr, "CEnvGlobal", "m_initialstate", false, value); }
    int32_t GetCounter() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvGlobal", "m_counter"); }
    void SetCounter(int32_t value) { SetSchemaValue(m_ptr, "CEnvGlobal", "m_counter", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif