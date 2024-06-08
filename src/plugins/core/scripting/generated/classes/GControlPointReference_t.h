class GControlPointReference_t;

#ifndef _gccontrolpointreference_t_h
#define _gccontrolpointreference_t_h

#include "../../../scripting.h"




class GControlPointReference_t
{
private:
    void *m_ptr;

public:
    GControlPointReference_t() {}
    GControlPointReference_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNameString() const { return GetSchemaValue<int32_t>(m_ptr, "ControlPointReference_t", "m_controlPointNameString"); }
    void SetControlPointNameString(int32_t value) { SetSchemaValue(m_ptr, "ControlPointReference_t", "m_controlPointNameString", true, value); }
    Vector GetOffsetFromControlPoint() const { return GetSchemaValue<Vector>(m_ptr, "ControlPointReference_t", "m_vOffsetFromControlPoint"); }
    void SetOffsetFromControlPoint(Vector value) { SetSchemaValue(m_ptr, "ControlPointReference_t", "m_vOffsetFromControlPoint", true, value); }
    bool GetOffsetInLocalSpace() const { return GetSchemaValue<bool>(m_ptr, "ControlPointReference_t", "m_bOffsetInLocalSpace"); }
    void SetOffsetInLocalSpace(bool value) { SetSchemaValue(m_ptr, "ControlPointReference_t", "m_bOffsetInLocalSpace", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif