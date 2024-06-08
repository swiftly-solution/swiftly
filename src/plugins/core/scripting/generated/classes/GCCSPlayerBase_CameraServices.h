class GCCSPlayerBase_CameraServices;

#ifndef _gcccsplayerbase_cameraservices_h
#define _gcccsplayerbase_cameraservices_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCCSPlayerBase_CameraServices
{
private:
    void *m_ptr;

public:
    GCCSPlayerBase_CameraServices() {}
    GCCSPlayerBase_CameraServices(void *ptr) : m_ptr(ptr) {}

    uint32_t GetFOV() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerBase_CameraServices", "m_iFOV"); }
    void SetFOV(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerBase_CameraServices", "m_iFOV", false, value); }
    uint32_t GetFOVStart() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerBase_CameraServices", "m_iFOVStart"); }
    void SetFOVStart(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerBase_CameraServices", "m_iFOVStart", false, value); }
    float GetFOVRate() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerBase_CameraServices", "m_flFOVRate"); }
    void SetFOVRate(float value) { SetSchemaValue(m_ptr, "CCSPlayerBase_CameraServices", "m_flFOVRate", false, value); }
    GCBaseEntity* GetZoomOwner() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSPlayerBase_CameraServices", "m_hZoomOwner"); }
    void SetZoomOwner(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ZoomOwner' is not possible.\n"); }
    GCBaseEntity* GetLastFogTrigger() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSPlayerBase_CameraServices", "m_hLastFogTrigger"); }
    void SetLastFogTrigger(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastFogTrigger' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif