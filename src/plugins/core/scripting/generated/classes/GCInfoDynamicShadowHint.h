class GCInfoDynamicShadowHint;

#ifndef _gccinfodynamicshadowhint_h
#define _gccinfodynamicshadowhint_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCInfoDynamicShadowHint
{
private:
    void *m_ptr;

public:
    GCInfoDynamicShadowHint() {}
    GCInfoDynamicShadowHint(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CInfoDynamicShadowHint", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CInfoDynamicShadowHint", "m_bDisabled", false, value); }
    float GetRange() const { return GetSchemaValue<float>(m_ptr, "CInfoDynamicShadowHint", "m_flRange"); }
    void SetRange(float value) { SetSchemaValue(m_ptr, "CInfoDynamicShadowHint", "m_flRange", false, value); }
    int32_t GetImportance() const { return GetSchemaValue<int32_t>(m_ptr, "CInfoDynamicShadowHint", "m_nImportance"); }
    void SetImportance(int32_t value) { SetSchemaValue(m_ptr, "CInfoDynamicShadowHint", "m_nImportance", false, value); }
    int32_t GetLightChoice() const { return GetSchemaValue<int32_t>(m_ptr, "CInfoDynamicShadowHint", "m_nLightChoice"); }
    void SetLightChoice(int32_t value) { SetSchemaValue(m_ptr, "CInfoDynamicShadowHint", "m_nLightChoice", false, value); }
    GCBaseEntity* GetLight() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CInfoDynamicShadowHint", "m_hLight"); }
    void SetLight(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Light' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif