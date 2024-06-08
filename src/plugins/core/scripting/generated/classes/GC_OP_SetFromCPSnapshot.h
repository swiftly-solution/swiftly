class GC_OP_SetFromCPSnapshot;

#ifndef _gcc_op_setfromcpsnapshot_h
#define _gcc_op_setfromcpsnapshot_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCParticleCollectionFloatInput.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_SetFromCPSnapshot
{
private:
    void *m_ptr;

public:
    GC_OP_SetFromCPSnapshot() {}
    GC_OP_SetFromCPSnapshot(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetFromCPSnapshot", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_nControlPointNumber", false, value); }
    GParticleAttributeIndex_t GetAttributeToRead() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetFromCPSnapshot", "m_nAttributeToRead"); }
    void SetAttributeToRead(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_nAttributeToRead", false, value); }
    GParticleAttributeIndex_t GetAttributeToWrite() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetFromCPSnapshot", "m_nAttributeToWrite"); }
    void SetAttributeToWrite(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_nAttributeToWrite", false, value); }
    int32_t GetLocalSpaceCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetFromCPSnapshot", "m_nLocalSpaceCP"); }
    void SetLocalSpaceCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_nLocalSpaceCP", false, value); }
    bool GetRandom() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetFromCPSnapshot", "m_bRandom"); }
    void SetRandom(bool value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_bRandom", false, value); }
    bool GetReverse() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetFromCPSnapshot", "m_bReverse"); }
    void SetReverse(bool value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_bReverse", false, value); }
    int32_t GetRandomSeed() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetFromCPSnapshot", "m_nRandomSeed"); }
    void SetRandomSeed(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_nRandomSeed", false, value); }
    GCParticleCollectionFloatInput GetSnapShotStartPoint() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetFromCPSnapshot", "m_nSnapShotStartPoint"); }
    void SetSnapShotStartPoint(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_nSnapShotStartPoint", false, value); }
    GCParticleCollectionFloatInput GetSnapShotIncrement() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetFromCPSnapshot", "m_nSnapShotIncrement"); }
    void SetSnapShotIncrement(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_nSnapShotIncrement", false, value); }
    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SetFromCPSnapshot", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_flInterpolation", false, value); }
    bool GetSubSample() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetFromCPSnapshot", "m_bSubSample"); }
    void SetSubSample(bool value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_bSubSample", false, value); }
    bool GetPrev() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetFromCPSnapshot", "m_bPrev"); }
    void SetPrev(bool value) { SetSchemaValue(m_ptr, "C_OP_SetFromCPSnapshot", "m_bPrev", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif