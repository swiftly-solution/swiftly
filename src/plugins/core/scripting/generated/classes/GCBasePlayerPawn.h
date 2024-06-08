class GCBasePlayerPawn;

#ifndef _gccbaseplayerpawn_h
#define _gccbaseplayerpawn_h

#include "../../../scripting.h"


#include "GCPlayer_WeaponServices.h"
#include "GCPlayer_ItemServices.h"
#include "GCPlayer_AutoaimServices.h"
#include "GCPlayer_ObserverServices.h"
#include "GCPlayer_WaterServices.h"
#include "GCPlayer_UseServices.h"
#include "GCPlayer_FlashlightServices.h"
#include "GCPlayer_CameraServices.h"
#include "GCPlayer_MovementServices.h"
#include "GViewAngleServerChange_t.h"
#include "Gsky3dparams_t.h"
#include "GCAI_Expresser.h"
#include "GCBasePlayerController.h"
#include "Gsndopvarlatchdata_t.h"

class GCBasePlayerPawn
{
private:
    void *m_ptr;

public:
    GCBasePlayerPawn() {}
    GCBasePlayerPawn(void *ptr) : m_ptr(ptr) {}

    GCPlayer_WeaponServices* GetWeaponServices() const { return GetSchemaValue<GCPlayer_WeaponServices*>(m_ptr, "CBasePlayerPawn", "m_pWeaponServices"); }
    void SetWeaponServices(GCPlayer_WeaponServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'WeaponServices' is not possible.\n"); }
    GCPlayer_ItemServices* GetItemServices() const { return GetSchemaValue<GCPlayer_ItemServices*>(m_ptr, "CBasePlayerPawn", "m_pItemServices"); }
    void SetItemServices(GCPlayer_ItemServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ItemServices' is not possible.\n"); }
    GCPlayer_AutoaimServices* GetAutoaimServices() const { return GetSchemaValue<GCPlayer_AutoaimServices*>(m_ptr, "CBasePlayerPawn", "m_pAutoaimServices"); }
    void SetAutoaimServices(GCPlayer_AutoaimServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'AutoaimServices' is not possible.\n"); }
    GCPlayer_ObserverServices* GetObserverServices() const { return GetSchemaValue<GCPlayer_ObserverServices*>(m_ptr, "CBasePlayerPawn", "m_pObserverServices"); }
    void SetObserverServices(GCPlayer_ObserverServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ObserverServices' is not possible.\n"); }
    GCPlayer_WaterServices* GetWaterServices() const { return GetSchemaValue<GCPlayer_WaterServices*>(m_ptr, "CBasePlayerPawn", "m_pWaterServices"); }
    void SetWaterServices(GCPlayer_WaterServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'WaterServices' is not possible.\n"); }
    GCPlayer_UseServices* GetUseServices() const { return GetSchemaValue<GCPlayer_UseServices*>(m_ptr, "CBasePlayerPawn", "m_pUseServices"); }
    void SetUseServices(GCPlayer_UseServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'UseServices' is not possible.\n"); }
    GCPlayer_FlashlightServices* GetFlashlightServices() const { return GetSchemaValue<GCPlayer_FlashlightServices*>(m_ptr, "CBasePlayerPawn", "m_pFlashlightServices"); }
    void SetFlashlightServices(GCPlayer_FlashlightServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'FlashlightServices' is not possible.\n"); }
    GCPlayer_CameraServices* GetCameraServices() const { return GetSchemaValue<GCPlayer_CameraServices*>(m_ptr, "CBasePlayerPawn", "m_pCameraServices"); }
    void SetCameraServices(GCPlayer_CameraServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CameraServices' is not possible.\n"); }
    GCPlayer_MovementServices* GetMovementServices() const { return GetSchemaValue<GCPlayer_MovementServices*>(m_ptr, "CBasePlayerPawn", "m_pMovementServices"); }
    void SetMovementServices(GCPlayer_MovementServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'MovementServices' is not possible.\n"); }
    std::vector<GViewAngleServerChange_t> GetServerViewAngleChanges() const { CUtlVector<GViewAngleServerChange_t>* vec = GetSchemaValue<CUtlVector<GViewAngleServerChange_t>*>(m_ptr, "CBasePlayerPawn", "m_ServerViewAngleChanges"); std::vector<GViewAngleServerChange_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetServerViewAngleChanges(std::vector<GViewAngleServerChange_t> value) { SetSchemaValueCUtlVector<GViewAngleServerChange_t>(m_ptr, "CBasePlayerPawn", "m_ServerViewAngleChanges", false, value); }
    uint32_t GetHighestGeneratedServerViewAngleChangeIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "CBasePlayerPawn", "m_nHighestGeneratedServerViewAngleChangeIndex"); }
    void SetHighestGeneratedServerViewAngleChangeIndex(uint32_t value) { SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_nHighestGeneratedServerViewAngleChangeIndex", false, value); }
    QAngle Get_angle() const { return GetSchemaValue<QAngle>(m_ptr, "CBasePlayerPawn", "v_angle"); }
    void Set_angle(QAngle value) { SetSchemaValue(m_ptr, "CBasePlayerPawn", "v_angle", false, value); }
    QAngle Get_anglePrevious() const { return GetSchemaValue<QAngle>(m_ptr, "CBasePlayerPawn", "v_anglePrevious"); }
    void Set_anglePrevious(QAngle value) { SetSchemaValue(m_ptr, "CBasePlayerPawn", "v_anglePrevious", false, value); }
    uint32_t GetHideHUD() const { return GetSchemaValue<uint32_t>(m_ptr, "CBasePlayerPawn", "m_iHideHUD"); }
    void SetHideHUD(uint32_t value) { SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_iHideHUD", false, value); }
    Gsky3dparams_t GetSkybox3d() const { return GetSchemaValue<Gsky3dparams_t>(m_ptr, "CBasePlayerPawn", "m_skybox3d"); }
    void SetSkybox3d(Gsky3dparams_t value) { SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_skybox3d", false, value); }
    bool GetInitHUD() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerPawn", "m_fInitHUD"); }
    void SetInitHUD(bool value) { SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_fInitHUD", false, value); }
    GCAI_Expresser* GetExpresser() const { return GetSchemaValue<GCAI_Expresser*>(m_ptr, "CBasePlayerPawn", "m_pExpresser"); }
    void SetExpresser(GCAI_Expresser* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Expresser' is not possible.\n"); }
    GCBasePlayerController* GetController() const { return GetSchemaValue<GCBasePlayerController*>(m_ptr, "CBasePlayerPawn", "m_hController"); }
    void SetController(GCBasePlayerController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Controller' is not possible.\n"); }
    float GetHltvReplayDelay() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerPawn", "m_fHltvReplayDelay"); }
    void SetHltvReplayDelay(float value) { SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_fHltvReplayDelay", false, value); }
    float GetHltvReplayEnd() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerPawn", "m_fHltvReplayEnd"); }
    void SetHltvReplayEnd(float value) { SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_fHltvReplayEnd", false, value); }
    CEntityIndex GetHltvReplayEntity() const { return GetSchemaValue<CEntityIndex>(m_ptr, "CBasePlayerPawn", "m_iHltvReplayEntity"); }
    void SetHltvReplayEntity(CEntityIndex value) { SetSchemaValue(m_ptr, "CBasePlayerPawn", "m_iHltvReplayEntity", false, value); }
    std::vector<Gsndopvarlatchdata_t> GetSndOpvarLatchData() const { CUtlVector<Gsndopvarlatchdata_t>* vec = GetSchemaValue<CUtlVector<Gsndopvarlatchdata_t>*>(m_ptr, "CBasePlayerPawn", "m_sndOpvarLatchData"); std::vector<Gsndopvarlatchdata_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSndOpvarLatchData(std::vector<Gsndopvarlatchdata_t> value) { SetSchemaValueCUtlVector<Gsndopvarlatchdata_t>(m_ptr, "CBasePlayerPawn", "m_sndOpvarLatchData", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif