class GIKDemoCaptureSettings_t;

#ifndef _gcikdemocapturesettings_t_h
#define _gcikdemocapturesettings_t_h

#include "../../../scripting.h"

#include "../types/GIKChannelMode.h"


class GIKDemoCaptureSettings_t
{
private:
    void *m_ptr;

public:
    GIKDemoCaptureSettings_t() {}
    GIKDemoCaptureSettings_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetParentBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "IKDemoCaptureSettings_t", "m_parentBoneName"); }
    void SetParentBoneName(CUtlString value) { SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_parentBoneName", true, value); }
    IKChannelMode GetMode() const { return GetSchemaValue<IKChannelMode>(m_ptr, "IKDemoCaptureSettings_t", "m_eMode"); }
    void SetMode(IKChannelMode value) { SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_eMode", true, value); }
    CUtlString GetIkChainName() const { return GetSchemaValue<CUtlString>(m_ptr, "IKDemoCaptureSettings_t", "m_ikChainName"); }
    void SetIkChainName(CUtlString value) { SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_ikChainName", true, value); }
    CUtlString GetOneBoneStart() const { return GetSchemaValue<CUtlString>(m_ptr, "IKDemoCaptureSettings_t", "m_oneBoneStart"); }
    void SetOneBoneStart(CUtlString value) { SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_oneBoneStart", true, value); }
    CUtlString GetOneBoneEnd() const { return GetSchemaValue<CUtlString>(m_ptr, "IKDemoCaptureSettings_t", "m_oneBoneEnd"); }
    void SetOneBoneEnd(CUtlString value) { SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_oneBoneEnd", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif