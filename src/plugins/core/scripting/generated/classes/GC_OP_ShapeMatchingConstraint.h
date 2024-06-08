class GC_OP_ShapeMatchingConstraint;

#ifndef _gcc_op_shapematchingconstraint_h
#define _gcc_op_shapematchingconstraint_h

#include "../../../scripting.h"




class GC_OP_ShapeMatchingConstraint
{
private:
    void *m_ptr;

public:
    GC_OP_ShapeMatchingConstraint() {}
    GC_OP_ShapeMatchingConstraint(void *ptr) : m_ptr(ptr) {}

    float GetShapeRestorationTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_ShapeMatchingConstraint", "m_flShapeRestorationTime"); }
    void SetShapeRestorationTime(float value) { SetSchemaValue(m_ptr, "C_OP_ShapeMatchingConstraint", "m_flShapeRestorationTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif