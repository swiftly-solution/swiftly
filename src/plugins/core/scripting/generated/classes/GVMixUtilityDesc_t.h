class GVMixUtilityDesc_t;

#ifndef _gcvmixutilitydesc_t_h
#define _gcvmixutilitydesc_t_h

#include "../../../scripting.h"

#include "../types/GVMixChannelOperation_t.h"


class GVMixUtilityDesc_t
{
private:
    void *m_ptr;

public:
    GVMixUtilityDesc_t() {}
    GVMixUtilityDesc_t(void *ptr) : m_ptr(ptr) {}

    VMixChannelOperation_t GetOp() const { return GetSchemaValue<VMixChannelOperation_t>(m_ptr, "VMixUtilityDesc_t", "m_nOp"); }
    void SetOp(VMixChannelOperation_t value) { SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_nOp", true, value); }
    float GetInputPan() const { return GetSchemaValue<float>(m_ptr, "VMixUtilityDesc_t", "m_flInputPan"); }
    void SetInputPan(float value) { SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_flInputPan", true, value); }
    float GetOutputBalance() const { return GetSchemaValue<float>(m_ptr, "VMixUtilityDesc_t", "m_flOutputBalance"); }
    void SetOutputBalance(float value) { SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_flOutputBalance", true, value); }
    float GetFldbOutputGain() const { return GetSchemaValue<float>(m_ptr, "VMixUtilityDesc_t", "m_fldbOutputGain"); }
    void SetFldbOutputGain(float value) { SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_fldbOutputGain", true, value); }
    bool GetBassMono() const { return GetSchemaValue<bool>(m_ptr, "VMixUtilityDesc_t", "m_bBassMono"); }
    void SetBassMono(bool value) { SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_bBassMono", true, value); }
    float GetBassFreq() const { return GetSchemaValue<float>(m_ptr, "VMixUtilityDesc_t", "m_flBassFreq"); }
    void SetBassFreq(float value) { SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_flBassFreq", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif