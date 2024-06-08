class GCFuncNavBlocker;

#ifndef _gccfuncnavblocker_h
#define _gccfuncnavblocker_h

#include "../../../scripting.h"




class GCFuncNavBlocker
{
private:
    void *m_ptr;

public:
    GCFuncNavBlocker() {}
    GCFuncNavBlocker(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CFuncNavBlocker", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CFuncNavBlocker", "m_bDisabled", false, value); }
    int32_t GetBlockedTeamNumber() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncNavBlocker", "m_nBlockedTeamNumber"); }
    void SetBlockedTeamNumber(int32_t value) { SetSchemaValue(m_ptr, "CFuncNavBlocker", "m_nBlockedTeamNumber", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif