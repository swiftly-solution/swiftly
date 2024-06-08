class GC_OP_FadeAndKill;

#ifndef _gcc_op_fadeandkill_h
#define _gcc_op_fadeandkill_h

#include "../../../scripting.h"




class GC_OP_FadeAndKill
{
private:
    void *m_ptr;

public:
    GC_OP_FadeAndKill() {}
    GC_OP_FadeAndKill(void *ptr) : m_ptr(ptr) {}

    float GetStartFadeInTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKill", "m_flStartFadeInTime"); }
    void SetStartFadeInTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKill", "m_flStartFadeInTime", false, value); }
    float GetEndFadeInTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKill", "m_flEndFadeInTime"); }
    void SetEndFadeInTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKill", "m_flEndFadeInTime", false, value); }
    float GetStartFadeOutTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKill", "m_flStartFadeOutTime"); }
    void SetStartFadeOutTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKill", "m_flStartFadeOutTime", false, value); }
    float GetEndFadeOutTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKill", "m_flEndFadeOutTime"); }
    void SetEndFadeOutTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKill", "m_flEndFadeOutTime", false, value); }
    float GetStartAlpha() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKill", "m_flStartAlpha"); }
    void SetStartAlpha(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKill", "m_flStartAlpha", false, value); }
    float GetEndAlpha() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKill", "m_flEndAlpha"); }
    void SetEndAlpha(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKill", "m_flEndAlpha", false, value); }
    bool GetForcePreserveParticleOrder() const { return GetSchemaValue<bool>(m_ptr, "C_OP_FadeAndKill", "m_bForcePreserveParticleOrder"); }
    void SetForcePreserveParticleOrder(bool value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKill", "m_bForcePreserveParticleOrder", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif