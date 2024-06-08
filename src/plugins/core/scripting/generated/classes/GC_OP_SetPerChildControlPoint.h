class GC_OP_SetPerChildControlPoint;

#ifndef _gcc_op_setperchildcontrolpoint_h
#define _gcc_op_setperchildcontrolpoint_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_SetPerChildControlPoint
{
private:
    void *m_ptr;

public:
    GC_OP_SetPerChildControlPoint() {}
    GC_OP_SetPerChildControlPoint(void *ptr) : m_ptr(ptr) {}

    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetPerChildControlPoint", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPoint", "m_nChildGroupID", false, value); }
    int32_t GetFirstControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetPerChildControlPoint", "m_nFirstControlPoint"); }
    void SetFirstControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPoint", "m_nFirstControlPoint", false, value); }
    int32_t GetNumControlPoints() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetPerChildControlPoint", "m_nNumControlPoints"); }
    void SetNumControlPoints(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPoint", "m_nNumControlPoints", false, value); }
    GCParticleCollectionFloatInput GetParticleIncrement() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetPerChildControlPoint", "m_nParticleIncrement"); }
    void SetParticleIncrement(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPoint", "m_nParticleIncrement", false, value); }
    GCParticleCollectionFloatInput GetFirstSourcePoint() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetPerChildControlPoint", "m_nFirstSourcePoint"); }
    void SetFirstSourcePoint(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPoint", "m_nFirstSourcePoint", false, value); }
    bool GetSetOrientation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetPerChildControlPoint", "m_bSetOrientation"); }
    void SetSetOrientation(bool value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPoint", "m_bSetOrientation", false, value); }
    GParticleAttributeIndex_t GetOrientationField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetPerChildControlPoint", "m_nOrientationField"); }
    void SetOrientationField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPoint", "m_nOrientationField", false, value); }
    bool GetNumBasedOnParticleCount() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetPerChildControlPoint", "m_bNumBasedOnParticleCount"); }
    void SetNumBasedOnParticleCount(bool value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPoint", "m_bNumBasedOnParticleCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif