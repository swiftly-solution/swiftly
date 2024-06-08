class GCMessage;

#ifndef _gccmessage_h
#define _gccmessage_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCMessage
{
private:
    void *m_ptr;

public:
    GCMessage() {}
    GCMessage(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetMessage() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMessage", "m_iszMessage"); }
    void SetMessage(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CMessage", "m_iszMessage", false, value); }
    float GetMessageVolume() const { return GetSchemaValue<float>(m_ptr, "CMessage", "m_MessageVolume"); }
    void SetMessageVolume(float value) { SetSchemaValue(m_ptr, "CMessage", "m_MessageVolume", false, value); }
    int32_t GetMessageAttenuation() const { return GetSchemaValue<int32_t>(m_ptr, "CMessage", "m_MessageAttenuation"); }
    void SetMessageAttenuation(int32_t value) { SetSchemaValue(m_ptr, "CMessage", "m_MessageAttenuation", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CMessage", "m_Radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CMessage", "m_Radius", false, value); }
    CUtlSymbolLarge GetNoise() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMessage", "m_sNoise"); }
    void SetNoise(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CMessage", "m_sNoise", false, value); }
    GCEntityIOOutput GetOnShowMessage() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMessage", "m_OnShowMessage"); }
    void SetOnShowMessage(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMessage", "m_OnShowMessage", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif