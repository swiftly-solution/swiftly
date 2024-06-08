class GCParticleVisibilityInputs;

#ifndef _gccparticlevisibilityinputs_h
#define _gccparticlevisibilityinputs_h

#include "../../../scripting.h"




class GCParticleVisibilityInputs
{
private:
    void *m_ptr;

public:
    GCParticleVisibilityInputs() {}
    GCParticleVisibilityInputs(void *ptr) : m_ptr(ptr) {}

    float GetCameraBias() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flCameraBias"); }
    void SetCameraBias(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flCameraBias", false, value); }
    int32_t GetCPin() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleVisibilityInputs", "m_nCPin"); }
    void SetCPin(int32_t value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_nCPin", false, value); }
    float GetProxyRadius() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flProxyRadius"); }
    void SetProxyRadius(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flProxyRadius", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flInputMax", false, value); }
    float GetInputPixelVisFade() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flInputPixelVisFade"); }
    void SetInputPixelVisFade(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flInputPixelVisFade", false, value); }
    float GetNoPixelVisibilityFallback() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flNoPixelVisibilityFallback"); }
    void SetNoPixelVisibilityFallback(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flNoPixelVisibilityFallback", false, value); }
    float GetDistanceInputMin() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flDistanceInputMin"); }
    void SetDistanceInputMin(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flDistanceInputMin", false, value); }
    float GetDistanceInputMax() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flDistanceInputMax"); }
    void SetDistanceInputMax(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flDistanceInputMax", false, value); }
    float GetDotInputMin() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flDotInputMin"); }
    void SetDotInputMin(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flDotInputMin", false, value); }
    float GetDotInputMax() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flDotInputMax"); }
    void SetDotInputMax(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flDotInputMax", false, value); }
    bool GetDotCPAngles() const { return GetSchemaValue<bool>(m_ptr, "CParticleVisibilityInputs", "m_bDotCPAngles"); }
    void SetDotCPAngles(bool value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_bDotCPAngles", false, value); }
    bool GetDotCameraAngles() const { return GetSchemaValue<bool>(m_ptr, "CParticleVisibilityInputs", "m_bDotCameraAngles"); }
    void SetDotCameraAngles(bool value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_bDotCameraAngles", false, value); }
    float GetAlphaScaleMin() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flAlphaScaleMin"); }
    void SetAlphaScaleMin(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flAlphaScaleMin", false, value); }
    float GetAlphaScaleMax() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flAlphaScaleMax"); }
    void SetAlphaScaleMax(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flAlphaScaleMax", false, value); }
    float GetRadiusScaleMin() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleMin"); }
    void SetRadiusScaleMin(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleMin", false, value); }
    float GetRadiusScaleMax() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleMax"); }
    void SetRadiusScaleMax(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleMax", false, value); }
    float GetRadiusScaleFOVBase() const { return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleFOVBase"); }
    void SetRadiusScaleFOVBase(float value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleFOVBase", false, value); }
    bool GetRightEye() const { return GetSchemaValue<bool>(m_ptr, "CParticleVisibilityInputs", "m_bRightEye"); }
    void SetRightEye(bool value) { SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_bRightEye", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif