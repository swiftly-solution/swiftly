class Gragdollelement_t;

#ifndef _gcragdollelement_t_h
#define _gcragdollelement_t_h

#include "../../../scripting.h"




class Gragdollelement_t
{
private:
    void *m_ptr;

public:
    Gragdollelement_t() {}
    Gragdollelement_t(void *ptr) : m_ptr(ptr) {}

    Vector GetOriginParentSpace() const { return GetSchemaValue<Vector>(m_ptr, "ragdollelement_t", "originParentSpace"); }
    void SetOriginParentSpace(Vector value) { SetSchemaValue(m_ptr, "ragdollelement_t", "originParentSpace", true, value); }
    int32_t GetParentIndex() const { return GetSchemaValue<int32_t>(m_ptr, "ragdollelement_t", "parentIndex"); }
    void SetParentIndex(int32_t value) { SetSchemaValue(m_ptr, "ragdollelement_t", "parentIndex", true, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "ragdollelement_t", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "ragdollelement_t", "m_flRadius", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif