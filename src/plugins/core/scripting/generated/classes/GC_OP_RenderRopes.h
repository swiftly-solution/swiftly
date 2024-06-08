class GC_OP_RenderRopes;

#ifndef _gcc_op_renderropes_h
#define _gcc_op_renderropes_h

#include "../../../scripting.h"

#include "../types/GParticleOrientationChoiceList_t.h"
#include "GCParticleCollectionRendererFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderRopes
{
private:
    void *m_ptr;

public:
    GC_OP_RenderRopes() {}
    GC_OP_RenderRopes(void *ptr) : m_ptr(ptr) {}

    bool GetEnableFadingAndClamping() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderRopes", "m_bEnableFadingAndClamping"); }
    void SetEnableFadingAndClamping(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_bEnableFadingAndClamping", false, value); }
    float GetMinSize() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flMinSize"); }
    void SetMinSize(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flMinSize", false, value); }
    float GetMaxSize() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flMaxSize"); }
    void SetMaxSize(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flMaxSize", false, value); }
    float GetStartFadeSize() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flStartFadeSize"); }
    void SetStartFadeSize(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flStartFadeSize", false, value); }
    float GetEndFadeSize() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flEndFadeSize"); }
    void SetEndFadeSize(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flEndFadeSize", false, value); }
    float GetStartFadeDot() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flStartFadeDot"); }
    void SetStartFadeDot(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flStartFadeDot", false, value); }
    float GetEndFadeDot() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flEndFadeDot"); }
    void SetEndFadeDot(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flEndFadeDot", false, value); }
    float GetRadiusTaper() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flRadiusTaper"); }
    void SetRadiusTaper(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flRadiusTaper", false, value); }
    int32_t GetMinTesselation() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderRopes", "m_nMinTesselation"); }
    void SetMinTesselation(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_nMinTesselation", false, value); }
    int32_t GetMaxTesselation() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderRopes", "m_nMaxTesselation"); }
    void SetMaxTesselation(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_nMaxTesselation", false, value); }
    float GetTessScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flTessScale"); }
    void SetTessScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flTessScale", false, value); }
    GCParticleCollectionRendererFloatInput GetTextureVWorldSize() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderRopes", "m_flTextureVWorldSize"); }
    void SetTextureVWorldSize(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flTextureVWorldSize", false, value); }
    GCParticleCollectionRendererFloatInput GetTextureVScrollRate() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderRopes", "m_flTextureVScrollRate"); }
    void SetTextureVScrollRate(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flTextureVScrollRate", false, value); }
    GCParticleCollectionRendererFloatInput GetTextureVOffset() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderRopes", "m_flTextureVOffset"); }
    void SetTextureVOffset(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flTextureVOffset", false, value); }
    int32_t GetTextureVParamsCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderRopes", "m_nTextureVParamsCP"); }
    void SetTextureVParamsCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_nTextureVParamsCP", false, value); }
    bool GetClampV() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderRopes", "m_bClampV"); }
    void SetClampV(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_bClampV", false, value); }
    int32_t GetScaleCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderRopes", "m_nScaleCP1"); }
    void SetScaleCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_nScaleCP1", false, value); }
    int32_t GetScaleCP2() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderRopes", "m_nScaleCP2"); }
    void SetScaleCP2(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_nScaleCP2", false, value); }
    float GetScaleVSizeByControlPointDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flScaleVSizeByControlPointDistance"); }
    void SetScaleVSizeByControlPointDistance(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flScaleVSizeByControlPointDistance", false, value); }
    float GetScaleVScrollByControlPointDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flScaleVScrollByControlPointDistance"); }
    void SetScaleVScrollByControlPointDistance(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flScaleVScrollByControlPointDistance", false, value); }
    float GetScaleVOffsetByControlPointDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flScaleVOffsetByControlPointDistance"); }
    void SetScaleVOffsetByControlPointDistance(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flScaleVOffsetByControlPointDistance", false, value); }
    bool GetUseScalarForTextureCoordinate() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderRopes", "m_bUseScalarForTextureCoordinate"); }
    void SetUseScalarForTextureCoordinate(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_bUseScalarForTextureCoordinate", false, value); }
    GParticleAttributeIndex_t GetScalarFieldForTextureCoordinate() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderRopes", "m_nScalarFieldForTextureCoordinate"); }
    void SetScalarFieldForTextureCoordinate(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_nScalarFieldForTextureCoordinate", false, value); }
    float GetScalarAttributeTextureCoordScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderRopes", "m_flScalarAttributeTextureCoordScale"); }
    void SetScalarAttributeTextureCoordScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_flScalarAttributeTextureCoordScale", false, value); }
    bool GetReverseOrder() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderRopes", "m_bReverseOrder"); }
    void SetReverseOrder(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_bReverseOrder", false, value); }
    bool GetClosedLoop() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderRopes", "m_bClosedLoop"); }
    void SetClosedLoop(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_bClosedLoop", false, value); }
    ParticleOrientationChoiceList_t GetOrientationType() const { return GetSchemaValue<ParticleOrientationChoiceList_t>(m_ptr, "C_OP_RenderRopes", "m_nOrientationType"); }
    void SetOrientationType(ParticleOrientationChoiceList_t value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_nOrientationType", false, value); }
    GParticleAttributeIndex_t GetVectorFieldForOrientation() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderRopes", "m_nVectorFieldForOrientation"); }
    void SetVectorFieldForOrientation(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_nVectorFieldForOrientation", false, value); }
    bool GetDrawAsOpaque() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderRopes", "m_bDrawAsOpaque"); }
    void SetDrawAsOpaque(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_bDrawAsOpaque", false, value); }
    bool GetGenerateNormals() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderRopes", "m_bGenerateNormals"); }
    void SetGenerateNormals(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderRopes", "m_bGenerateNormals", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif