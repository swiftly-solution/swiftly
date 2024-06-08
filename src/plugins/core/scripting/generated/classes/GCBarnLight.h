class GCBarnLight;

#ifndef _gccbarnlight_h
#define _gccbarnlight_h

#include "../../../scripting.h"


#include "GCBaseModelEntity.h"
#include "GCEntityIOOutput.h"

class GCBarnLight
{
private:
    void *m_ptr;

public:
    GCBarnLight() {}
    GCBarnLight(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CBarnLight", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CBarnLight", "m_bEnabled", false, value); }
    int32_t GetColorMode() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nColorMode"); }
    void SetColorMode(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nColorMode", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CBarnLight", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CBarnLight", "m_Color", false, value); }
    float GetColorTemperature() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flColorTemperature"); }
    void SetColorTemperature(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flColorTemperature", false, value); }
    float GetBrightness() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flBrightness"); }
    void SetBrightness(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flBrightness", false, value); }
    float GetBrightnessScale() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flBrightnessScale"); }
    void SetBrightnessScale(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flBrightnessScale", false, value); }
    int32_t GetDirectLight() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nDirectLight"); }
    void SetDirectLight(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nDirectLight", false, value); }
    int32_t GetBakedShadowIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nBakedShadowIndex"); }
    void SetBakedShadowIndex(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nBakedShadowIndex", false, value); }
    int32_t GetLuminaireShape() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nLuminaireShape"); }
    void SetLuminaireShape(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nLuminaireShape", false, value); }
    float GetLuminaireSize() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flLuminaireSize"); }
    void SetLuminaireSize(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flLuminaireSize", false, value); }
    float GetLuminaireAnisotropy() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flLuminaireAnisotropy"); }
    void SetLuminaireAnisotropy(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flLuminaireAnisotropy", false, value); }
    CUtlString GetLightStyleString() const { return GetSchemaValue<CUtlString>(m_ptr, "CBarnLight", "m_LightStyleString"); }
    void SetLightStyleString(CUtlString value) { SetSchemaValue(m_ptr, "CBarnLight", "m_LightStyleString", false, value); }
    std::vector<CUtlString> GetQueuedLightStyleStrings() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CBarnLight", "m_QueuedLightStyleStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetQueuedLightStyleStrings(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CBarnLight", "m_QueuedLightStyleStrings", false, value); }
    std::vector<CUtlString> GetLightStyleEvents() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CBarnLight", "m_LightStyleEvents"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLightStyleEvents(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CBarnLight", "m_LightStyleEvents", false, value); }
    GCBaseModelEntity* GetLightStyleTargets() const { return GetSchemaValue<GCBaseModelEntity*>(m_ptr, "CBarnLight", "m_LightStyleTargets"); }
    void SetLightStyleTargets(GCBaseModelEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LightStyleTargets' is not possible.\n"); }
    std::vector<GCEntityIOOutput> GetStyleEvent() const { GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CBarnLight", "m_StyleEvent"); std::vector<GCEntityIOOutput> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetStyleEvent(std::vector<GCEntityIOOutput> value) { GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CBarnLight", "m_StyleEvent"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CBarnLight", "m_StyleEvent", false, outValue); }
    float GetShape() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flShape"); }
    void SetShape(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flShape", false, value); }
    float GetSoftX() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flSoftX"); }
    void SetSoftX(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flSoftX", false, value); }
    float GetSoftY() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flSoftY"); }
    void SetSoftY(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flSoftY", false, value); }
    float GetSkirt() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flSkirt"); }
    void SetSkirt(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flSkirt", false, value); }
    float GetSkirtNear() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flSkirtNear"); }
    void SetSkirtNear(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flSkirtNear", false, value); }
    Vector GetSizeParams() const { return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vSizeParams"); }
    void SetSizeParams(Vector value) { SetSchemaValue(m_ptr, "CBarnLight", "m_vSizeParams", false, value); }
    float GetRange() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flRange"); }
    void SetRange(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flRange", false, value); }
    Vector GetShear() const { return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vShear"); }
    void SetShear(Vector value) { SetSchemaValue(m_ptr, "CBarnLight", "m_vShear", false, value); }
    int32_t GetBakeSpecularToCubemaps() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nBakeSpecularToCubemaps"); }
    void SetBakeSpecularToCubemaps(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nBakeSpecularToCubemaps", false, value); }
    Vector GetBakeSpecularToCubemapsSize() const { return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vBakeSpecularToCubemapsSize"); }
    void SetBakeSpecularToCubemapsSize(Vector value) { SetSchemaValue(m_ptr, "CBarnLight", "m_vBakeSpecularToCubemapsSize", false, value); }
    int32_t GetCastShadows() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nCastShadows"); }
    void SetCastShadows(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nCastShadows", false, value); }
    int32_t GetShadowMapSize() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nShadowMapSize"); }
    void SetShadowMapSize(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nShadowMapSize", false, value); }
    int32_t GetShadowPriority() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nShadowPriority"); }
    void SetShadowPriority(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nShadowPriority", false, value); }
    bool GetContactShadow() const { return GetSchemaValue<bool>(m_ptr, "CBarnLight", "m_bContactShadow"); }
    void SetContactShadow(bool value) { SetSchemaValue(m_ptr, "CBarnLight", "m_bContactShadow", false, value); }
    int32_t GetBounceLight() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nBounceLight"); }
    void SetBounceLight(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nBounceLight", false, value); }
    float GetBounceScale() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flBounceScale"); }
    void SetBounceScale(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flBounceScale", false, value); }
    float GetMinRoughness() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flMinRoughness"); }
    void SetMinRoughness(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flMinRoughness", false, value); }
    Vector GetAlternateColor() const { return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vAlternateColor"); }
    void SetAlternateColor(Vector value) { SetSchemaValue(m_ptr, "CBarnLight", "m_vAlternateColor", false, value); }
    float GetAlternateColorBrightness() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_fAlternateColorBrightness"); }
    void SetAlternateColorBrightness(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_fAlternateColorBrightness", false, value); }
    int32_t GetFog() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nFog"); }
    void SetFog(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nFog", false, value); }
    float GetFogStrength() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flFogStrength"); }
    void SetFogStrength(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flFogStrength", false, value); }
    int32_t GetFogShadows() const { return GetSchemaValue<int32_t>(m_ptr, "CBarnLight", "m_nFogShadows"); }
    void SetFogShadows(int32_t value) { SetSchemaValue(m_ptr, "CBarnLight", "m_nFogShadows", false, value); }
    float GetFogScale() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flFogScale"); }
    void SetFogScale(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flFogScale", false, value); }
    float GetFadeSizeStart() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flFadeSizeStart"); }
    void SetFadeSizeStart(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flFadeSizeStart", false, value); }
    float GetFadeSizeEnd() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flFadeSizeEnd"); }
    void SetFadeSizeEnd(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flFadeSizeEnd", false, value); }
    float GetShadowFadeSizeStart() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flShadowFadeSizeStart"); }
    void SetShadowFadeSizeStart(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flShadowFadeSizeStart", false, value); }
    float GetShadowFadeSizeEnd() const { return GetSchemaValue<float>(m_ptr, "CBarnLight", "m_flShadowFadeSizeEnd"); }
    void SetShadowFadeSizeEnd(float value) { SetSchemaValue(m_ptr, "CBarnLight", "m_flShadowFadeSizeEnd", false, value); }
    bool GetPrecomputedFieldsValid() const { return GetSchemaValue<bool>(m_ptr, "CBarnLight", "m_bPrecomputedFieldsValid"); }
    void SetPrecomputedFieldsValid(bool value) { SetSchemaValue(m_ptr, "CBarnLight", "m_bPrecomputedFieldsValid", false, value); }
    Vector GetPrecomputedBoundsMins() const { return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vPrecomputedBoundsMins"); }
    void SetPrecomputedBoundsMins(Vector value) { SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedBoundsMins", false, value); }
    Vector GetPrecomputedBoundsMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vPrecomputedBoundsMaxs"); }
    void SetPrecomputedBoundsMaxs(Vector value) { SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedBoundsMaxs", false, value); }
    Vector GetPrecomputedOBBOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vPrecomputedOBBOrigin"); }
    void SetPrecomputedOBBOrigin(Vector value) { SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedOBBOrigin", false, value); }
    QAngle GetPrecomputedOBBAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CBarnLight", "m_vPrecomputedOBBAngles"); }
    void SetPrecomputedOBBAngles(QAngle value) { SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedOBBAngles", false, value); }
    Vector GetPrecomputedOBBExtent() const { return GetSchemaValue<Vector>(m_ptr, "CBarnLight", "m_vPrecomputedOBBExtent"); }
    void SetPrecomputedOBBExtent(Vector value) { SetSchemaValue(m_ptr, "CBarnLight", "m_vPrecomputedOBBExtent", false, value); }
    bool GetPvsModifyEntity() const { return GetSchemaValue<bool>(m_ptr, "CBarnLight", "m_bPvsModifyEntity"); }
    void SetPvsModifyEntity(bool value) { SetSchemaValue(m_ptr, "CBarnLight", "m_bPvsModifyEntity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif