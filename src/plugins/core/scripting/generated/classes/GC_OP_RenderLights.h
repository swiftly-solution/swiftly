class GC_OP_RenderLights;

#ifndef _gcc_op_renderlights_h
#define _gcc_op_renderlights_h

#include "../../../scripting.h"

#include "../types/GAnimationType_t.h"


class GC_OP_RenderLights
{
private:
    void *m_ptr;

public:
    GC_OP_RenderLights() {}
    GC_OP_RenderLights(void *ptr) : m_ptr(ptr) {}

    float GetAnimationRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderLights", "m_flAnimationRate"); }
    void SetAnimationRate(float value) { SetSchemaValue(m_ptr, "C_OP_RenderLights", "m_flAnimationRate", false, value); }
    AnimationType_t GetAnimationType() const { return GetSchemaValue<AnimationType_t>(m_ptr, "C_OP_RenderLights", "m_nAnimationType"); }
    void SetAnimationType(AnimationType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderLights", "m_nAnimationType", false, value); }
    bool GetAnimateInFPS() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderLights", "m_bAnimateInFPS"); }
    void SetAnimateInFPS(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderLights", "m_bAnimateInFPS", false, value); }
    float GetMinSize() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderLights", "m_flMinSize"); }
    void SetMinSize(float value) { SetSchemaValue(m_ptr, "C_OP_RenderLights", "m_flMinSize", false, value); }
    float GetMaxSize() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderLights", "m_flMaxSize"); }
    void SetMaxSize(float value) { SetSchemaValue(m_ptr, "C_OP_RenderLights", "m_flMaxSize", false, value); }
    float GetStartFadeSize() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderLights", "m_flStartFadeSize"); }
    void SetStartFadeSize(float value) { SetSchemaValue(m_ptr, "C_OP_RenderLights", "m_flStartFadeSize", false, value); }
    float GetEndFadeSize() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderLights", "m_flEndFadeSize"); }
    void SetEndFadeSize(float value) { SetSchemaValue(m_ptr, "C_OP_RenderLights", "m_flEndFadeSize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif