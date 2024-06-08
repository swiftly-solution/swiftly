class GCLightComponent;

#ifndef _gcclightcomponent_h
#define _gcclightcomponent_h

#include "../../../scripting.h"


#include "GCNetworkVarChainer.h"

class GCLightComponent
{
private:
    void *m_ptr;

public:
    GCLightComponent() {}
    GCLightComponent(void *ptr) : m_ptr(ptr) {}

    GCNetworkVarChainer Get__pChainEntity() const { return GetSchemaValue<GCNetworkVarChainer>(m_ptr, "CLightComponent", "__m_pChainEntity"); }
    void Set__pChainEntity(GCNetworkVarChainer value) { SetSchemaValue(m_ptr, "CLightComponent", "__m_pChainEntity", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CLightComponent", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CLightComponent", "m_Color", false, value); }
    Color GetSecondaryColor() const { return GetSchemaValue<Color>(m_ptr, "CLightComponent", "m_SecondaryColor"); }
    void SetSecondaryColor(Color value) { SetSchemaValue(m_ptr, "CLightComponent", "m_SecondaryColor", false, value); }
    float GetBrightness() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flBrightness"); }
    void SetBrightness(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flBrightness", false, value); }
    float GetBrightnessScale() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flBrightnessScale"); }
    void SetBrightnessScale(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flBrightnessScale", false, value); }
    float GetBrightnessMult() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flBrightnessMult"); }
    void SetBrightnessMult(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flBrightnessMult", false, value); }
    float GetRange() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flRange"); }
    void SetRange(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flRange", false, value); }
    float GetFalloff() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flFalloff"); }
    void SetFalloff(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flFalloff", false, value); }
    float GetAttenuation0() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flAttenuation0"); }
    void SetAttenuation0(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flAttenuation0", false, value); }
    float GetAttenuation1() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flAttenuation1"); }
    void SetAttenuation1(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flAttenuation1", false, value); }
    float GetAttenuation2() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flAttenuation2"); }
    void SetAttenuation2(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flAttenuation2", false, value); }
    float GetTheta() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flTheta"); }
    void SetTheta(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flTheta", false, value); }
    float GetPhi() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flPhi"); }
    void SetPhi(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flPhi", false, value); }
    int32_t GetCascades() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nCascades"); }
    void SetCascades(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nCascades", false, value); }
    int32_t GetCastShadows() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nCastShadows"); }
    void SetCastShadows(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nCastShadows", false, value); }
    int32_t GetShadowWidth() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowWidth"); }
    void SetShadowWidth(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowWidth", false, value); }
    int32_t GetShadowHeight() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowHeight"); }
    void SetShadowHeight(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowHeight", false, value); }
    bool GetRenderDiffuse() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bRenderDiffuse"); }
    void SetRenderDiffuse(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bRenderDiffuse", false, value); }
    int32_t GetRenderSpecular() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nRenderSpecular"); }
    void SetRenderSpecular(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nRenderSpecular", false, value); }
    bool GetRenderTransmissive() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bRenderTransmissive"); }
    void SetRenderTransmissive(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bRenderTransmissive", false, value); }
    float GetOrthoLightWidth() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flOrthoLightWidth"); }
    void SetOrthoLightWidth(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flOrthoLightWidth", false, value); }
    float GetOrthoLightHeight() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flOrthoLightHeight"); }
    void SetOrthoLightHeight(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flOrthoLightHeight", false, value); }
    int32_t GetStyle() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nStyle"); }
    void SetStyle(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nStyle", false, value); }
    CUtlString GetPattern() const { return GetSchemaValue<CUtlString>(m_ptr, "CLightComponent", "m_Pattern"); }
    void SetPattern(CUtlString value) { SetSchemaValue(m_ptr, "CLightComponent", "m_Pattern", false, value); }
    int32_t GetCascadeRenderStaticObjects() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nCascadeRenderStaticObjects"); }
    void SetCascadeRenderStaticObjects(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nCascadeRenderStaticObjects", false, value); }
    float GetShadowCascadeCrossFade() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeCrossFade"); }
    void SetShadowCascadeCrossFade(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeCrossFade", false, value); }
    float GetShadowCascadeDistanceFade() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistanceFade"); }
    void SetShadowCascadeDistanceFade(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistanceFade", false, value); }
    float GetShadowCascadeDistance0() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistance0"); }
    void SetShadowCascadeDistance0(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistance0", false, value); }
    float GetShadowCascadeDistance1() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistance1"); }
    void SetShadowCascadeDistance1(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistance1", false, value); }
    float GetShadowCascadeDistance2() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistance2"); }
    void SetShadowCascadeDistance2(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistance2", false, value); }
    float GetShadowCascadeDistance3() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowCascadeDistance3"); }
    void SetShadowCascadeDistance3(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowCascadeDistance3", false, value); }
    int32_t GetShadowCascadeResolution0() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowCascadeResolution0"); }
    void SetShadowCascadeResolution0(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowCascadeResolution0", false, value); }
    int32_t GetShadowCascadeResolution1() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowCascadeResolution1"); }
    void SetShadowCascadeResolution1(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowCascadeResolution1", false, value); }
    int32_t GetShadowCascadeResolution2() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowCascadeResolution2"); }
    void SetShadowCascadeResolution2(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowCascadeResolution2", false, value); }
    int32_t GetShadowCascadeResolution3() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowCascadeResolution3"); }
    void SetShadowCascadeResolution3(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowCascadeResolution3", false, value); }
    bool GetUsesBakedShadowing() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bUsesBakedShadowing"); }
    void SetUsesBakedShadowing(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bUsesBakedShadowing", false, value); }
    int32_t GetShadowPriority() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nShadowPriority"); }
    void SetShadowPriority(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nShadowPriority", false, value); }
    int32_t GetBakedShadowIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nBakedShadowIndex"); }
    void SetBakedShadowIndex(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nBakedShadowIndex", false, value); }
    bool GetRenderToCubemaps() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bRenderToCubemaps"); }
    void SetRenderToCubemaps(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bRenderToCubemaps", false, value); }
    int32_t GetDirectLight() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nDirectLight"); }
    void SetDirectLight(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nDirectLight", false, value); }
    int32_t GetIndirectLight() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nIndirectLight"); }
    void SetIndirectLight(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nIndirectLight", false, value); }
    float GetFadeMinDist() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flFadeMinDist"); }
    void SetFadeMinDist(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flFadeMinDist", false, value); }
    float GetFadeMaxDist() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flFadeMaxDist"); }
    void SetFadeMaxDist(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flFadeMaxDist", false, value); }
    float GetShadowFadeMinDist() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowFadeMinDist"); }
    void SetShadowFadeMinDist(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowFadeMinDist", false, value); }
    float GetShadowFadeMaxDist() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flShadowFadeMaxDist"); }
    void SetShadowFadeMaxDist(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flShadowFadeMaxDist", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bEnabled", false, value); }
    bool GetFlicker() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bFlicker"); }
    void SetFlicker(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bFlicker", false, value); }
    bool GetPrecomputedFieldsValid() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bPrecomputedFieldsValid"); }
    void SetPrecomputedFieldsValid(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bPrecomputedFieldsValid", false, value); }
    Vector GetPrecomputedBoundsMins() const { return GetSchemaValue<Vector>(m_ptr, "CLightComponent", "m_vPrecomputedBoundsMins"); }
    void SetPrecomputedBoundsMins(Vector value) { SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedBoundsMins", false, value); }
    Vector GetPrecomputedBoundsMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CLightComponent", "m_vPrecomputedBoundsMaxs"); }
    void SetPrecomputedBoundsMaxs(Vector value) { SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedBoundsMaxs", false, value); }
    Vector GetPrecomputedOBBOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CLightComponent", "m_vPrecomputedOBBOrigin"); }
    void SetPrecomputedOBBOrigin(Vector value) { SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedOBBOrigin", false, value); }
    QAngle GetPrecomputedOBBAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CLightComponent", "m_vPrecomputedOBBAngles"); }
    void SetPrecomputedOBBAngles(QAngle value) { SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedOBBAngles", false, value); }
    Vector GetPrecomputedOBBExtent() const { return GetSchemaValue<Vector>(m_ptr, "CLightComponent", "m_vPrecomputedOBBExtent"); }
    void SetPrecomputedOBBExtent(Vector value) { SetSchemaValue(m_ptr, "CLightComponent", "m_vPrecomputedOBBExtent", false, value); }
    float GetPrecomputedMaxRange() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flPrecomputedMaxRange"); }
    void SetPrecomputedMaxRange(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flPrecomputedMaxRange", false, value); }
    int32_t GetFogLightingMode() const { return GetSchemaValue<int32_t>(m_ptr, "CLightComponent", "m_nFogLightingMode"); }
    void SetFogLightingMode(int32_t value) { SetSchemaValue(m_ptr, "CLightComponent", "m_nFogLightingMode", false, value); }
    float GetFogContributionStength() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flFogContributionStength"); }
    void SetFogContributionStength(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flFogContributionStength", false, value); }
    float GetNearClipPlane() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flNearClipPlane"); }
    void SetNearClipPlane(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flNearClipPlane", false, value); }
    Color GetSkyColor() const { return GetSchemaValue<Color>(m_ptr, "CLightComponent", "m_SkyColor"); }
    void SetSkyColor(Color value) { SetSchemaValue(m_ptr, "CLightComponent", "m_SkyColor", false, value); }
    float GetSkyIntensity() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flSkyIntensity"); }
    void SetSkyIntensity(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flSkyIntensity", false, value); }
    Color GetSkyAmbientBounce() const { return GetSchemaValue<Color>(m_ptr, "CLightComponent", "m_SkyAmbientBounce"); }
    void SetSkyAmbientBounce(Color value) { SetSchemaValue(m_ptr, "CLightComponent", "m_SkyAmbientBounce", false, value); }
    bool GetUseSecondaryColor() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bUseSecondaryColor"); }
    void SetUseSecondaryColor(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bUseSecondaryColor", false, value); }
    bool GetMixedShadows() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bMixedShadows"); }
    void SetMixedShadows(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bMixedShadows", false, value); }
    float GetCapsuleLength() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flCapsuleLength"); }
    void SetCapsuleLength(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flCapsuleLength", false, value); }
    float GetMinRoughness() const { return GetSchemaValue<float>(m_ptr, "CLightComponent", "m_flMinRoughness"); }
    void SetMinRoughness(float value) { SetSchemaValue(m_ptr, "CLightComponent", "m_flMinRoughness", false, value); }
    bool GetPvsModifyEntity() const { return GetSchemaValue<bool>(m_ptr, "CLightComponent", "m_bPvsModifyEntity"); }
    void SetPvsModifyEntity(bool value) { SetSchemaValue(m_ptr, "CLightComponent", "m_bPvsModifyEntity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif