class GCPointCamera;

#ifndef _gccpointcamera_h
#define _gccpointcamera_h

#include "../../../scripting.h"


#include "GCPointCamera.h"

class GCPointCamera
{
private:
    void *m_ptr;

public:
    GCPointCamera() {}
    GCPointCamera(void *ptr) : m_ptr(ptr) {}

    float GetFOV() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_FOV"); }
    void SetFOV(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_FOV", false, value); }
    float GetResolution() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_Resolution"); }
    void SetResolution(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_Resolution", false, value); }
    bool GetFogEnable() const { return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bFogEnable"); }
    void SetFogEnable(bool value) { SetSchemaValue(m_ptr, "CPointCamera", "m_bFogEnable", false, value); }
    Color GetFogColor() const { return GetSchemaValue<Color>(m_ptr, "CPointCamera", "m_FogColor"); }
    void SetFogColor(Color value) { SetSchemaValue(m_ptr, "CPointCamera", "m_FogColor", false, value); }
    float GetFogStart() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flFogStart"); }
    void SetFogStart(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flFogStart", false, value); }
    float GetFogEnd() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flFogEnd"); }
    void SetFogEnd(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flFogEnd", false, value); }
    float GetFogMaxDensity() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flFogMaxDensity"); }
    void SetFogMaxDensity(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flFogMaxDensity", false, value); }
    bool GetActive() const { return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bActive"); }
    void SetActive(bool value) { SetSchemaValue(m_ptr, "CPointCamera", "m_bActive", false, value); }
    bool GetUseScreenAspectRatio() const { return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bUseScreenAspectRatio"); }
    void SetUseScreenAspectRatio(bool value) { SetSchemaValue(m_ptr, "CPointCamera", "m_bUseScreenAspectRatio", false, value); }
    float GetAspectRatio() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flAspectRatio"); }
    void SetAspectRatio(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flAspectRatio", false, value); }
    bool GetNoSky() const { return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bNoSky"); }
    void SetNoSky(bool value) { SetSchemaValue(m_ptr, "CPointCamera", "m_bNoSky", false, value); }
    float GetBrightness() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_fBrightness"); }
    void SetBrightness(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_fBrightness", false, value); }
    float GetZFar() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flZFar"); }
    void SetZFar(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flZFar", false, value); }
    float GetZNear() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flZNear"); }
    void SetZNear(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flZNear", false, value); }
    bool GetCanHLTVUse() const { return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bCanHLTVUse"); }
    void SetCanHLTVUse(bool value) { SetSchemaValue(m_ptr, "CPointCamera", "m_bCanHLTVUse", false, value); }
    bool GetDofEnabled() const { return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bDofEnabled"); }
    void SetDofEnabled(bool value) { SetSchemaValue(m_ptr, "CPointCamera", "m_bDofEnabled", false, value); }
    float GetDofNearBlurry() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofNearBlurry"); }
    void SetDofNearBlurry(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flDofNearBlurry", false, value); }
    float GetDofNearCrisp() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofNearCrisp"); }
    void SetDofNearCrisp(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flDofNearCrisp", false, value); }
    float GetDofFarCrisp() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofFarCrisp"); }
    void SetDofFarCrisp(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flDofFarCrisp", false, value); }
    float GetDofFarBlurry() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofFarBlurry"); }
    void SetDofFarBlurry(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flDofFarBlurry", false, value); }
    float GetDofTiltToGround() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofTiltToGround"); }
    void SetDofTiltToGround(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_flDofTiltToGround", false, value); }
    float GetTargetFOV() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_TargetFOV"); }
    void SetTargetFOV(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_TargetFOV", false, value); }
    float GetDegreesPerSecond() const { return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_DegreesPerSecond"); }
    void SetDegreesPerSecond(float value) { SetSchemaValue(m_ptr, "CPointCamera", "m_DegreesPerSecond", false, value); }
    bool GetIsOn() const { return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bIsOn"); }
    void SetIsOn(bool value) { SetSchemaValue(m_ptr, "CPointCamera", "m_bIsOn", false, value); }
    GCPointCamera* GetNext() const { return GetSchemaValue<GCPointCamera*>(m_ptr, "CPointCamera", "m_pNext"); }
    void SetNext(GCPointCamera* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif