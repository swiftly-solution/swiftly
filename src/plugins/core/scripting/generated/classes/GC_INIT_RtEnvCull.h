class GC_INIT_RtEnvCull;

#ifndef _gcc_init_rtenvcull_h
#define _gcc_init_rtenvcull_h

#include "../../../scripting.h"




class GC_INIT_RtEnvCull
{
private:
    void *m_ptr;

public:
    GC_INIT_RtEnvCull() {}
    GC_INIT_RtEnvCull(void *ptr) : m_ptr(ptr) {}

    Vector GetTestDir() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RtEnvCull", "m_vecTestDir"); }
    void SetTestDir(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RtEnvCull", "m_vecTestDir", false, value); }
    Vector GetTestNormal() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RtEnvCull", "m_vecTestNormal"); }
    void SetTestNormal(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RtEnvCull", "m_vecTestNormal", false, value); }
    bool GetUseVelocity() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RtEnvCull", "m_bUseVelocity"); }
    void SetUseVelocity(bool value) { SetSchemaValue(m_ptr, "C_INIT_RtEnvCull", "m_bUseVelocity", false, value); }
    bool GetCullOnMiss() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RtEnvCull", "m_bCullOnMiss"); }
    void SetCullOnMiss(bool value) { SetSchemaValue(m_ptr, "C_INIT_RtEnvCull", "m_bCullOnMiss", false, value); }
    bool GetLifeAdjust() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RtEnvCull", "m_bLifeAdjust"); }
    void SetLifeAdjust(bool value) { SetSchemaValue(m_ptr, "C_INIT_RtEnvCull", "m_bLifeAdjust", false, value); }
    std::string GetRtEnvName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_RtEnvCull", "m_RtEnvName"); }
    void SetRtEnvName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_RtEnvCull", "m_RtEnvName", false, value); }
    int32_t GetRTEnvCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RtEnvCull", "m_nRTEnvCP"); }
    void SetRTEnvCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RtEnvCull", "m_nRTEnvCP", false, value); }
    int32_t GetComponent() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RtEnvCull", "m_nComponent"); }
    void SetComponent(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RtEnvCull", "m_nComponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif