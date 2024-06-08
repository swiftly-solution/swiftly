class GCBaseButton;

#ifndef _gccbasebutton_h
#define _gccbasebutton_h

#include "../../../scripting.h"


#include "Glocksound_t.h"
#include "GCEntityIOOutput.h"
#include "GCEntityInstance.h"
#include "GCBaseModelEntity.h"

class GCBaseButton
{
private:
    void *m_ptr;

public:
    GCBaseButton() {}
    GCBaseButton(void *ptr) : m_ptr(ptr) {}

    QAngle GetMoveEntitySpace() const { return GetSchemaValue<QAngle>(m_ptr, "CBaseButton", "m_angMoveEntitySpace"); }
    void SetMoveEntitySpace(QAngle value) { SetSchemaValue(m_ptr, "CBaseButton", "m_angMoveEntitySpace", false, value); }
    bool GetStayPushed() const { return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_fStayPushed"); }
    void SetStayPushed(bool value) { SetSchemaValue(m_ptr, "CBaseButton", "m_fStayPushed", false, value); }
    bool GetRotating() const { return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_fRotating"); }
    void SetRotating(bool value) { SetSchemaValue(m_ptr, "CBaseButton", "m_fRotating", false, value); }
    Glocksound_t GetLs() const { return GetSchemaValue<Glocksound_t>(m_ptr, "CBaseButton", "m_ls"); }
    void SetLs(Glocksound_t value) { SetSchemaValue(m_ptr, "CBaseButton", "m_ls", false, value); }
    CUtlSymbolLarge GetUseSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sUseSound"); }
    void SetUseSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseButton", "m_sUseSound", false, value); }
    CUtlSymbolLarge GetLockedSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sLockedSound"); }
    void SetLockedSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseButton", "m_sLockedSound", false, value); }
    CUtlSymbolLarge GetUnlockedSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sUnlockedSound"); }
    void SetUnlockedSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseButton", "m_sUnlockedSound", false, value); }
    CUtlSymbolLarge GetOverrideAnticipationName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sOverrideAnticipationName"); }
    void SetOverrideAnticipationName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseButton", "m_sOverrideAnticipationName", false, value); }
    bool GetLocked() const { return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_bLocked"); }
    void SetLocked(bool value) { SetSchemaValue(m_ptr, "CBaseButton", "m_bLocked", false, value); }
    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CBaseButton", "m_bDisabled", false, value); }
    bool GetSolidBsp() const { return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_bSolidBsp"); }
    void SetSolidBsp(bool value) { SetSchemaValue(m_ptr, "CBaseButton", "m_bSolidBsp", false, value); }
    GCEntityIOOutput GetOnDamaged() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseButton", "m_OnDamaged"); }
    void SetOnDamaged(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseButton", "m_OnDamaged", false, value); }
    GCEntityIOOutput GetOnPressed() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseButton", "m_OnPressed"); }
    void SetOnPressed(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseButton", "m_OnPressed", false, value); }
    GCEntityIOOutput GetOnUseLocked() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseButton", "m_OnUseLocked"); }
    void SetOnUseLocked(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseButton", "m_OnUseLocked", false, value); }
    GCEntityIOOutput GetOnIn() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseButton", "m_OnIn"); }
    void SetOnIn(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseButton", "m_OnIn", false, value); }
    GCEntityIOOutput GetOnOut() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseButton", "m_OnOut"); }
    void SetOnOut(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseButton", "m_OnOut", false, value); }
    int32_t GetState() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseButton", "m_nState"); }
    void SetState(int32_t value) { SetSchemaValue(m_ptr, "CBaseButton", "m_nState", false, value); }
    GCEntityInstance* GetConstraint() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CBaseButton", "m_hConstraint"); }
    void SetConstraint(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Constraint' is not possible.\n"); }
    GCEntityInstance* GetConstraintParent() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CBaseButton", "m_hConstraintParent"); }
    void SetConstraintParent(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ConstraintParent' is not possible.\n"); }
    bool GetForceNpcExclude() const { return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_bForceNpcExclude"); }
    void SetForceNpcExclude(bool value) { SetSchemaValue(m_ptr, "CBaseButton", "m_bForceNpcExclude", false, value); }
    CUtlSymbolLarge GetGlowEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sGlowEntity"); }
    void SetGlowEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseButton", "m_sGlowEntity", false, value); }
    GCBaseModelEntity* GetGlowEntity1() const { return GetSchemaValue<GCBaseModelEntity*>(m_ptr, "CBaseButton", "m_glowEntity"); }
    void SetGlowEntity1(GCBaseModelEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'GlowEntity1' is not possible.\n"); }
    bool GetUsable() const { return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_usable"); }
    void SetUsable(bool value) { SetSchemaValue(m_ptr, "CBaseButton", "m_usable", false, value); }
    CUtlSymbolLarge GetDisplayText() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_szDisplayText"); }
    void SetDisplayText(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseButton", "m_szDisplayText", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif