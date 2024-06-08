class GCPointPush;

#ifndef _gccpointpush_h
#define _gccpointpush_h

#include "../../../scripting.h"


#include "GCBaseFilter.h"

class GCPointPush
{
private:
    void *m_ptr;

public:
    GCPointPush() {}
    GCPointPush(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CPointPush", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CPointPush", "m_bEnabled", false, value); }
    float GetMagnitude() const { return GetSchemaValue<float>(m_ptr, "CPointPush", "m_flMagnitude"); }
    void SetMagnitude(float value) { SetSchemaValue(m_ptr, "CPointPush", "m_flMagnitude", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CPointPush", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CPointPush", "m_flRadius", false, value); }
    float GetInnerRadius() const { return GetSchemaValue<float>(m_ptr, "CPointPush", "m_flInnerRadius"); }
    void SetInnerRadius(float value) { SetSchemaValue(m_ptr, "CPointPush", "m_flInnerRadius", false, value); }
    float GetConeOfInfluence() const { return GetSchemaValue<float>(m_ptr, "CPointPush", "m_flConeOfInfluence"); }
    void SetConeOfInfluence(float value) { SetSchemaValue(m_ptr, "CPointPush", "m_flConeOfInfluence", false, value); }
    CUtlSymbolLarge GetFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointPush", "m_iszFilterName"); }
    void SetFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointPush", "m_iszFilterName", false, value); }
    GCBaseFilter* GetFilter() const { return GetSchemaValue<GCBaseFilter*>(m_ptr, "CPointPush", "m_hFilter"); }
    void SetFilter(GCBaseFilter* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif