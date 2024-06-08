class GCPointValueRemapper;

#ifndef _gccpointvalueremapper_h
#define _gccpointvalueremapper_h

#include "../../../scripting.h"

#include "../types/GValueRemapperInputType_t.h"
#include "../types/GValueRemapperOutputType_t.h"
#include "../types/GValueRemapperHapticsType_t.h"
#include "../types/GValueRemapperMomentumType_t.h"
#include "../types/GValueRemapperRatchetType_t.h"
#include "GCBaseEntity.h"
#include "GCBasePlayerPawn.h"
#include "GCEntityIOOutput.h"

class GCPointValueRemapper
{
private:
    void *m_ptr;

public:
    GCPointValueRemapper() {}
    GCPointValueRemapper(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bDisabled", false, value); }
    bool GetUpdateOnClient() const { return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bUpdateOnClient"); }
    void SetUpdateOnClient(bool value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bUpdateOnClient", false, value); }
    ValueRemapperInputType_t GetInputType() const { return GetSchemaValue<ValueRemapperInputType_t>(m_ptr, "CPointValueRemapper", "m_nInputType"); }
    void SetInputType(ValueRemapperInputType_t value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nInputType", false, value); }
    CUtlSymbolLarge GetRemapLineStartName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszRemapLineStartName"); }
    void SetRemapLineStartName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszRemapLineStartName", false, value); }
    CUtlSymbolLarge GetRemapLineEndName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszRemapLineEndName"); }
    void SetRemapLineEndName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszRemapLineEndName", false, value); }
    GCBaseEntity* GetRemapLineStart() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointValueRemapper", "m_hRemapLineStart"); }
    void SetRemapLineStart(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'RemapLineStart' is not possible.\n"); }
    GCBaseEntity* GetRemapLineEnd() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointValueRemapper", "m_hRemapLineEnd"); }
    void SetRemapLineEnd(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'RemapLineEnd' is not possible.\n"); }
    float GetMaximumChangePerSecond() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flMaximumChangePerSecond"); }
    void SetMaximumChangePerSecond(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flMaximumChangePerSecond", false, value); }
    float GetDisengageDistance() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flDisengageDistance"); }
    void SetDisengageDistance(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flDisengageDistance", false, value); }
    float GetEngageDistance() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flEngageDistance"); }
    void SetEngageDistance(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flEngageDistance", false, value); }
    bool GetRequiresUseKey() const { return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bRequiresUseKey"); }
    void SetRequiresUseKey(bool value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bRequiresUseKey", false, value); }
    ValueRemapperOutputType_t GetOutputType() const { return GetSchemaValue<ValueRemapperOutputType_t>(m_ptr, "CPointValueRemapper", "m_nOutputType"); }
    void SetOutputType(ValueRemapperOutputType_t value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nOutputType", false, value); }
    CUtlSymbolLarge GetOutputEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszOutputEntityName"); }
    void SetOutputEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszOutputEntityName", false, value); }
    CUtlSymbolLarge GetOutputEntity2Name() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszOutputEntity2Name"); }
    void SetOutputEntity2Name(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszOutputEntity2Name", false, value); }
    CUtlSymbolLarge GetOutputEntity3Name() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszOutputEntity3Name"); }
    void SetOutputEntity3Name(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszOutputEntity3Name", false, value); }
    CUtlSymbolLarge GetOutputEntity4Name() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszOutputEntity4Name"); }
    void SetOutputEntity4Name(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszOutputEntity4Name", false, value); }
    GCBaseEntity* GetOutputEntities() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointValueRemapper", "m_hOutputEntities"); }
    void SetOutputEntities(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OutputEntities' is not possible.\n"); }
    ValueRemapperHapticsType_t GetHapticsType() const { return GetSchemaValue<ValueRemapperHapticsType_t>(m_ptr, "CPointValueRemapper", "m_nHapticsType"); }
    void SetHapticsType(ValueRemapperHapticsType_t value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nHapticsType", false, value); }
    ValueRemapperMomentumType_t GetMomentumType() const { return GetSchemaValue<ValueRemapperMomentumType_t>(m_ptr, "CPointValueRemapper", "m_nMomentumType"); }
    void SetMomentumType(ValueRemapperMomentumType_t value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nMomentumType", false, value); }
    float GetMomentumModifier() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flMomentumModifier"); }
    void SetMomentumModifier(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flMomentumModifier", false, value); }
    float GetSnapValue() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flSnapValue"); }
    void SetSnapValue(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flSnapValue", false, value); }
    float GetCurrentMomentum() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flCurrentMomentum"); }
    void SetCurrentMomentum(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flCurrentMomentum", false, value); }
    ValueRemapperRatchetType_t GetRatchetType() const { return GetSchemaValue<ValueRemapperRatchetType_t>(m_ptr, "CPointValueRemapper", "m_nRatchetType"); }
    void SetRatchetType(ValueRemapperRatchetType_t value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nRatchetType", false, value); }
    float GetRatchetOffset() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flRatchetOffset"); }
    void SetRatchetOffset(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flRatchetOffset", false, value); }
    float GetInputOffset() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flInputOffset"); }
    void SetInputOffset(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flInputOffset", false, value); }
    bool GetEngaged() const { return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bEngaged"); }
    void SetEngaged(bool value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bEngaged", false, value); }
    bool GetFirstUpdate() const { return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bFirstUpdate"); }
    void SetFirstUpdate(bool value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bFirstUpdate", false, value); }
    float GetPreviousValue() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flPreviousValue"); }
    void SetPreviousValue(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flPreviousValue", false, value); }
    Vector GetPreviousTestPoint() const { return GetSchemaValue<Vector>(m_ptr, "CPointValueRemapper", "m_vecPreviousTestPoint"); }
    void SetPreviousTestPoint(Vector value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_vecPreviousTestPoint", false, value); }
    GCBasePlayerPawn* GetUsingPlayer() const { return GetSchemaValue<GCBasePlayerPawn*>(m_ptr, "CPointValueRemapper", "m_hUsingPlayer"); }
    void SetUsingPlayer(GCBasePlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'UsingPlayer' is not possible.\n"); }
    float GetCustomOutputValue() const { return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flCustomOutputValue"); }
    void SetCustomOutputValue(float value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flCustomOutputValue", false, value); }
    CUtlSymbolLarge GetSoundEngage() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundEngage"); }
    void SetSoundEngage(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundEngage", false, value); }
    CUtlSymbolLarge GetSoundDisengage() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundDisengage"); }
    void SetSoundDisengage(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundDisengage", false, value); }
    CUtlSymbolLarge GetSoundReachedValueZero() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundReachedValueZero"); }
    void SetSoundReachedValueZero(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundReachedValueZero", false, value); }
    CUtlSymbolLarge GetSoundReachedValueOne() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundReachedValueOne"); }
    void SetSoundReachedValueOne(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundReachedValueOne", false, value); }
    CUtlSymbolLarge GetSoundMovingLoop() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundMovingLoop"); }
    void SetSoundMovingLoop(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundMovingLoop", false, value); }
    GCEntityIOOutput GetOnReachedValueZero() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointValueRemapper", "m_OnReachedValueZero"); }
    void SetOnReachedValueZero(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnReachedValueZero", false, value); }
    GCEntityIOOutput GetOnReachedValueOne() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointValueRemapper", "m_OnReachedValueOne"); }
    void SetOnReachedValueOne(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnReachedValueOne", false, value); }
    GCEntityIOOutput GetOnReachedValueCustom() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointValueRemapper", "m_OnReachedValueCustom"); }
    void SetOnReachedValueCustom(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnReachedValueCustom", false, value); }
    GCEntityIOOutput GetOnEngage() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointValueRemapper", "m_OnEngage"); }
    void SetOnEngage(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnEngage", false, value); }
    GCEntityIOOutput GetOnDisengage() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointValueRemapper", "m_OnDisengage"); }
    void SetOnDisengage(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnDisengage", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif