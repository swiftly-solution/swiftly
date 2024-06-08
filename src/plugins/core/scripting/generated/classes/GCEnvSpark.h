class GCEnvSpark;

#ifndef _gccenvspark_h
#define _gccenvspark_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCEnvSpark
{
private:
    void *m_ptr;

public:
    GCEnvSpark() {}
    GCEnvSpark(void *ptr) : m_ptr(ptr) {}

    float GetDelay() const { return GetSchemaValue<float>(m_ptr, "CEnvSpark", "m_flDelay"); }
    void SetDelay(float value) { SetSchemaValue(m_ptr, "CEnvSpark", "m_flDelay", false, value); }
    int32_t GetMagnitude() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvSpark", "m_nMagnitude"); }
    void SetMagnitude(int32_t value) { SetSchemaValue(m_ptr, "CEnvSpark", "m_nMagnitude", false, value); }
    int32_t GetTrailLength() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvSpark", "m_nTrailLength"); }
    void SetTrailLength(int32_t value) { SetSchemaValue(m_ptr, "CEnvSpark", "m_nTrailLength", false, value); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvSpark", "m_nType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "CEnvSpark", "m_nType", false, value); }
    GCEntityIOOutput GetOnSpark() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvSpark", "m_OnSpark"); }
    void SetOnSpark(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvSpark", "m_OnSpark", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif