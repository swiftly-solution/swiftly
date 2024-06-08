class GCAnimEventDefinition;

#ifndef _gccanimeventdefinition_h
#define _gccanimeventdefinition_h

#include "../../../scripting.h"




class GCAnimEventDefinition
{
private:
    void *m_ptr;

public:
    GCAnimEventDefinition() {}
    GCAnimEventDefinition(void *ptr) : m_ptr(ptr) {}

    int32_t GetFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimEventDefinition", "m_nFrame"); }
    void SetFrame(int32_t value) { SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_nFrame", false, value); }
    int32_t GetEndFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimEventDefinition", "m_nEndFrame"); }
    void SetEndFrame(int32_t value) { SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_nEndFrame", false, value); }
    float GetCycle() const { return GetSchemaValue<float>(m_ptr, "CAnimEventDefinition", "m_flCycle"); }
    void SetCycle(float value) { SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_flCycle", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CAnimEventDefinition", "m_flDuration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_flDuration", false, value); }
    CBufferString GetLegacyOptions() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimEventDefinition", "m_sLegacyOptions"); }
    void SetLegacyOptions(CBufferString value) { SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_sLegacyOptions", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif