class GCCSPlayerController_InGameMoneyServices;

#ifndef _gcccsplayercontroller_ingamemoneyservices_h
#define _gcccsplayercontroller_ingamemoneyservices_h

#include "../../../scripting.h"




class GCCSPlayerController_InGameMoneyServices
{
private:
    void *m_ptr;

public:
    GCCSPlayerController_InGameMoneyServices() {}
    GCCSPlayerController_InGameMoneyServices(void *ptr) : m_ptr(ptr) {}

    bool GetReceivesMoneyNextRound() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_bReceivesMoneyNextRound"); }
    void SetReceivesMoneyNextRound(bool value) { SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_bReceivesMoneyNextRound", false, value); }
    int32_t GetMoneyEarnedForNextRound() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iMoneyEarnedForNextRound"); }
    void SetMoneyEarnedForNextRound(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iMoneyEarnedForNextRound", false, value); }
    int32_t GetAccount() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iAccount"); }
    void SetAccount(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iAccount", false, value); }
    int32_t GetStartAccount() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iStartAccount"); }
    void SetStartAccount(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iStartAccount", false, value); }
    int32_t GetTotalCashSpent() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iTotalCashSpent"); }
    void SetTotalCashSpent(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iTotalCashSpent", false, value); }
    int32_t GetCashSpentThisRound() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iCashSpentThisRound"); }
    void SetCashSpentThisRound(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iCashSpentThisRound", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif