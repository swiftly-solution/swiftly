class GC_OP_FadeIn;

#ifndef _gcc_op_fadein_h
#define _gcc_op_fadein_h

#include "../../../scripting.h"




class GC_OP_FadeIn
{
private:
    void *m_ptr;

public:
    GC_OP_FadeIn() {}
    GC_OP_FadeIn(void *ptr) : m_ptr(ptr) {}

    float GetFadeInTimeMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeIn", "m_flFadeInTimeMin"); }
    void SetFadeInTimeMin(float value) { SetSchemaValue(m_ptr, "C_OP_FadeIn", "m_flFadeInTimeMin", false, value); }
    float GetFadeInTimeMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeIn", "m_flFadeInTimeMax"); }
    void SetFadeInTimeMax(float value) { SetSchemaValue(m_ptr, "C_OP_FadeIn", "m_flFadeInTimeMax", false, value); }
    float GetFadeInTimeExp() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeIn", "m_flFadeInTimeExp"); }
    void SetFadeInTimeExp(float value) { SetSchemaValue(m_ptr, "C_OP_FadeIn", "m_flFadeInTimeExp", false, value); }
    bool GetProportional() const { return GetSchemaValue<bool>(m_ptr, "C_OP_FadeIn", "m_bProportional"); }
    void SetProportional(bool value) { SetSchemaValue(m_ptr, "C_OP_FadeIn", "m_bProportional", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif