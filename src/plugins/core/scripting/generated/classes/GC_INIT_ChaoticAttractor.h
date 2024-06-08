class GC_INIT_ChaoticAttractor;

#ifndef _gcc_init_chaoticattractor_h
#define _gcc_init_chaoticattractor_h

#include "../../../scripting.h"




class GC_INIT_ChaoticAttractor
{
private:
    void *m_ptr;

public:
    GC_INIT_ChaoticAttractor() {}
    GC_INIT_ChaoticAttractor(void *ptr) : m_ptr(ptr) {}

    float GetAParm() const { return GetSchemaValue<float>(m_ptr, "C_INIT_ChaoticAttractor", "m_flAParm"); }
    void SetAParm(float value) { SetSchemaValue(m_ptr, "C_INIT_ChaoticAttractor", "m_flAParm", false, value); }
    float GetBParm() const { return GetSchemaValue<float>(m_ptr, "C_INIT_ChaoticAttractor", "m_flBParm"); }
    void SetBParm(float value) { SetSchemaValue(m_ptr, "C_INIT_ChaoticAttractor", "m_flBParm", false, value); }
    float GetCParm() const { return GetSchemaValue<float>(m_ptr, "C_INIT_ChaoticAttractor", "m_flCParm"); }
    void SetCParm(float value) { SetSchemaValue(m_ptr, "C_INIT_ChaoticAttractor", "m_flCParm", false, value); }
    float GetDParm() const { return GetSchemaValue<float>(m_ptr, "C_INIT_ChaoticAttractor", "m_flDParm"); }
    void SetDParm(float value) { SetSchemaValue(m_ptr, "C_INIT_ChaoticAttractor", "m_flDParm", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_ChaoticAttractor", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_INIT_ChaoticAttractor", "m_flScale", false, value); }
    float GetSpeedMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_ChaoticAttractor", "m_flSpeedMin"); }
    void SetSpeedMin(float value) { SetSchemaValue(m_ptr, "C_INIT_ChaoticAttractor", "m_flSpeedMin", false, value); }
    float GetSpeedMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_ChaoticAttractor", "m_flSpeedMax"); }
    void SetSpeedMax(float value) { SetSchemaValue(m_ptr, "C_INIT_ChaoticAttractor", "m_flSpeedMax", false, value); }
    int32_t GetBaseCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_ChaoticAttractor", "m_nBaseCP"); }
    void SetBaseCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_ChaoticAttractor", "m_nBaseCP", false, value); }
    bool GetUniformSpeed() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_ChaoticAttractor", "m_bUniformSpeed"); }
    void SetUniformSpeed(bool value) { SetSchemaValue(m_ptr, "C_INIT_ChaoticAttractor", "m_bUniformSpeed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif