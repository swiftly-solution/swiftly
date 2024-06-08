class GC_OP_RemapAverageHitboxSpeedtoCP;

#ifndef _gcc_op_remapaveragehitboxspeedtocp_h
#define _gcc_op_remapaveragehitboxspeedtocp_h

#include "../../../scripting.h"

#include "../types/GParticleHitboxDataSelection_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_RemapAverageHitboxSpeedtoCP
{
private:
    void *m_ptr;

public:
    GC_OP_RemapAverageHitboxSpeedtoCP() {}
    GC_OP_RemapAverageHitboxSpeedtoCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetInControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nInControlPointNumber"); }
    void SetInControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nInControlPointNumber", false, value); }
    int32_t GetOutControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nOutControlPointNumber"); }
    void SetOutControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nOutControlPointNumber", false, value); }
    int32_t GetField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nField"); }
    void SetField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nField", false, value); }
    ParticleHitboxDataSelection_t GetHitboxDataType() const { return GetSchemaValue<ParticleHitboxDataSelection_t>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nHitboxDataType"); }
    void SetHitboxDataType(ParticleHitboxDataSelection_t value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nHitboxDataType", false, value); }
    GCParticleCollectionFloatInput GetInputMin() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_flInputMin"); }
    void SetInputMin(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_flInputMin", false, value); }
    GCParticleCollectionFloatInput GetInputMax() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_flInputMax"); }
    void SetInputMax(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_flInputMax", false, value); }
    GCParticleCollectionFloatInput GetOutputMin() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_flOutputMin"); }
    void SetOutputMin(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_flOutputMin", false, value); }
    GCParticleCollectionFloatInput GetOutputMax() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_flOutputMax"); }
    void SetOutputMax(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_flOutputMax", false, value); }
    int32_t GetHeightControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nHeightControlPointNumber"); }
    void SetHeightControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_nHeightControlPointNumber", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageHitboxSpeedtoCP", "m_HitboxSetName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif