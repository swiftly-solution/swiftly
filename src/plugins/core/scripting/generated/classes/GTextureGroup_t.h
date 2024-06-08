class GTextureGroup_t;

#ifndef _gctexturegroup_t_h
#define _gctexturegroup_t_h

#include "../../../scripting.h"

#include "../types/GSpriteCardTextureType_t.h"
#include "../types/GSpriteCardTextureChannel_t.h"
#include "../types/GParticleTextureLayerBlendType_t.h"
#include "GCParticleCollectionRendererFloatInput.h"
#include "GTextureControls_t.h"

class GTextureGroup_t
{
private:
    void *m_ptr;

public:
    GTextureGroup_t() {}
    GTextureGroup_t(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "TextureGroup_t", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "TextureGroup_t", "m_bEnabled", true, value); }
    bool GetReplaceTextureWithGradient() const { return GetSchemaValue<bool>(m_ptr, "TextureGroup_t", "m_bReplaceTextureWithGradient"); }
    void SetReplaceTextureWithGradient(bool value) { SetSchemaValue(m_ptr, "TextureGroup_t", "m_bReplaceTextureWithGradient", true, value); }
    SpriteCardTextureType_t GetTextureType() const { return GetSchemaValue<SpriteCardTextureType_t>(m_ptr, "TextureGroup_t", "m_nTextureType"); }
    void SetTextureType(SpriteCardTextureType_t value) { SetSchemaValue(m_ptr, "TextureGroup_t", "m_nTextureType", true, value); }
    SpriteCardTextureChannel_t GetTextureChannels() const { return GetSchemaValue<SpriteCardTextureChannel_t>(m_ptr, "TextureGroup_t", "m_nTextureChannels"); }
    void SetTextureChannels(SpriteCardTextureChannel_t value) { SetSchemaValue(m_ptr, "TextureGroup_t", "m_nTextureChannels", true, value); }
    ParticleTextureLayerBlendType_t GetTextureBlendMode() const { return GetSchemaValue<ParticleTextureLayerBlendType_t>(m_ptr, "TextureGroup_t", "m_nTextureBlendMode"); }
    void SetTextureBlendMode(ParticleTextureLayerBlendType_t value) { SetSchemaValue(m_ptr, "TextureGroup_t", "m_nTextureBlendMode", true, value); }
    GCParticleCollectionRendererFloatInput GetTextureBlend() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "TextureGroup_t", "m_flTextureBlend"); }
    void SetTextureBlend(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "TextureGroup_t", "m_flTextureBlend", true, value); }
    GTextureControls_t GetTextureControls() const { return GetSchemaValue<GTextureControls_t>(m_ptr, "TextureGroup_t", "m_TextureControls"); }
    void SetTextureControls(GTextureControls_t value) { SetSchemaValue(m_ptr, "TextureGroup_t", "m_TextureControls", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif