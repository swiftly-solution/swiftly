class Gconstraint_breakableparams_t;

#ifndef _gcconstraint_breakableparams_t_h
#define _gcconstraint_breakableparams_t_h

#include "../../../scripting.h"




class Gconstraint_breakableparams_t
{
private:
    void *m_ptr;

public:
    Gconstraint_breakableparams_t() {}
    Gconstraint_breakableparams_t(void *ptr) : m_ptr(ptr) {}

    float GetStrength() const { return GetSchemaValue<float>(m_ptr, "constraint_breakableparams_t", "strength"); }
    void SetStrength(float value) { SetSchemaValue(m_ptr, "constraint_breakableparams_t", "strength", true, value); }
    float GetForceLimit() const { return GetSchemaValue<float>(m_ptr, "constraint_breakableparams_t", "forceLimit"); }
    void SetForceLimit(float value) { SetSchemaValue(m_ptr, "constraint_breakableparams_t", "forceLimit", true, value); }
    float GetTorqueLimit() const { return GetSchemaValue<float>(m_ptr, "constraint_breakableparams_t", "torqueLimit"); }
    void SetTorqueLimit(float value) { SetSchemaValue(m_ptr, "constraint_breakableparams_t", "torqueLimit", true, value); }
    std::vector<float> GetBodyMassScale() const { float* outValue = GetSchemaValue<float*>(m_ptr, "constraint_breakableparams_t", "bodyMassScale"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetBodyMassScale(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "constraint_breakableparams_t", "bodyMassScale"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "constraint_breakableparams_t", "bodyMassScale", true, outValue); }
    bool GetIsActive() const { return GetSchemaValue<bool>(m_ptr, "constraint_breakableparams_t", "isActive"); }
    void SetIsActive(bool value) { SetSchemaValue(m_ptr, "constraint_breakableparams_t", "isActive", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif