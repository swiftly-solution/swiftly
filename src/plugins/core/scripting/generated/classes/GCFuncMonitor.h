class GCFuncMonitor;

#ifndef _gccfuncmonitor_h
#define _gccfuncmonitor_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCFuncMonitor
{
private:
    void *m_ptr;

public:
    GCFuncMonitor() {}
    GCFuncMonitor(void *ptr) : m_ptr(ptr) {}

    CUtlString GetTargetCamera() const { return GetSchemaValue<CUtlString>(m_ptr, "CFuncMonitor", "m_targetCamera"); }
    void SetTargetCamera(CUtlString value) { SetSchemaValue(m_ptr, "CFuncMonitor", "m_targetCamera", false, value); }
    int32_t GetResolutionEnum() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncMonitor", "m_nResolutionEnum"); }
    void SetResolutionEnum(int32_t value) { SetSchemaValue(m_ptr, "CFuncMonitor", "m_nResolutionEnum", false, value); }
    bool GetRenderShadows() const { return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bRenderShadows"); }
    void SetRenderShadows(bool value) { SetSchemaValue(m_ptr, "CFuncMonitor", "m_bRenderShadows", false, value); }
    bool GetUseUniqueColorTarget() const { return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bUseUniqueColorTarget"); }
    void SetUseUniqueColorTarget(bool value) { SetSchemaValue(m_ptr, "CFuncMonitor", "m_bUseUniqueColorTarget", false, value); }
    CUtlString GetBrushModelName() const { return GetSchemaValue<CUtlString>(m_ptr, "CFuncMonitor", "m_brushModelName"); }
    void SetBrushModelName(CUtlString value) { SetSchemaValue(m_ptr, "CFuncMonitor", "m_brushModelName", false, value); }
    GCBaseEntity* GetTargetCamera1() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CFuncMonitor", "m_hTargetCamera"); }
    void SetTargetCamera1(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetCamera1' is not possible.\n"); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CFuncMonitor", "m_bEnabled", false, value); }
    bool GetDraw3DSkybox() const { return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bDraw3DSkybox"); }
    void SetDraw3DSkybox(bool value) { SetSchemaValue(m_ptr, "CFuncMonitor", "m_bDraw3DSkybox", false, value); }
    bool GetStartEnabled() const { return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bStartEnabled"); }
    void SetStartEnabled(bool value) { SetSchemaValue(m_ptr, "CFuncMonitor", "m_bStartEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif