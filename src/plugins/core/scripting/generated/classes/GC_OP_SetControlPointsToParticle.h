class GC_OP_SetControlPointsToParticle;

#ifndef _gcc_op_setcontrolpointstoparticle_h
#define _gcc_op_setcontrolpointstoparticle_h

#include "../../../scripting.h"

#include "../types/GParticleOrientationSetMode_t.h"
#include "../types/GParticleParentSetMode_t.h"


class GC_OP_SetControlPointsToParticle
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointsToParticle() {}
    GC_OP_SetControlPointsToParticle(void *ptr) : m_ptr(ptr) {}

    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointsToParticle", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToParticle", "m_nChildGroupID", false, value); }
    int32_t GetFirstControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointsToParticle", "m_nFirstControlPoint"); }
    void SetFirstControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToParticle", "m_nFirstControlPoint", false, value); }
    int32_t GetNumControlPoints() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointsToParticle", "m_nNumControlPoints"); }
    void SetNumControlPoints(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToParticle", "m_nNumControlPoints", false, value); }
    int32_t GetFirstSourcePoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointsToParticle", "m_nFirstSourcePoint"); }
    void SetFirstSourcePoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToParticle", "m_nFirstSourcePoint", false, value); }
    bool GetSetOrientation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointsToParticle", "m_bSetOrientation"); }
    void SetSetOrientation(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToParticle", "m_bSetOrientation", false, value); }
    ParticleOrientationSetMode_t GetOrientationMode() const { return GetSchemaValue<ParticleOrientationSetMode_t>(m_ptr, "C_OP_SetControlPointsToParticle", "m_nOrientationMode"); }
    void SetOrientationMode(ParticleOrientationSetMode_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToParticle", "m_nOrientationMode", false, value); }
    ParticleParentSetMode_t GetSetParent() const { return GetSchemaValue<ParticleParentSetMode_t>(m_ptr, "C_OP_SetControlPointsToParticle", "m_nSetParent"); }
    void SetSetParent(ParticleParentSetMode_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToParticle", "m_nSetParent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif