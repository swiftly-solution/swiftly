class GCGameMoney;

#ifndef _gccgamemoney_h
#define _gccgamemoney_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCGameMoney
{
private:
    void *m_ptr;

public:
    GCGameMoney() {}
    GCGameMoney(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnMoneySpent() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CGameMoney", "m_OnMoneySpent"); }
    void SetOnMoneySpent(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CGameMoney", "m_OnMoneySpent", false, value); }
    GCEntityIOOutput GetOnMoneySpentFail() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CGameMoney", "m_OnMoneySpentFail"); }
    void SetOnMoneySpentFail(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CGameMoney", "m_OnMoneySpentFail", false, value); }
    int32_t GetMoney() const { return GetSchemaValue<int32_t>(m_ptr, "CGameMoney", "m_nMoney"); }
    void SetMoney(int32_t value) { SetSchemaValue(m_ptr, "CGameMoney", "m_nMoney", false, value); }
    CUtlString GetStrAwardText() const { return GetSchemaValue<CUtlString>(m_ptr, "CGameMoney", "m_strAwardText"); }
    void SetStrAwardText(CUtlString value) { SetSchemaValue(m_ptr, "CGameMoney", "m_strAwardText", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif