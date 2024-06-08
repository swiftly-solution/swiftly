class GTextureControls_t;

#ifndef _gctexturecontrols_t_h
#define _gctexturecontrols_t_h

#include "../../../scripting.h"

#include "../types/GSpriteCardPerParticleScale_t.h"
#include "GCParticleCollectionRendererFloatInput.h"

class GTextureControls_t
{
private:
    void *m_ptr;

public:
    GTextureControls_t() {}
    GTextureControls_t(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionRendererFloatInput GetFinalTextureScaleU() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "TextureControls_t", "m_flFinalTextureScaleU"); }
    void SetFinalTextureScaleU(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureScaleU", true, value); }
    GCParticleCollectionRendererFloatInput GetFinalTextureScaleV() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "TextureControls_t", "m_flFinalTextureScaleV"); }
    void SetFinalTextureScaleV(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureScaleV", true, value); }
    GCParticleCollectionRendererFloatInput GetFinalTextureOffsetU() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "TextureControls_t", "m_flFinalTextureOffsetU"); }
    void SetFinalTextureOffsetU(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureOffsetU", true, value); }
    GCParticleCollectionRendererFloatInput GetFinalTextureOffsetV() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "TextureControls_t", "m_flFinalTextureOffsetV"); }
    void SetFinalTextureOffsetV(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureOffsetV", true, value); }
    GCParticleCollectionRendererFloatInput GetFinalTextureUVRotation() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "TextureControls_t", "m_flFinalTextureUVRotation"); }
    void SetFinalTextureUVRotation(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureUVRotation", true, value); }
    GCParticleCollectionRendererFloatInput GetZoomScale() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "TextureControls_t", "m_flZoomScale"); }
    void SetZoomScale(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_flZoomScale", true, value); }
    GCParticleCollectionRendererFloatInput GetDistortion() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "TextureControls_t", "m_flDistortion"); }
    void SetDistortion(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_flDistortion", true, value); }
    bool GetRandomizeOffsets() const { return GetSchemaValue<bool>(m_ptr, "TextureControls_t", "m_bRandomizeOffsets"); }
    void SetRandomizeOffsets(bool value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_bRandomizeOffsets", true, value); }
    bool GetClampUVs() const { return GetSchemaValue<bool>(m_ptr, "TextureControls_t", "m_bClampUVs"); }
    void SetClampUVs(bool value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_bClampUVs", true, value); }
    SpriteCardPerParticleScale_t GetPerParticleBlend() const { return GetSchemaValue<SpriteCardPerParticleScale_t>(m_ptr, "TextureControls_t", "m_nPerParticleBlend"); }
    void SetPerParticleBlend(SpriteCardPerParticleScale_t value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleBlend", true, value); }
    SpriteCardPerParticleScale_t GetPerParticleScale() const { return GetSchemaValue<SpriteCardPerParticleScale_t>(m_ptr, "TextureControls_t", "m_nPerParticleScale"); }
    void SetPerParticleScale(SpriteCardPerParticleScale_t value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleScale", true, value); }
    SpriteCardPerParticleScale_t GetPerParticleOffsetU() const { return GetSchemaValue<SpriteCardPerParticleScale_t>(m_ptr, "TextureControls_t", "m_nPerParticleOffsetU"); }
    void SetPerParticleOffsetU(SpriteCardPerParticleScale_t value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleOffsetU", true, value); }
    SpriteCardPerParticleScale_t GetPerParticleOffsetV() const { return GetSchemaValue<SpriteCardPerParticleScale_t>(m_ptr, "TextureControls_t", "m_nPerParticleOffsetV"); }
    void SetPerParticleOffsetV(SpriteCardPerParticleScale_t value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleOffsetV", true, value); }
    SpriteCardPerParticleScale_t GetPerParticleRotation() const { return GetSchemaValue<SpriteCardPerParticleScale_t>(m_ptr, "TextureControls_t", "m_nPerParticleRotation"); }
    void SetPerParticleRotation(SpriteCardPerParticleScale_t value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleRotation", true, value); }
    SpriteCardPerParticleScale_t GetPerParticleZoom() const { return GetSchemaValue<SpriteCardPerParticleScale_t>(m_ptr, "TextureControls_t", "m_nPerParticleZoom"); }
    void SetPerParticleZoom(SpriteCardPerParticleScale_t value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleZoom", true, value); }
    SpriteCardPerParticleScale_t GetPerParticleDistortion() const { return GetSchemaValue<SpriteCardPerParticleScale_t>(m_ptr, "TextureControls_t", "m_nPerParticleDistortion"); }
    void SetPerParticleDistortion(SpriteCardPerParticleScale_t value) { SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleDistortion", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif