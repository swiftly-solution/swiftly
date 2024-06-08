class GCommandToolCommand_t;

#ifndef _gccommandtoolcommand_t_h
#define _gccommandtoolcommand_t_h

#include "../../../scripting.h"

#include "../types/GCommandExecMode_t.h"
#include "../types/GCommandEntitySpecType_t.h"
#include "../types/GDebugOverlayBits_t.h"


class GCommandToolCommand_t
{
private:
    void *m_ptr;

public:
    GCommandToolCommand_t() {}
    GCommandToolCommand_t(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CommandToolCommand_t", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_bEnabled", true, value); }
    bool GetOpened() const { return GetSchemaValue<bool>(m_ptr, "CommandToolCommand_t", "m_bOpened"); }
    void SetOpened(bool value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_bOpened", true, value); }
    uint32_t GetInternalId() const { return GetSchemaValue<uint32_t>(m_ptr, "CommandToolCommand_t", "m_InternalId"); }
    void SetInternalId(uint32_t value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_InternalId", true, value); }
    CUtlString GetShortName() const { return GetSchemaValue<CUtlString>(m_ptr, "CommandToolCommand_t", "m_ShortName"); }
    void SetShortName(CUtlString value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_ShortName", true, value); }
    CommandExecMode_t GetExecMode() const { return GetSchemaValue<CommandExecMode_t>(m_ptr, "CommandToolCommand_t", "m_ExecMode"); }
    void SetExecMode(CommandExecMode_t value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_ExecMode", true, value); }
    CUtlString GetSpawnGroup() const { return GetSchemaValue<CUtlString>(m_ptr, "CommandToolCommand_t", "m_SpawnGroup"); }
    void SetSpawnGroup(CUtlString value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_SpawnGroup", true, value); }
    float GetPeriodicExecDelay() const { return GetSchemaValue<float>(m_ptr, "CommandToolCommand_t", "m_PeriodicExecDelay"); }
    void SetPeriodicExecDelay(float value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_PeriodicExecDelay", true, value); }
    CommandEntitySpecType_t GetSpecType() const { return GetSchemaValue<CommandEntitySpecType_t>(m_ptr, "CommandToolCommand_t", "m_SpecType"); }
    void SetSpecType(CommandEntitySpecType_t value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_SpecType", true, value); }
    CUtlString GetEntitySpec() const { return GetSchemaValue<CUtlString>(m_ptr, "CommandToolCommand_t", "m_EntitySpec"); }
    void SetEntitySpec(CUtlString value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_EntitySpec", true, value); }
    CUtlString GetCommands() const { return GetSchemaValue<CUtlString>(m_ptr, "CommandToolCommand_t", "m_Commands"); }
    void SetCommands(CUtlString value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_Commands", true, value); }
    DebugOverlayBits_t GetSetDebugBits() const { return GetSchemaValue<DebugOverlayBits_t>(m_ptr, "CommandToolCommand_t", "m_SetDebugBits"); }
    void SetSetDebugBits(DebugOverlayBits_t value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_SetDebugBits", true, value); }
    DebugOverlayBits_t GetClearDebugBits() const { return GetSchemaValue<DebugOverlayBits_t>(m_ptr, "CommandToolCommand_t", "m_ClearDebugBits"); }
    void SetClearDebugBits(DebugOverlayBits_t value) { SetSchemaValue(m_ptr, "CommandToolCommand_t", "m_ClearDebugBits", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif