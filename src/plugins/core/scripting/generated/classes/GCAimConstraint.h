class GCAimConstraint;

#ifndef _gccaimconstraint_h
#define _gccaimconstraint_h

#include "../../../scripting.h"




class GCAimConstraint
{
private:
    void *m_ptr;

public:
    GCAimConstraint() {}
    GCAimConstraint(void *ptr) : m_ptr(ptr) {}

    Quaternion GetAimOffset() const { return GetSchemaValue<Quaternion>(m_ptr, "CAimConstraint", "m_qAimOffset"); }
    void SetAimOffset(Quaternion value) { SetSchemaValue(m_ptr, "CAimConstraint", "m_qAimOffset", false, value); }
    uint32_t GetUpType() const { return GetSchemaValue<uint32_t>(m_ptr, "CAimConstraint", "m_nUpType"); }
    void SetUpType(uint32_t value) { SetSchemaValue(m_ptr, "CAimConstraint", "m_nUpType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif