class Gconstraint_hingeparams_t;

#ifndef _gcconstraint_hingeparams_t_h
#define _gcconstraint_hingeparams_t_h

#include "../../../scripting.h"


#include "Gconstraint_axislimit_t.h"
#include "Gconstraint_breakableparams_t.h"

class Gconstraint_hingeparams_t
{
private:
    void *m_ptr;

public:
    Gconstraint_hingeparams_t() {}
    Gconstraint_hingeparams_t(void *ptr) : m_ptr(ptr) {}

    Vector GetWorldPosition() const { return GetSchemaValue<Vector>(m_ptr, "constraint_hingeparams_t", "worldPosition"); }
    void SetWorldPosition(Vector value) { SetSchemaValue(m_ptr, "constraint_hingeparams_t", "worldPosition", true, value); }
    Vector GetWorldAxisDirection() const { return GetSchemaValue<Vector>(m_ptr, "constraint_hingeparams_t", "worldAxisDirection"); }
    void SetWorldAxisDirection(Vector value) { SetSchemaValue(m_ptr, "constraint_hingeparams_t", "worldAxisDirection", true, value); }
    Gconstraint_axislimit_t GetHingeAxis() const { return GetSchemaValue<Gconstraint_axislimit_t>(m_ptr, "constraint_hingeparams_t", "hingeAxis"); }
    void SetHingeAxis(Gconstraint_axislimit_t value) { SetSchemaValue(m_ptr, "constraint_hingeparams_t", "hingeAxis", true, value); }
    Gconstraint_breakableparams_t GetConstraint() const { return GetSchemaValue<Gconstraint_breakableparams_t>(m_ptr, "constraint_hingeparams_t", "constraint"); }
    void SetConstraint(Gconstraint_breakableparams_t value) { SetSchemaValue(m_ptr, "constraint_hingeparams_t", "constraint", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif