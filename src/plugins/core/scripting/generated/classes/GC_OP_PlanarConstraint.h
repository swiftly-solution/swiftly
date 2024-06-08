class GC_OP_PlanarConstraint;

#ifndef _gcc_op_planarconstraint_h
#define _gcc_op_planarconstraint_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_PlanarConstraint
{
private:
    void *m_ptr;

public:
    GC_OP_PlanarConstraint() {}
    GC_OP_PlanarConstraint(void *ptr) : m_ptr(ptr) {}

    Vector GetPointOnPlane() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_PlanarConstraint", "m_PointOnPlane"); }
    void SetPointOnPlane(Vector value) { SetSchemaValue(m_ptr, "C_OP_PlanarConstraint", "m_PointOnPlane", false, value); }
    Vector GetPlaneNormal() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_PlanarConstraint", "m_PlaneNormal"); }
    void SetPlaneNormal(Vector value) { SetSchemaValue(m_ptr, "C_OP_PlanarConstraint", "m_PlaneNormal", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_PlanarConstraint", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_PlanarConstraint", "m_nControlPointNumber", false, value); }
    bool GetGlobalOrigin() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PlanarConstraint", "m_bGlobalOrigin"); }
    void SetGlobalOrigin(bool value) { SetSchemaValue(m_ptr, "C_OP_PlanarConstraint", "m_bGlobalOrigin", false, value); }
    bool GetGlobalNormal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PlanarConstraint", "m_bGlobalNormal"); }
    void SetGlobalNormal(bool value) { SetSchemaValue(m_ptr, "C_OP_PlanarConstraint", "m_bGlobalNormal", false, value); }
    GCPerParticleFloatInput GetRadiusScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_PlanarConstraint", "m_flRadiusScale"); }
    void SetRadiusScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PlanarConstraint", "m_flRadiusScale", false, value); }
    GCParticleCollectionFloatInput GetMaximumDistanceToCP() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_PlanarConstraint", "m_flMaximumDistanceToCP"); }
    void SetMaximumDistanceToCP(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PlanarConstraint", "m_flMaximumDistanceToCP", false, value); }
    bool GetUseOldCode() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PlanarConstraint", "m_bUseOldCode"); }
    void SetUseOldCode(bool value) { SetSchemaValue(m_ptr, "C_OP_PlanarConstraint", "m_bUseOldCode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif