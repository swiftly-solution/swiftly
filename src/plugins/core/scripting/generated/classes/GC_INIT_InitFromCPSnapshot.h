class GC_INIT_InitFromCPSnapshot;

#ifndef _gcc_init_initfromcpsnapshot_h
#define _gcc_init_initfromcpsnapshot_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCParticleCollectionFloatInput.h"
#include "GCPerParticleFloatInput.h"

class GC_INIT_InitFromCPSnapshot
{
private:
    void *m_ptr;

public:
    GC_INIT_InitFromCPSnapshot() {}
    GC_INIT_InitFromCPSnapshot(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nControlPointNumber", false, value); }
    GParticleAttributeIndex_t GetAttributeToRead() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nAttributeToRead"); }
    void SetAttributeToRead(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nAttributeToRead", false, value); }
    GParticleAttributeIndex_t GetAttributeToWrite() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nAttributeToWrite"); }
    void SetAttributeToWrite(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nAttributeToWrite", false, value); }
    int32_t GetLocalSpaceCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nLocalSpaceCP"); }
    void SetLocalSpaceCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nLocalSpaceCP", false, value); }
    bool GetRandom() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_bRandom"); }
    void SetRandom(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_bRandom", false, value); }
    bool GetReverse() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_bReverse"); }
    void SetReverse(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_bReverse", false, value); }
    GCParticleCollectionFloatInput GetSnapShotIncrement() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nSnapShotIncrement"); }
    void SetSnapShotIncrement(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nSnapShotIncrement", false, value); }
    GCPerParticleFloatInput GetManualSnapshotIndex() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nManualSnapshotIndex"); }
    void SetManualSnapshotIndex(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nManualSnapshotIndex", false, value); }
    int32_t GetRandomSeed() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nRandomSeed"); }
    void SetRandomSeed(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_nRandomSeed", false, value); }
    bool GetLocalSpaceAngles() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitFromCPSnapshot", "m_bLocalSpaceAngles"); }
    void SetLocalSpaceAngles(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitFromCPSnapshot", "m_bLocalSpaceAngles", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif