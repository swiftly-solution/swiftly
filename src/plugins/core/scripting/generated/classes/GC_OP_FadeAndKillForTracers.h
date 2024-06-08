class GC_OP_FadeAndKillForTracers;

#ifndef _gcc_op_fadeandkillfortracers_h
#define _gcc_op_fadeandkillfortracers_h

#include "../../../scripting.h"




class GC_OP_FadeAndKillForTracers
{
private:
    void *m_ptr;

public:
    GC_OP_FadeAndKillForTracers() {}
    GC_OP_FadeAndKillForTracers(void *ptr) : m_ptr(ptr) {}

    float GetStartFadeInTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKillForTracers", "m_flStartFadeInTime"); }
    void SetStartFadeInTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKillForTracers", "m_flStartFadeInTime", false, value); }
    float GetEndFadeInTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKillForTracers", "m_flEndFadeInTime"); }
    void SetEndFadeInTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKillForTracers", "m_flEndFadeInTime", false, value); }
    float GetStartFadeOutTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKillForTracers", "m_flStartFadeOutTime"); }
    void SetStartFadeOutTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKillForTracers", "m_flStartFadeOutTime", false, value); }
    float GetEndFadeOutTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKillForTracers", "m_flEndFadeOutTime"); }
    void SetEndFadeOutTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKillForTracers", "m_flEndFadeOutTime", false, value); }
    float GetStartAlpha() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKillForTracers", "m_flStartAlpha"); }
    void SetStartAlpha(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKillForTracers", "m_flStartAlpha", false, value); }
    float GetEndAlpha() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeAndKillForTracers", "m_flEndAlpha"); }
    void SetEndAlpha(float value) { SetSchemaValue(m_ptr, "C_OP_FadeAndKillForTracers", "m_flEndAlpha", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif