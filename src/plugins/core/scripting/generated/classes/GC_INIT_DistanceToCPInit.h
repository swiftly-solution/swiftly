class GC_INIT_DistanceToCPInit;

#ifndef _gcc_init_distancetocpinit_h
#define _gcc_init_distancetocpinit_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"
#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"

class GC_INIT_DistanceToCPInit
{
private:
    void *m_ptr;

public:
    GC_INIT_DistanceToCPInit() {}
    GC_INIT_DistanceToCPInit(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_DistanceToCPInit", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_nFieldOutput", false, value); }
    GCPerParticleFloatInput GetInputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_DistanceToCPInit", "m_flInputMin"); }
    void SetInputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_flInputMin", false, value); }
    GCPerParticleFloatInput GetInputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_DistanceToCPInit", "m_flInputMax"); }
    void SetInputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_flInputMax", false, value); }
    GCPerParticleFloatInput GetOutputMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_DistanceToCPInit", "m_flOutputMin"); }
    void SetOutputMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_flOutputMin", false, value); }
    GCPerParticleFloatInput GetOutputMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_DistanceToCPInit", "m_flOutputMax"); }
    void SetOutputMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_flOutputMax", false, value); }
    int32_t GetStartCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_DistanceToCPInit", "m_nStartCP"); }
    void SetStartCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_nStartCP", false, value); }
    bool GetLOS() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_DistanceToCPInit", "m_bLOS"); }
    void SetLOS(bool value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_bLOS", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_DistanceToCPInit", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_INIT_DistanceToCPInit", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_nTraceSet", false, value); }
    GCPerParticleFloatInput GetMaxTraceLength() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_DistanceToCPInit", "m_flMaxTraceLength"); }
    void SetMaxTraceLength(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_flMaxTraceLength", false, value); }
    float GetLOSScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_DistanceToCPInit", "m_flLOSScale"); }
    void SetLOSScale(float value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_flLOSScale", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_DistanceToCPInit", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_DistanceToCPInit", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_bActiveRange", false, value); }
    Vector GetDistanceScale() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_DistanceToCPInit", "m_vecDistanceScale"); }
    void SetDistanceScale(Vector value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_vecDistanceScale", false, value); }
    float GetRemapBias() const { return GetSchemaValue<float>(m_ptr, "C_INIT_DistanceToCPInit", "m_flRemapBias"); }
    void SetRemapBias(float value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToCPInit", "m_flRemapBias", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif