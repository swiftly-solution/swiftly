class GCConcreteAnimParameter;

#ifndef _gccconcreteanimparameter_h
#define _gccconcreteanimparameter_h

#include "../../../scripting.h"

#include "../types/GAnimParamButton_t.h"
#include "../types/GAnimParamNetworkSetting.h"


class GCConcreteAnimParameter
{
private:
    void *m_ptr;

public:
    GCConcreteAnimParameter() {}
    GCConcreteAnimParameter(void *ptr) : m_ptr(ptr) {}

    AnimParamButton_t GetPreviewButton() const { return GetSchemaValue<AnimParamButton_t>(m_ptr, "CConcreteAnimParameter", "m_previewButton"); }
    void SetPreviewButton(AnimParamButton_t value) { SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_previewButton", false, value); }
    AnimParamNetworkSetting GetNetworkSetting() const { return GetSchemaValue<AnimParamNetworkSetting>(m_ptr, "CConcreteAnimParameter", "m_eNetworkSetting"); }
    void SetNetworkSetting(AnimParamNetworkSetting value) { SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_eNetworkSetting", false, value); }
    bool GetUseMostRecentValue() const { return GetSchemaValue<bool>(m_ptr, "CConcreteAnimParameter", "m_bUseMostRecentValue"); }
    void SetUseMostRecentValue(bool value) { SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_bUseMostRecentValue", false, value); }
    bool GetAutoReset() const { return GetSchemaValue<bool>(m_ptr, "CConcreteAnimParameter", "m_bAutoReset"); }
    void SetAutoReset(bool value) { SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_bAutoReset", false, value); }
    bool GetGameWritable() const { return GetSchemaValue<bool>(m_ptr, "CConcreteAnimParameter", "m_bGameWritable"); }
    void SetGameWritable(bool value) { SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_bGameWritable", false, value); }
    bool GetGraphWritable() const { return GetSchemaValue<bool>(m_ptr, "CConcreteAnimParameter", "m_bGraphWritable"); }
    void SetGraphWritable(bool value) { SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_bGraphWritable", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif