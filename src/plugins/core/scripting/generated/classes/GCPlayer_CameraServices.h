class GCPlayer_CameraServices;

#ifndef _gccplayer_cameraservices_h
#define _gccplayer_cameraservices_h

#include "../../../scripting.h"


#include "Gfogplayerparams_t.h"
#include "GCColorCorrection.h"
#include "GCBaseEntity.h"
#include "GCTonemapController2.h"
#include "Gaudioparams_t.h"
#include "GCPostProcessingVolume.h"

class GCPlayer_CameraServices
{
private:
    void *m_ptr;

public:
    GCPlayer_CameraServices() {}
    GCPlayer_CameraServices(void *ptr) : m_ptr(ptr) {}

    QAngle GetCsViewPunchAngle() const { return GetSchemaValue<QAngle>(m_ptr, "CPlayer_CameraServices", "m_vecCsViewPunchAngle"); }
    void SetCsViewPunchAngle(QAngle value) { SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_vecCsViewPunchAngle", false, value); }
    float GetCsViewPunchAngleTickRatio() const { return GetSchemaValue<float>(m_ptr, "CPlayer_CameraServices", "m_flCsViewPunchAngleTickRatio"); }
    void SetCsViewPunchAngleTickRatio(float value) { SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_flCsViewPunchAngleTickRatio", false, value); }
    Gfogplayerparams_t GetPlayerFog() const { return GetSchemaValue<Gfogplayerparams_t>(m_ptr, "CPlayer_CameraServices", "m_PlayerFog"); }
    void SetPlayerFog(Gfogplayerparams_t value) { SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_PlayerFog", false, value); }
    GCColorCorrection* GetColorCorrectionCtrl() const { return GetSchemaValue<GCColorCorrection*>(m_ptr, "CPlayer_CameraServices", "m_hColorCorrectionCtrl"); }
    void SetColorCorrectionCtrl(GCColorCorrection* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ColorCorrectionCtrl' is not possible.\n"); }
    GCBaseEntity* GetViewEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPlayer_CameraServices", "m_hViewEntity"); }
    void SetViewEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ViewEntity' is not possible.\n"); }
    GCTonemapController2* GetTonemapController() const { return GetSchemaValue<GCTonemapController2*>(m_ptr, "CPlayer_CameraServices", "m_hTonemapController"); }
    void SetTonemapController(GCTonemapController2* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TonemapController' is not possible.\n"); }
    Gaudioparams_t GetAudio() const { return GetSchemaValue<Gaudioparams_t>(m_ptr, "CPlayer_CameraServices", "m_audio"); }
    void SetAudio(Gaudioparams_t value) { SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_audio", false, value); }
    GCPostProcessingVolume* GetPostProcessingVolumes() const { return GetSchemaValue<GCPostProcessingVolume*>(m_ptr, "CPlayer_CameraServices", "m_PostProcessingVolumes"); }
    void SetPostProcessingVolumes(GCPostProcessingVolume* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PostProcessingVolumes' is not possible.\n"); }
    float GetOldPlayerZ() const { return GetSchemaValue<float>(m_ptr, "CPlayer_CameraServices", "m_flOldPlayerZ"); }
    void SetOldPlayerZ(float value) { SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_flOldPlayerZ", false, value); }
    float GetOldPlayerViewOffsetZ() const { return GetSchemaValue<float>(m_ptr, "CPlayer_CameraServices", "m_flOldPlayerViewOffsetZ"); }
    void SetOldPlayerViewOffsetZ(float value) { SetSchemaValue(m_ptr, "CPlayer_CameraServices", "m_flOldPlayerViewOffsetZ", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif