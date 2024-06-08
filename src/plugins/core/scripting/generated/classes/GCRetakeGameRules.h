class GCRetakeGameRules;

#ifndef _gccretakegamerules_h
#define _gccretakegamerules_h

#include "../../../scripting.h"




class GCRetakeGameRules
{
private:
    void *m_ptr;

public:
    GCRetakeGameRules() {}
    GCRetakeGameRules(void *ptr) : m_ptr(ptr) {}

    int32_t GetMatchSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CRetakeGameRules", "m_nMatchSeed"); }
    void SetMatchSeed(int32_t value) { SetSchemaValue(m_ptr, "CRetakeGameRules", "m_nMatchSeed", false, value); }
    bool GetBlockersPresent() const { return GetSchemaValue<bool>(m_ptr, "CRetakeGameRules", "m_bBlockersPresent"); }
    void SetBlockersPresent(bool value) { SetSchemaValue(m_ptr, "CRetakeGameRules", "m_bBlockersPresent", false, value); }
    bool GetRoundInProgress() const { return GetSchemaValue<bool>(m_ptr, "CRetakeGameRules", "m_bRoundInProgress"); }
    void SetRoundInProgress(bool value) { SetSchemaValue(m_ptr, "CRetakeGameRules", "m_bRoundInProgress", false, value); }
    int32_t GetFirstSecondHalfRound() const { return GetSchemaValue<int32_t>(m_ptr, "CRetakeGameRules", "m_iFirstSecondHalfRound"); }
    void SetFirstSecondHalfRound(int32_t value) { SetSchemaValue(m_ptr, "CRetakeGameRules", "m_iFirstSecondHalfRound", false, value); }
    int32_t GetBombSite() const { return GetSchemaValue<int32_t>(m_ptr, "CRetakeGameRules", "m_iBombSite"); }
    void SetBombSite(int32_t value) { SetSchemaValue(m_ptr, "CRetakeGameRules", "m_iBombSite", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif