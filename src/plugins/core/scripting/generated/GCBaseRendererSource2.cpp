#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseRendererSource2::GCBaseRendererSource2(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseRendererSource2::GCBaseRendererSource2(void *ptr) {
    m_ptr = ptr;
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetRadiusScale() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flRadiusScale"));
    return value;
}
void GCBaseRendererSource2::SetRadiusScale(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flRadiusScale", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetAlphaScale() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flAlphaScale"));
    return value;
}
void GCBaseRendererSource2::SetAlphaScale(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flAlphaScale", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetRollScale() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flRollScale"));
    return value;
}
void GCBaseRendererSource2::SetRollScale(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flRollScale", false, value);
}
GParticleAttributeIndex_t GCBaseRendererSource2::GetAlpha2Field() const {
    GParticleAttributeIndex_t value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_nAlpha2Field"));
    return value;
}
void GCBaseRendererSource2::SetAlpha2Field(GParticleAttributeIndex_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nAlpha2Field", false, value);
}
GCParticleCollectionRendererVecInput GCBaseRendererSource2::GetColorScale() const {
    GCParticleCollectionRendererVecInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_vecColorScale"));
    return value;
}
void GCBaseRendererSource2::SetColorScale(GCParticleCollectionRendererVecInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_vecColorScale", false, value);
}
uint64_t GCBaseRendererSource2::GetColorBlendType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nColorBlendType");
}
void GCBaseRendererSource2::SetColorBlendType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nColorBlendType", false, value);
}
uint64_t GCBaseRendererSource2::GetShaderType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nShaderType");
}
void GCBaseRendererSource2::SetShaderType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nShaderType", false, value);
}
std::string GCBaseRendererSource2::GetStrShaderOverride() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBaseRendererSource2", "m_strShaderOverride").Get();
}
void GCBaseRendererSource2::SetStrShaderOverride(std::string value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_strShaderOverride", false, CUtlString(value.c_str()));
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetCenterXOffset() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flCenterXOffset"));
    return value;
}
void GCBaseRendererSource2::SetCenterXOffset(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flCenterXOffset", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetCenterYOffset() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flCenterYOffset"));
    return value;
}
void GCBaseRendererSource2::SetCenterYOffset(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flCenterYOffset", false, value);
}
float GCBaseRendererSource2::GetBumpStrength() const {
    return GetSchemaValue<float>(m_ptr, "CBaseRendererSource2", "m_flBumpStrength");
}
void GCBaseRendererSource2::SetBumpStrength(float value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flBumpStrength", false, value);
}
uint64_t GCBaseRendererSource2::GetCropTextureOverride() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nCropTextureOverride");
}
void GCBaseRendererSource2::SetCropTextureOverride(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nCropTextureOverride", false, value);
}
std::vector<GTextureGroup_t> GCBaseRendererSource2::GetTexturesInput() const {
    CUtlVector<GTextureGroup_t>* vec = GetSchemaValue<CUtlVector<GTextureGroup_t>*>(m_ptr, "CBaseRendererSource2", "m_vecTexturesInput"); std::vector<GTextureGroup_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBaseRendererSource2::SetTexturesInput(std::vector<GTextureGroup_t> value) {
    SetSchemaValueCUtlVector<GTextureGroup_t>(m_ptr, "CBaseRendererSource2", "m_vecTexturesInput", false, value);
}
float GCBaseRendererSource2::GetAnimationRate() const {
    return GetSchemaValue<float>(m_ptr, "CBaseRendererSource2", "m_flAnimationRate");
}
void GCBaseRendererSource2::SetAnimationRate(float value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flAnimationRate", false, value);
}
uint64_t GCBaseRendererSource2::GetAnimationType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nAnimationType");
}
void GCBaseRendererSource2::SetAnimationType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nAnimationType", false, value);
}
bool GCBaseRendererSource2::GetAnimateInFPS() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bAnimateInFPS");
}
void GCBaseRendererSource2::SetAnimateInFPS(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bAnimateInFPS", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetSelfIllumAmount() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flSelfIllumAmount"));
    return value;
}
void GCBaseRendererSource2::SetSelfIllumAmount(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flSelfIllumAmount", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetDiffuseAmount() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flDiffuseAmount"));
    return value;
}
void GCBaseRendererSource2::SetDiffuseAmount(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flDiffuseAmount", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetDiffuseClamp() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flDiffuseClamp"));
    return value;
}
void GCBaseRendererSource2::SetDiffuseClamp(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flDiffuseClamp", false, value);
}
int32_t GCBaseRendererSource2::GetLightingControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseRendererSource2", "m_nLightingControlPoint");
}
void GCBaseRendererSource2::SetLightingControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nLightingControlPoint", false, value);
}
GParticleAttributeIndex_t GCBaseRendererSource2::GetSelfIllumPerParticle() const {
    GParticleAttributeIndex_t value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_nSelfIllumPerParticle"));
    return value;
}
void GCBaseRendererSource2::SetSelfIllumPerParticle(GParticleAttributeIndex_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nSelfIllumPerParticle", false, value);
}
uint64_t GCBaseRendererSource2::GetOutputBlendMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nOutputBlendMode");
}
void GCBaseRendererSource2::SetOutputBlendMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nOutputBlendMode", false, value);
}
bool GCBaseRendererSource2::GetGammaCorrectVertexColors() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bGammaCorrectVertexColors");
}
void GCBaseRendererSource2::SetGammaCorrectVertexColors(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bGammaCorrectVertexColors", false, value);
}
bool GCBaseRendererSource2::GetSaturateColorPreAlphaBlend() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bSaturateColorPreAlphaBlend");
}
void GCBaseRendererSource2::SetSaturateColorPreAlphaBlend(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bSaturateColorPreAlphaBlend", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetAddSelfAmount() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flAddSelfAmount"));
    return value;
}
void GCBaseRendererSource2::SetAddSelfAmount(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flAddSelfAmount", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetDesaturation() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flDesaturation"));
    return value;
}
void GCBaseRendererSource2::SetDesaturation(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flDesaturation", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetOverbrightFactor() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flOverbrightFactor"));
    return value;
}
void GCBaseRendererSource2::SetOverbrightFactor(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flOverbrightFactor", false, value);
}
int32_t GCBaseRendererSource2::GetHSVShiftControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseRendererSource2", "m_nHSVShiftControlPoint");
}
void GCBaseRendererSource2::SetHSVShiftControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nHSVShiftControlPoint", false, value);
}
uint64_t GCBaseRendererSource2::GetFogType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nFogType");
}
void GCBaseRendererSource2::SetFogType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nFogType", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetFogAmount() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flFogAmount"));
    return value;
}
void GCBaseRendererSource2::SetFogAmount(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flFogAmount", false, value);
}
bool GCBaseRendererSource2::GetTintByFOW() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bTintByFOW");
}
void GCBaseRendererSource2::SetTintByFOW(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bTintByFOW", false, value);
}
bool GCBaseRendererSource2::GetTintByGlobalLight() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bTintByGlobalLight");
}
void GCBaseRendererSource2::SetTintByGlobalLight(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bTintByGlobalLight", false, value);
}
uint64_t GCBaseRendererSource2::GetPerParticleAlphaReference() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nPerParticleAlphaReference");
}
void GCBaseRendererSource2::SetPerParticleAlphaReference(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nPerParticleAlphaReference", false, value);
}
uint64_t GCBaseRendererSource2::GetPerParticleAlphaRefWindow() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nPerParticleAlphaRefWindow");
}
void GCBaseRendererSource2::SetPerParticleAlphaRefWindow(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nPerParticleAlphaRefWindow", false, value);
}
uint64_t GCBaseRendererSource2::GetAlphaReferenceType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nAlphaReferenceType");
}
void GCBaseRendererSource2::SetAlphaReferenceType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nAlphaReferenceType", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetAlphaReferenceSoftness() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flAlphaReferenceSoftness"));
    return value;
}
void GCBaseRendererSource2::SetAlphaReferenceSoftness(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flAlphaReferenceSoftness", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetSourceAlphaValueToMapToZero() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flSourceAlphaValueToMapToZero"));
    return value;
}
void GCBaseRendererSource2::SetSourceAlphaValueToMapToZero(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flSourceAlphaValueToMapToZero", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetSourceAlphaValueToMapToOne() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flSourceAlphaValueToMapToOne"));
    return value;
}
void GCBaseRendererSource2::SetSourceAlphaValueToMapToOne(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flSourceAlphaValueToMapToOne", false, value);
}
bool GCBaseRendererSource2::GetRefract() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bRefract");
}
void GCBaseRendererSource2::SetRefract(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bRefract", false, value);
}
bool GCBaseRendererSource2::GetRefractSolid() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bRefractSolid");
}
void GCBaseRendererSource2::SetRefractSolid(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bRefractSolid", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetRefractAmount() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flRefractAmount"));
    return value;
}
void GCBaseRendererSource2::SetRefractAmount(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flRefractAmount", false, value);
}
int32_t GCBaseRendererSource2::GetRefractBlurRadius() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseRendererSource2", "m_nRefractBlurRadius");
}
void GCBaseRendererSource2::SetRefractBlurRadius(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nRefractBlurRadius", false, value);
}
uint64_t GCBaseRendererSource2::GetRefractBlurType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nRefractBlurType");
}
void GCBaseRendererSource2::SetRefractBlurType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nRefractBlurType", false, value);
}
bool GCBaseRendererSource2::GetOnlyRenderInEffectsBloomPass() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffectsBloomPass");
}
void GCBaseRendererSource2::SetOnlyRenderInEffectsBloomPass(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffectsBloomPass", false, value);
}
bool GCBaseRendererSource2::GetOnlyRenderInEffectsWaterPass() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffectsWaterPass");
}
void GCBaseRendererSource2::SetOnlyRenderInEffectsWaterPass(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffectsWaterPass", false, value);
}
bool GCBaseRendererSource2::GetUseMixedResolutionRendering() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bUseMixedResolutionRendering");
}
void GCBaseRendererSource2::SetUseMixedResolutionRendering(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bUseMixedResolutionRendering", false, value);
}
bool GCBaseRendererSource2::GetOnlyRenderInEffecsGameOverlay() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffecsGameOverlay");
}
void GCBaseRendererSource2::SetOnlyRenderInEffecsGameOverlay(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffecsGameOverlay", false, value);
}
std::string GCBaseRendererSource2::GetStencilTestID() const {
    return GetSchemaValuePtr<char>(m_ptr, "CBaseRendererSource2", "m_stencilTestID");
}
void GCBaseRendererSource2::SetStencilTestID(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CBaseRendererSource2", "m_stencilTestID", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 128);
}
bool GCBaseRendererSource2::GetStencilTestExclude() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bStencilTestExclude");
}
void GCBaseRendererSource2::SetStencilTestExclude(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bStencilTestExclude", false, value);
}
std::string GCBaseRendererSource2::GetStencilWriteID() const {
    return GetSchemaValuePtr<char>(m_ptr, "CBaseRendererSource2", "m_stencilWriteID");
}
void GCBaseRendererSource2::SetStencilWriteID(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CBaseRendererSource2", "m_stencilWriteID", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 128);
}
bool GCBaseRendererSource2::GetWriteStencilOnDepthPass() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bWriteStencilOnDepthPass");
}
void GCBaseRendererSource2::SetWriteStencilOnDepthPass(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bWriteStencilOnDepthPass", false, value);
}
bool GCBaseRendererSource2::GetWriteStencilOnDepthFail() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bWriteStencilOnDepthFail");
}
void GCBaseRendererSource2::SetWriteStencilOnDepthFail(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bWriteStencilOnDepthFail", false, value);
}
bool GCBaseRendererSource2::GetReverseZBuffering() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bReverseZBuffering");
}
void GCBaseRendererSource2::SetReverseZBuffering(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bReverseZBuffering", false, value);
}
bool GCBaseRendererSource2::GetDisableZBuffering() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bDisableZBuffering");
}
void GCBaseRendererSource2::SetDisableZBuffering(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bDisableZBuffering", false, value);
}
uint64_t GCBaseRendererSource2::GetFeatheringMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nFeatheringMode");
}
void GCBaseRendererSource2::SetFeatheringMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nFeatheringMode", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetFeatheringMinDist() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flFeatheringMinDist"));
    return value;
}
void GCBaseRendererSource2::SetFeatheringMinDist(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flFeatheringMinDist", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetFeatheringMaxDist() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flFeatheringMaxDist"));
    return value;
}
void GCBaseRendererSource2::SetFeatheringMaxDist(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flFeatheringMaxDist", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetFeatheringFilter() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flFeatheringFilter"));
    return value;
}
void GCBaseRendererSource2::SetFeatheringFilter(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flFeatheringFilter", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseRendererSource2::GetDepthBias() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseRendererSource2", "m_flDepthBias"));
    return value;
}
void GCBaseRendererSource2::SetDepthBias(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flDepthBias", false, value);
}
uint64_t GCBaseRendererSource2::GetSortMethod() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseRendererSource2", "m_nSortMethod");
}
void GCBaseRendererSource2::SetSortMethod(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nSortMethod", false, value);
}
bool GCBaseRendererSource2::GetBlendFramesSeq0() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bBlendFramesSeq0");
}
void GCBaseRendererSource2::SetBlendFramesSeq0(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bBlendFramesSeq0", false, value);
}
bool GCBaseRendererSource2::GetMaxLuminanceBlendingSequence0() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bMaxLuminanceBlendingSequence0");
}
void GCBaseRendererSource2::SetMaxLuminanceBlendingSequence0(bool value) {
    SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bMaxLuminanceBlendingSequence0", false, value);
}
std::string GCBaseRendererSource2::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseRendererSource2::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunctionRenderer GCBaseRendererSource2::GetParent() const {
    GCParticleFunctionRenderer value(m_ptr);
    return value;
}
void GCBaseRendererSource2::SetParent(GCParticleFunctionRenderer value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseRendererSource2(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseRendererSource2>("CBaseRendererSource2")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RadiusScale", &GCBaseRendererSource2::GetRadiusScale, &GCBaseRendererSource2::SetRadiusScale)
        .addProperty("AlphaScale", &GCBaseRendererSource2::GetAlphaScale, &GCBaseRendererSource2::SetAlphaScale)
        .addProperty("RollScale", &GCBaseRendererSource2::GetRollScale, &GCBaseRendererSource2::SetRollScale)
        .addProperty("Alpha2Field", &GCBaseRendererSource2::GetAlpha2Field, &GCBaseRendererSource2::SetAlpha2Field)
        .addProperty("ColorScale", &GCBaseRendererSource2::GetColorScale, &GCBaseRendererSource2::SetColorScale)
        .addProperty("ColorBlendType", &GCBaseRendererSource2::GetColorBlendType, &GCBaseRendererSource2::SetColorBlendType)
        .addProperty("ShaderType", &GCBaseRendererSource2::GetShaderType, &GCBaseRendererSource2::SetShaderType)
        .addProperty("StrShaderOverride", &GCBaseRendererSource2::GetStrShaderOverride, &GCBaseRendererSource2::SetStrShaderOverride)
        .addProperty("CenterXOffset", &GCBaseRendererSource2::GetCenterXOffset, &GCBaseRendererSource2::SetCenterXOffset)
        .addProperty("CenterYOffset", &GCBaseRendererSource2::GetCenterYOffset, &GCBaseRendererSource2::SetCenterYOffset)
        .addProperty("BumpStrength", &GCBaseRendererSource2::GetBumpStrength, &GCBaseRendererSource2::SetBumpStrength)
        .addProperty("CropTextureOverride", &GCBaseRendererSource2::GetCropTextureOverride, &GCBaseRendererSource2::SetCropTextureOverride)
        .addProperty("TexturesInput", &GCBaseRendererSource2::GetTexturesInput, &GCBaseRendererSource2::SetTexturesInput)
        .addProperty("AnimationRate", &GCBaseRendererSource2::GetAnimationRate, &GCBaseRendererSource2::SetAnimationRate)
        .addProperty("AnimationType", &GCBaseRendererSource2::GetAnimationType, &GCBaseRendererSource2::SetAnimationType)
        .addProperty("AnimateInFPS", &GCBaseRendererSource2::GetAnimateInFPS, &GCBaseRendererSource2::SetAnimateInFPS)
        .addProperty("SelfIllumAmount", &GCBaseRendererSource2::GetSelfIllumAmount, &GCBaseRendererSource2::SetSelfIllumAmount)
        .addProperty("DiffuseAmount", &GCBaseRendererSource2::GetDiffuseAmount, &GCBaseRendererSource2::SetDiffuseAmount)
        .addProperty("DiffuseClamp", &GCBaseRendererSource2::GetDiffuseClamp, &GCBaseRendererSource2::SetDiffuseClamp)
        .addProperty("LightingControlPoint", &GCBaseRendererSource2::GetLightingControlPoint, &GCBaseRendererSource2::SetLightingControlPoint)
        .addProperty("SelfIllumPerParticle", &GCBaseRendererSource2::GetSelfIllumPerParticle, &GCBaseRendererSource2::SetSelfIllumPerParticle)
        .addProperty("OutputBlendMode", &GCBaseRendererSource2::GetOutputBlendMode, &GCBaseRendererSource2::SetOutputBlendMode)
        .addProperty("GammaCorrectVertexColors", &GCBaseRendererSource2::GetGammaCorrectVertexColors, &GCBaseRendererSource2::SetGammaCorrectVertexColors)
        .addProperty("SaturateColorPreAlphaBlend", &GCBaseRendererSource2::GetSaturateColorPreAlphaBlend, &GCBaseRendererSource2::SetSaturateColorPreAlphaBlend)
        .addProperty("AddSelfAmount", &GCBaseRendererSource2::GetAddSelfAmount, &GCBaseRendererSource2::SetAddSelfAmount)
        .addProperty("Desaturation", &GCBaseRendererSource2::GetDesaturation, &GCBaseRendererSource2::SetDesaturation)
        .addProperty("OverbrightFactor", &GCBaseRendererSource2::GetOverbrightFactor, &GCBaseRendererSource2::SetOverbrightFactor)
        .addProperty("HSVShiftControlPoint", &GCBaseRendererSource2::GetHSVShiftControlPoint, &GCBaseRendererSource2::SetHSVShiftControlPoint)
        .addProperty("FogType", &GCBaseRendererSource2::GetFogType, &GCBaseRendererSource2::SetFogType)
        .addProperty("FogAmount", &GCBaseRendererSource2::GetFogAmount, &GCBaseRendererSource2::SetFogAmount)
        .addProperty("TintByFOW", &GCBaseRendererSource2::GetTintByFOW, &GCBaseRendererSource2::SetTintByFOW)
        .addProperty("TintByGlobalLight", &GCBaseRendererSource2::GetTintByGlobalLight, &GCBaseRendererSource2::SetTintByGlobalLight)
        .addProperty("PerParticleAlphaReference", &GCBaseRendererSource2::GetPerParticleAlphaReference, &GCBaseRendererSource2::SetPerParticleAlphaReference)
        .addProperty("PerParticleAlphaRefWindow", &GCBaseRendererSource2::GetPerParticleAlphaRefWindow, &GCBaseRendererSource2::SetPerParticleAlphaRefWindow)
        .addProperty("AlphaReferenceType", &GCBaseRendererSource2::GetAlphaReferenceType, &GCBaseRendererSource2::SetAlphaReferenceType)
        .addProperty("AlphaReferenceSoftness", &GCBaseRendererSource2::GetAlphaReferenceSoftness, &GCBaseRendererSource2::SetAlphaReferenceSoftness)
        .addProperty("SourceAlphaValueToMapToZero", &GCBaseRendererSource2::GetSourceAlphaValueToMapToZero, &GCBaseRendererSource2::SetSourceAlphaValueToMapToZero)
        .addProperty("SourceAlphaValueToMapToOne", &GCBaseRendererSource2::GetSourceAlphaValueToMapToOne, &GCBaseRendererSource2::SetSourceAlphaValueToMapToOne)
        .addProperty("Refract", &GCBaseRendererSource2::GetRefract, &GCBaseRendererSource2::SetRefract)
        .addProperty("RefractSolid", &GCBaseRendererSource2::GetRefractSolid, &GCBaseRendererSource2::SetRefractSolid)
        .addProperty("RefractAmount", &GCBaseRendererSource2::GetRefractAmount, &GCBaseRendererSource2::SetRefractAmount)
        .addProperty("RefractBlurRadius", &GCBaseRendererSource2::GetRefractBlurRadius, &GCBaseRendererSource2::SetRefractBlurRadius)
        .addProperty("RefractBlurType", &GCBaseRendererSource2::GetRefractBlurType, &GCBaseRendererSource2::SetRefractBlurType)
        .addProperty("OnlyRenderInEffectsBloomPass", &GCBaseRendererSource2::GetOnlyRenderInEffectsBloomPass, &GCBaseRendererSource2::SetOnlyRenderInEffectsBloomPass)
        .addProperty("OnlyRenderInEffectsWaterPass", &GCBaseRendererSource2::GetOnlyRenderInEffectsWaterPass, &GCBaseRendererSource2::SetOnlyRenderInEffectsWaterPass)
        .addProperty("UseMixedResolutionRendering", &GCBaseRendererSource2::GetUseMixedResolutionRendering, &GCBaseRendererSource2::SetUseMixedResolutionRendering)
        .addProperty("OnlyRenderInEffecsGameOverlay", &GCBaseRendererSource2::GetOnlyRenderInEffecsGameOverlay, &GCBaseRendererSource2::SetOnlyRenderInEffecsGameOverlay)
        .addProperty("StencilTestID", &GCBaseRendererSource2::GetStencilTestID, &GCBaseRendererSource2::SetStencilTestID)
        .addProperty("StencilTestExclude", &GCBaseRendererSource2::GetStencilTestExclude, &GCBaseRendererSource2::SetStencilTestExclude)
        .addProperty("StencilWriteID", &GCBaseRendererSource2::GetStencilWriteID, &GCBaseRendererSource2::SetStencilWriteID)
        .addProperty("WriteStencilOnDepthPass", &GCBaseRendererSource2::GetWriteStencilOnDepthPass, &GCBaseRendererSource2::SetWriteStencilOnDepthPass)
        .addProperty("WriteStencilOnDepthFail", &GCBaseRendererSource2::GetWriteStencilOnDepthFail, &GCBaseRendererSource2::SetWriteStencilOnDepthFail)
        .addProperty("ReverseZBuffering", &GCBaseRendererSource2::GetReverseZBuffering, &GCBaseRendererSource2::SetReverseZBuffering)
        .addProperty("DisableZBuffering", &GCBaseRendererSource2::GetDisableZBuffering, &GCBaseRendererSource2::SetDisableZBuffering)
        .addProperty("FeatheringMode", &GCBaseRendererSource2::GetFeatheringMode, &GCBaseRendererSource2::SetFeatheringMode)
        .addProperty("FeatheringMinDist", &GCBaseRendererSource2::GetFeatheringMinDist, &GCBaseRendererSource2::SetFeatheringMinDist)
        .addProperty("FeatheringMaxDist", &GCBaseRendererSource2::GetFeatheringMaxDist, &GCBaseRendererSource2::SetFeatheringMaxDist)
        .addProperty("FeatheringFilter", &GCBaseRendererSource2::GetFeatheringFilter, &GCBaseRendererSource2::SetFeatheringFilter)
        .addProperty("DepthBias", &GCBaseRendererSource2::GetDepthBias, &GCBaseRendererSource2::SetDepthBias)
        .addProperty("SortMethod", &GCBaseRendererSource2::GetSortMethod, &GCBaseRendererSource2::SetSortMethod)
        .addProperty("BlendFramesSeq0", &GCBaseRendererSource2::GetBlendFramesSeq0, &GCBaseRendererSource2::SetBlendFramesSeq0)
        .addProperty("MaxLuminanceBlendingSequence0", &GCBaseRendererSource2::GetMaxLuminanceBlendingSequence0, &GCBaseRendererSource2::SetMaxLuminanceBlendingSequence0)
        .addProperty("Parent", &GCBaseRendererSource2::GetParent, &GCBaseRendererSource2::SetParent)
        .addFunction("ToPtr", &GCBaseRendererSource2::ToPtr)
        .addFunction("IsValid", &GCBaseRendererSource2::IsValid)
        .endClass();
}