class GFeTwistConstraint_t;

#ifndef _gcfetwistconstraint_t_h
#define _gcfetwistconstraint_t_h

#include "../../../scripting.h"




class GFeTwistConstraint_t
{
private:
    void *m_ptr;

public:
    GFeTwistConstraint_t() {}
    GFeTwistConstraint_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetNodeOrient() const { return GetSchemaValue<uint16_t>(m_ptr, "FeTwistConstraint_t", "nNodeOrient"); }
    void SetNodeOrient(uint16_t value) { SetSchemaValue(m_ptr, "FeTwistConstraint_t", "nNodeOrient", true, value); }
    uint16_t GetNodeEnd() const { return GetSchemaValue<uint16_t>(m_ptr, "FeTwistConstraint_t", "nNodeEnd"); }
    void SetNodeEnd(uint16_t value) { SetSchemaValue(m_ptr, "FeTwistConstraint_t", "nNodeEnd", true, value); }
    float GetTwistRelax() const { return GetSchemaValue<float>(m_ptr, "FeTwistConstraint_t", "flTwistRelax"); }
    void SetTwistRelax(float value) { SetSchemaValue(m_ptr, "FeTwistConstraint_t", "flTwistRelax", true, value); }
    float GetSwingRelax() const { return GetSchemaValue<float>(m_ptr, "FeTwistConstraint_t", "flSwingRelax"); }
    void SetSwingRelax(float value) { SetSchemaValue(m_ptr, "FeTwistConstraint_t", "flSwingRelax", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif