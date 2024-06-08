class GC_OP_FadeOut;

#ifndef _gcc_op_fadeout_h
#define _gcc_op_fadeout_h

#include "../../../scripting.h"




class GC_OP_FadeOut
{
private:
    void *m_ptr;

public:
    GC_OP_FadeOut() {}
    GC_OP_FadeOut(void *ptr) : m_ptr(ptr) {}

    float GetFadeOutTimeMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeOut", "m_flFadeOutTimeMin"); }
    void SetFadeOutTimeMin(float value) { SetSchemaValue(m_ptr, "C_OP_FadeOut", "m_flFadeOutTimeMin", false, value); }
    float GetFadeOutTimeMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeOut", "m_flFadeOutTimeMax"); }
    void SetFadeOutTimeMax(float value) { SetSchemaValue(m_ptr, "C_OP_FadeOut", "m_flFadeOutTimeMax", false, value); }
    float GetFadeOutTimeExp() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeOut", "m_flFadeOutTimeExp"); }
    void SetFadeOutTimeExp(float value) { SetSchemaValue(m_ptr, "C_OP_FadeOut", "m_flFadeOutTimeExp", false, value); }
    float GetFadeBias() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeOut", "m_flFadeBias"); }
    void SetFadeBias(float value) { SetSchemaValue(m_ptr, "C_OP_FadeOut", "m_flFadeBias", false, value); }
    bool GetProportional() const { return GetSchemaValue<bool>(m_ptr, "C_OP_FadeOut", "m_bProportional"); }
    void SetProportional(bool value) { SetSchemaValue(m_ptr, "C_OP_FadeOut", "m_bProportional", false, value); }
    bool GetEaseInAndOut() const { return GetSchemaValue<bool>(m_ptr, "C_OP_FadeOut", "m_bEaseInAndOut"); }
    void SetEaseInAndOut(bool value) { SetSchemaValue(m_ptr, "C_OP_FadeOut", "m_bEaseInAndOut", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif