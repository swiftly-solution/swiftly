class GC_OP_DistanceBetweenCPsToCP;

#ifndef _gcc_op_distancebetweencpstocp_h
#define _gcc_op_distancebetweencpstocp_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"
#include "../types/GParticleParentSetMode_t.h"


class GC_OP_DistanceBetweenCPsToCP
{
private:
    void *m_ptr;

public:
    GC_OP_DistanceBetweenCPsToCP() {}
    GC_OP_DistanceBetweenCPsToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetStartCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nStartCP"); }
    void SetStartCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nStartCP", false, value); }
    int32_t GetEndCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nEndCP"); }
    void SetEndCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nEndCP", false, value); }
    int32_t GetOutputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nOutputCP"); }
    void SetOutputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nOutputCP", false, value); }
    int32_t GetOutputCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nOutputCPField"); }
    void SetOutputCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nOutputCPField", false, value); }
    bool GetSetOnce() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_bSetOnce"); }
    void SetSetOnce(bool value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_bSetOnce", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flOutputMax", false, value); }
    float GetMaxTraceLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flMaxTraceLength"); }
    void SetMaxTraceLength(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flMaxTraceLength", false, value); }
    float GetLOSScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flLOSScale"); }
    void SetLOSScale(float value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_flLOSScale", false, value); }
    bool GetLOS() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_bLOS"); }
    void SetLOS(bool value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_bLOS", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nTraceSet", false, value); }
    ParticleParentSetMode_t GetSetParent() const { return GetSchemaValue<ParticleParentSetMode_t>(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nSetParent"); }
    void SetSetParent(ParticleParentSetMode_t value) { SetSchemaValue(m_ptr, "C_OP_DistanceBetweenCPsToCP", "m_nSetParent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif