class GCTwistConstraint;

#ifndef _gcctwistconstraint_h
#define _gcctwistconstraint_h

#include "../../../scripting.h"




class GCTwistConstraint
{
private:
    void *m_ptr;

public:
    GCTwistConstraint() {}
    GCTwistConstraint(void *ptr) : m_ptr(ptr) {}

    bool GetInverse() const { return GetSchemaValue<bool>(m_ptr, "CTwistConstraint", "m_bInverse"); }
    void SetInverse(bool value) { SetSchemaValue(m_ptr, "CTwistConstraint", "m_bInverse", false, value); }
    Quaternion GetParentBindRotation() const { return GetSchemaValue<Quaternion>(m_ptr, "CTwistConstraint", "m_qParentBindRotation"); }
    void SetParentBindRotation(Quaternion value) { SetSchemaValue(m_ptr, "CTwistConstraint", "m_qParentBindRotation", false, value); }
    Quaternion GetChildBindRotation() const { return GetSchemaValue<Quaternion>(m_ptr, "CTwistConstraint", "m_qChildBindRotation"); }
    void SetChildBindRotation(Quaternion value) { SetSchemaValue(m_ptr, "CTwistConstraint", "m_qChildBindRotation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif