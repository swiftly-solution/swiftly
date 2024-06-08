class GC_OP_ConstrainLineLength;

#ifndef _gcc_op_constrainlinelength_h
#define _gcc_op_constrainlinelength_h

#include "../../../scripting.h"




class GC_OP_ConstrainLineLength
{
private:
    void *m_ptr;

public:
    GC_OP_ConstrainLineLength() {}
    GC_OP_ConstrainLineLength(void *ptr) : m_ptr(ptr) {}

    float GetMinDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainLineLength", "m_flMinDistance"); }
    void SetMinDistance(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainLineLength", "m_flMinDistance", false, value); }
    float GetMaxDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainLineLength", "m_flMaxDistance"); }
    void SetMaxDistance(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainLineLength", "m_flMaxDistance", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif