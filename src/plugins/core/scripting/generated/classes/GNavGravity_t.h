class GNavGravity_t;

#ifndef _gcnavgravity_t_h
#define _gcnavgravity_t_h

#include "../../../scripting.h"




class GNavGravity_t
{
private:
    void *m_ptr;

public:
    GNavGravity_t() {}
    GNavGravity_t(void *ptr) : m_ptr(ptr) {}

    Vector GetGravity() const { return GetSchemaValue<Vector>(m_ptr, "NavGravity_t", "m_vGravity"); }
    void SetGravity(Vector value) { SetSchemaValue(m_ptr, "NavGravity_t", "m_vGravity", true, value); }
    bool GetDefault() const { return GetSchemaValue<bool>(m_ptr, "NavGravity_t", "m_bDefault"); }
    void SetDefault(bool value) { SetSchemaValue(m_ptr, "NavGravity_t", "m_bDefault", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif