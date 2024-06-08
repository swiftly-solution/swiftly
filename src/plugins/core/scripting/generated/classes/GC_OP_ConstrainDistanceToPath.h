class GC_OP_ConstrainDistanceToPath;

#ifndef _gcc_op_constraindistancetopath_h
#define _gcc_op_constraindistancetopath_h

#include "../../../scripting.h"


#include "GCPathParameters.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_ConstrainDistanceToPath
{
private:
    void *m_ptr;

public:
    GC_OP_ConstrainDistanceToPath() {}
    GC_OP_ConstrainDistanceToPath(void *ptr) : m_ptr(ptr) {}

    float GetMinDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainDistanceToPath", "m_fMinDistance"); }
    void SetMinDistance(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToPath", "m_fMinDistance", false, value); }
    float GetMaxDistance0() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainDistanceToPath", "m_flMaxDistance0"); }
    void SetMaxDistance0(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToPath", "m_flMaxDistance0", false, value); }
    float GetMaxDistanceMid() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainDistanceToPath", "m_flMaxDistanceMid"); }
    void SetMaxDistanceMid(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToPath", "m_flMaxDistanceMid", false, value); }
    float GetMaxDistance1() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainDistanceToPath", "m_flMaxDistance1"); }
    void SetMaxDistance1(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToPath", "m_flMaxDistance1", false, value); }
    GCPathParameters GetPathParameters() const { return GetSchemaValue<GCPathParameters>(m_ptr, "C_OP_ConstrainDistanceToPath", "m_PathParameters"); }
    void SetPathParameters(GCPathParameters value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToPath", "m_PathParameters", false, value); }
    float GetTravelTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_ConstrainDistanceToPath", "m_flTravelTime"); }
    void SetTravelTime(float value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToPath", "m_flTravelTime", false, value); }
    GParticleAttributeIndex_t GetFieldScale() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ConstrainDistanceToPath", "m_nFieldScale"); }
    void SetFieldScale(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToPath", "m_nFieldScale", false, value); }
    GParticleAttributeIndex_t GetManualTField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ConstrainDistanceToPath", "m_nManualTField"); }
    void SetManualTField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistanceToPath", "m_nManualTField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif