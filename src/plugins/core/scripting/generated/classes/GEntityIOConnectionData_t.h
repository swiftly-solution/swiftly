class GEntityIOConnectionData_t;

#ifndef _gcentityioconnectiondata_t_h
#define _gcentityioconnectiondata_t_h

#include "../../../scripting.h"




class GEntityIOConnectionData_t
{
private:
    void *m_ptr;

public:
    GEntityIOConnectionData_t() {}
    GEntityIOConnectionData_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetOutputName() const { return GetSchemaValue<CUtlString>(m_ptr, "EntityIOConnectionData_t", "m_outputName"); }
    void SetOutputName(CUtlString value) { SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_outputName", true, value); }
    uint32_t GetTargetType() const { return GetSchemaValue<uint32_t>(m_ptr, "EntityIOConnectionData_t", "m_targetType"); }
    void SetTargetType(uint32_t value) { SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_targetType", true, value); }
    CUtlString GetTargetName() const { return GetSchemaValue<CUtlString>(m_ptr, "EntityIOConnectionData_t", "m_targetName"); }
    void SetTargetName(CUtlString value) { SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_targetName", true, value); }
    CUtlString GetInputName() const { return GetSchemaValue<CUtlString>(m_ptr, "EntityIOConnectionData_t", "m_inputName"); }
    void SetInputName(CUtlString value) { SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_inputName", true, value); }
    CUtlString GetOverrideParam() const { return GetSchemaValue<CUtlString>(m_ptr, "EntityIOConnectionData_t", "m_overrideParam"); }
    void SetOverrideParam(CUtlString value) { SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_overrideParam", true, value); }
    float GetDelay() const { return GetSchemaValue<float>(m_ptr, "EntityIOConnectionData_t", "m_flDelay"); }
    void SetDelay(float value) { SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_flDelay", true, value); }
    int32_t GetTimesToFire() const { return GetSchemaValue<int32_t>(m_ptr, "EntityIOConnectionData_t", "m_nTimesToFire"); }
    void SetTimesToFire(int32_t value) { SetSchemaValue(m_ptr, "EntityIOConnectionData_t", "m_nTimesToFire", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif