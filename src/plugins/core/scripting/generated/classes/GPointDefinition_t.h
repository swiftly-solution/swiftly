class GPointDefinition_t;

#ifndef _gcpointdefinition_t_h
#define _gcpointdefinition_t_h

#include "../../../scripting.h"




class GPointDefinition_t
{
private:
    void *m_ptr;

public:
    GPointDefinition_t() {}
    GPointDefinition_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "PointDefinition_t", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "PointDefinition_t", "m_nControlPoint", true, value); }
    bool GetLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "PointDefinition_t", "m_bLocalCoords"); }
    void SetLocalCoords(bool value) { SetSchemaValue(m_ptr, "PointDefinition_t", "m_bLocalCoords", true, value); }
    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "PointDefinition_t", "m_vOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "PointDefinition_t", "m_vOffset", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif