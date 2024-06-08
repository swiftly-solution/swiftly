class GC_OP_SetCPOrientationToPointAtCP;

#ifndef _gcc_op_setcporientationtopointatcp_h
#define _gcc_op_setcporientationtopointatcp_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetCPOrientationToPointAtCP
{
private:
    void *m_ptr;

public:
    GC_OP_SetCPOrientationToPointAtCP() {}
    GC_OP_SetCPOrientationToPointAtCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetInputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_nInputCP"); }
    void SetInputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_nInputCP", false, value); }
    int32_t GetOutputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_nOutputCP"); }
    void SetOutputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_nOutputCP", false, value); }
    GCParticleCollectionFloatInput GetInterpolation() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_flInterpolation"); }
    void SetInterpolation(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_flInterpolation", false, value); }
    bool Get2DOrientation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_b2DOrientation"); }
    void Set2DOrientation(bool value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_b2DOrientation", false, value); }
    bool GetAvoidSingularity() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_bAvoidSingularity"); }
    void SetAvoidSingularity(bool value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_bAvoidSingularity", false, value); }
    bool GetPointAway() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_bPointAway"); }
    void SetPointAway(bool value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToPointAtCP", "m_bPointAway", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif