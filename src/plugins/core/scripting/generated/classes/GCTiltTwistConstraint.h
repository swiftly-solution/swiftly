class GCTiltTwistConstraint;

#ifndef _gcctilttwistconstraint_h
#define _gcctilttwistconstraint_h

#include "../../../scripting.h"




class GCTiltTwistConstraint
{
private:
    void *m_ptr;

public:
    GCTiltTwistConstraint() {}
    GCTiltTwistConstraint(void *ptr) : m_ptr(ptr) {}

    int32_t GetTargetAxis() const { return GetSchemaValue<int32_t>(m_ptr, "CTiltTwistConstraint", "m_nTargetAxis"); }
    void SetTargetAxis(int32_t value) { SetSchemaValue(m_ptr, "CTiltTwistConstraint", "m_nTargetAxis", false, value); }
    int32_t GetSlaveAxis() const { return GetSchemaValue<int32_t>(m_ptr, "CTiltTwistConstraint", "m_nSlaveAxis"); }
    void SetSlaveAxis(int32_t value) { SetSchemaValue(m_ptr, "CTiltTwistConstraint", "m_nSlaveAxis", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif