class GCBaseViewModel;

#ifndef _gccbaseviewmodel_h
#define _gccbaseviewmodel_h

#include "../../../scripting.h"


#include "GCBasePlayerWeapon.h"
#include "GCBaseEntity.h"

class GCBaseViewModel
{
private:
    void *m_ptr;

public:
    GCBaseViewModel() {}
    GCBaseViewModel(void *ptr) : m_ptr(ptr) {}

    Vector GetLastFacing() const { return GetSchemaValue<Vector>(m_ptr, "CBaseViewModel", "m_vecLastFacing"); }
    void SetLastFacing(Vector value) { SetSchemaValue(m_ptr, "CBaseViewModel", "m_vecLastFacing", false, value); }
    uint32_t GetViewModelIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "CBaseViewModel", "m_nViewModelIndex"); }
    void SetViewModelIndex(uint32_t value) { SetSchemaValue(m_ptr, "CBaseViewModel", "m_nViewModelIndex", false, value); }
    uint32_t GetAnimationParity() const { return GetSchemaValue<uint32_t>(m_ptr, "CBaseViewModel", "m_nAnimationParity"); }
    void SetAnimationParity(uint32_t value) { SetSchemaValue(m_ptr, "CBaseViewModel", "m_nAnimationParity", false, value); }
    float GetAnimationStartTime() const { return GetSchemaValue<float>(m_ptr, "CBaseViewModel", "m_flAnimationStartTime"); }
    void SetAnimationStartTime(float value) { SetSchemaValue(m_ptr, "CBaseViewModel", "m_flAnimationStartTime", false, value); }
    GCBasePlayerWeapon* GetWeapon() const { return GetSchemaValue<GCBasePlayerWeapon*>(m_ptr, "CBaseViewModel", "m_hWeapon"); }
    void SetWeapon(GCBasePlayerWeapon* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Weapon' is not possible.\n"); }
    CUtlSymbolLarge GetVMName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseViewModel", "m_sVMName"); }
    void SetVMName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseViewModel", "m_sVMName", false, value); }
    CUtlSymbolLarge GetAnimationPrefix() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseViewModel", "m_sAnimationPrefix"); }
    void SetAnimationPrefix(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseViewModel", "m_sAnimationPrefix", false, value); }
    int32_t GetOldLayer() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseViewModel", "m_oldLayer"); }
    void SetOldLayer(int32_t value) { SetSchemaValue(m_ptr, "CBaseViewModel", "m_oldLayer", false, value); }
    float GetOldLayerStartTime() const { return GetSchemaValue<float>(m_ptr, "CBaseViewModel", "m_oldLayerStartTime"); }
    void SetOldLayerStartTime(float value) { SetSchemaValue(m_ptr, "CBaseViewModel", "m_oldLayerStartTime", false, value); }
    GCBaseEntity* GetControlPanel() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBaseViewModel", "m_hControlPanel"); }
    void SetControlPanel(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ControlPanel' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif