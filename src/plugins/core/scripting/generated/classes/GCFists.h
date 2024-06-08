class GCFists;

#ifndef _gccfists_h
#define _gccfists_h

#include "../../../scripting.h"

#include "../types/GPlayerAnimEvent_t.h"
#include "GCBasePlayerWeapon.h"

class GCFists
{
private:
    void *m_ptr;

public:
    GCFists() {}
    GCFists(void *ptr) : m_ptr(ptr) {}

    bool GetPlayingUninterruptableAct() const { return GetSchemaValue<bool>(m_ptr, "CFists", "m_bPlayingUninterruptableAct"); }
    void SetPlayingUninterruptableAct(bool value) { SetSchemaValue(m_ptr, "CFists", "m_bPlayingUninterruptableAct", false, value); }
    PlayerAnimEvent_t GetUninterruptableActivity() const { return GetSchemaValue<PlayerAnimEvent_t>(m_ptr, "CFists", "m_nUninterruptableActivity"); }
    void SetUninterruptableActivity(PlayerAnimEvent_t value) { SetSchemaValue(m_ptr, "CFists", "m_nUninterruptableActivity", false, value); }
    bool GetRestorePrevWep() const { return GetSchemaValue<bool>(m_ptr, "CFists", "m_bRestorePrevWep"); }
    void SetRestorePrevWep(bool value) { SetSchemaValue(m_ptr, "CFists", "m_bRestorePrevWep", false, value); }
    GCBasePlayerWeapon* GetWeaponBeforePrevious() const { return GetSchemaValue<GCBasePlayerWeapon*>(m_ptr, "CFists", "m_hWeaponBeforePrevious"); }
    void SetWeaponBeforePrevious(GCBasePlayerWeapon* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'WeaponBeforePrevious' is not possible.\n"); }
    GCBasePlayerWeapon* GetWeaponPrevious() const { return GetSchemaValue<GCBasePlayerWeapon*>(m_ptr, "CFists", "m_hWeaponPrevious"); }
    void SetWeaponPrevious(GCBasePlayerWeapon* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'WeaponPrevious' is not possible.\n"); }
    bool GetDelayedHardPunchIncoming() const { return GetSchemaValue<bool>(m_ptr, "CFists", "m_bDelayedHardPunchIncoming"); }
    void SetDelayedHardPunchIncoming(bool value) { SetSchemaValue(m_ptr, "CFists", "m_bDelayedHardPunchIncoming", false, value); }
    bool GetDestroyAfterTaunt() const { return GetSchemaValue<bool>(m_ptr, "CFists", "m_bDestroyAfterTaunt"); }
    void SetDestroyAfterTaunt(bool value) { SetSchemaValue(m_ptr, "CFists", "m_bDestroyAfterTaunt", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif