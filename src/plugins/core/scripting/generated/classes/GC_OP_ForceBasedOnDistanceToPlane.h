class GC_OP_ForceBasedOnDistanceToPlane;

#ifndef _gcc_op_forcebasedondistancetoplane_h
#define _gcc_op_forcebasedondistancetoplane_h

#include "../../../scripting.h"




class GC_OP_ForceBasedOnDistanceToPlane
{
private:
    void *m_ptr;

public:
    GC_OP_ForceBasedOnDistanceToPlane() {}
    GC_OP_ForceBasedOnDistanceToPlane(void *ptr) : m_ptr(ptr) {}

    float GetMinDist() const { return GetSchemaValue<float>(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_flMinDist"); }
    void SetMinDist(float value) { SetSchemaValue(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_flMinDist", false, value); }
    Vector GetForceAtMinDist() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_vecForceAtMinDist"); }
    void SetForceAtMinDist(Vector value) { SetSchemaValue(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_vecForceAtMinDist", false, value); }
    float GetMaxDist() const { return GetSchemaValue<float>(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_flMaxDist"); }
    void SetMaxDist(float value) { SetSchemaValue(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_flMaxDist", false, value); }
    Vector GetForceAtMaxDist() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_vecForceAtMaxDist"); }
    void SetForceAtMaxDist(Vector value) { SetSchemaValue(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_vecForceAtMaxDist", false, value); }
    Vector GetPlaneNormal() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_vecPlaneNormal"); }
    void SetPlaneNormal(Vector value) { SetSchemaValue(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_vecPlaneNormal", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_nControlPointNumber", false, value); }
    float GetExponent() const { return GetSchemaValue<float>(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_flExponent"); }
    void SetExponent(float value) { SetSchemaValue(m_ptr, "C_OP_ForceBasedOnDistanceToPlane", "m_flExponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif