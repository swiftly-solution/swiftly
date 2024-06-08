class GVPhysXConstraint2_t;

#ifndef _gcvphysxconstraint2_t_h
#define _gcvphysxconstraint2_t_h

#include "../../../scripting.h"


#include "GVPhysXConstraintParams_t.h"

class GVPhysXConstraint2_t
{
private:
    void *m_ptr;

public:
    GVPhysXConstraint2_t() {}
    GVPhysXConstraint2_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "VPhysXConstraint2_t", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "VPhysXConstraint2_t", "m_nFlags", true, value); }
    uint16_t GetParent() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXConstraint2_t", "m_nParent"); }
    void SetParent(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXConstraint2_t", "m_nParent", true, value); }
    uint16_t GetChild() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXConstraint2_t", "m_nChild"); }
    void SetChild(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXConstraint2_t", "m_nChild", true, value); }
    GVPhysXConstraintParams_t GetParams() const { return GetSchemaValue<GVPhysXConstraintParams_t>(m_ptr, "VPhysXConstraint2_t", "m_params"); }
    void SetParams(GVPhysXConstraintParams_t value) { SetSchemaValue(m_ptr, "VPhysXConstraint2_t", "m_params", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif