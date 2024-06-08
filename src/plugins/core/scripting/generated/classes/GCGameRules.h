class GCGameRules;

#ifndef _gccgamerules_h
#define _gccgamerules_h

#include "../../../scripting.h"


#include "GCNetworkVarChainer.h"

class GCGameRules
{
private:
    void *m_ptr;

public:
    GCGameRules() {}
    GCGameRules(void *ptr) : m_ptr(ptr) {}

    GCNetworkVarChainer Get__pChainEntity() const { return GetSchemaValue<GCNetworkVarChainer>(m_ptr, "CGameRules", "__m_pChainEntity"); }
    void Set__pChainEntity(GCNetworkVarChainer value) { SetSchemaValue(m_ptr, "CGameRules", "__m_pChainEntity", false, value); }
    std::string GetQuestName() const { return GetSchemaValue<char*>(m_ptr, "CGameRules", "m_szQuestName"); }
    void SetQuestName(std::string value) { SetSchemaValue(m_ptr, "CGameRules", "m_szQuestName", false, value); }
    int32_t GetQuestPhase() const { return GetSchemaValue<int32_t>(m_ptr, "CGameRules", "m_nQuestPhase"); }
    void SetQuestPhase(int32_t value) { SetSchemaValue(m_ptr, "CGameRules", "m_nQuestPhase", false, value); }
    int32_t GetTotalPausedTicks() const { return GetSchemaValue<int32_t>(m_ptr, "CGameRules", "m_nTotalPausedTicks"); }
    void SetTotalPausedTicks(int32_t value) { SetSchemaValue(m_ptr, "CGameRules", "m_nTotalPausedTicks", false, value); }
    int32_t GetPauseStartTick() const { return GetSchemaValue<int32_t>(m_ptr, "CGameRules", "m_nPauseStartTick"); }
    void SetPauseStartTick(int32_t value) { SetSchemaValue(m_ptr, "CGameRules", "m_nPauseStartTick", false, value); }
    bool GetGamePaused() const { return GetSchemaValue<bool>(m_ptr, "CGameRules", "m_bGamePaused"); }
    void SetGamePaused(bool value) { SetSchemaValue(m_ptr, "CGameRules", "m_bGamePaused", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif