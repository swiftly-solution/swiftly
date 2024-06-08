class GCMorphConstraint;

#ifndef _gccmorphconstraint_h
#define _gccmorphconstraint_h

#include "../../../scripting.h"




class GCMorphConstraint
{
private:
    void *m_ptr;

public:
    GCMorphConstraint() {}
    GCMorphConstraint(void *ptr) : m_ptr(ptr) {}

    CUtlString GetTargetMorph() const { return GetSchemaValue<CUtlString>(m_ptr, "CMorphConstraint", "m_sTargetMorph"); }
    void SetTargetMorph(CUtlString value) { SetSchemaValue(m_ptr, "CMorphConstraint", "m_sTargetMorph", false, value); }
    int32_t GetSlaveChannel() const { return GetSchemaValue<int32_t>(m_ptr, "CMorphConstraint", "m_nSlaveChannel"); }
    void SetSlaveChannel(int32_t value) { SetSchemaValue(m_ptr, "CMorphConstraint", "m_nSlaveChannel", false, value); }
    float GetMin() const { return GetSchemaValue<float>(m_ptr, "CMorphConstraint", "m_flMin"); }
    void SetMin(float value) { SetSchemaValue(m_ptr, "CMorphConstraint", "m_flMin", false, value); }
    float GetMax() const { return GetSchemaValue<float>(m_ptr, "CMorphConstraint", "m_flMax"); }
    void SetMax(float value) { SetSchemaValue(m_ptr, "CMorphConstraint", "m_flMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif