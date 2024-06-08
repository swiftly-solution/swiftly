class GCTextureBasedAnimatable;

#ifndef _gcctexturebasedanimatable_h
#define _gcctexturebasedanimatable_h

#include "../../../scripting.h"




class GCTextureBasedAnimatable
{
private:
    void *m_ptr;

public:
    GCTextureBasedAnimatable() {}
    GCTextureBasedAnimatable(void *ptr) : m_ptr(ptr) {}

    bool GetLoop() const { return GetSchemaValue<bool>(m_ptr, "CTextureBasedAnimatable", "m_bLoop"); }
    void SetLoop(bool value) { SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_bLoop", false, value); }
    float GetFPS() const { return GetSchemaValue<float>(m_ptr, "CTextureBasedAnimatable", "m_flFPS"); }
    void SetFPS(float value) { SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_flFPS", false, value); }
    Vector GetAnimationBoundsMin() const { return GetSchemaValue<Vector>(m_ptr, "CTextureBasedAnimatable", "m_vAnimationBoundsMin"); }
    void SetAnimationBoundsMin(Vector value) { SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_vAnimationBoundsMin", false, value); }
    Vector GetAnimationBoundsMax() const { return GetSchemaValue<Vector>(m_ptr, "CTextureBasedAnimatable", "m_vAnimationBoundsMax"); }
    void SetAnimationBoundsMax(Vector value) { SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_vAnimationBoundsMax", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "CTextureBasedAnimatable", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_flStartTime", false, value); }
    float GetStartFrame() const { return GetSchemaValue<float>(m_ptr, "CTextureBasedAnimatable", "m_flStartFrame"); }
    void SetStartFrame(float value) { SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_flStartFrame", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif