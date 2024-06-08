class GCTriggerBrush;

#ifndef _gcctriggerbrush_h
#define _gcctriggerbrush_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCTriggerBrush
{
private:
    void *m_ptr;

public:
    GCTriggerBrush() {}
    GCTriggerBrush(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnStartTouch() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerBrush", "m_OnStartTouch"); }
    void SetOnStartTouch(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerBrush", "m_OnStartTouch", false, value); }
    GCEntityIOOutput GetOnEndTouch() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerBrush", "m_OnEndTouch"); }
    void SetOnEndTouch(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerBrush", "m_OnEndTouch", false, value); }
    GCEntityIOOutput GetOnUse() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerBrush", "m_OnUse"); }
    void SetOnUse(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerBrush", "m_OnUse", false, value); }
    int32_t GetInputFilter() const { return GetSchemaValue<int32_t>(m_ptr, "CTriggerBrush", "m_iInputFilter"); }
    void SetInputFilter(int32_t value) { SetSchemaValue(m_ptr, "CTriggerBrush", "m_iInputFilter", false, value); }
    int32_t GetDontMessageParent() const { return GetSchemaValue<int32_t>(m_ptr, "CTriggerBrush", "m_iDontMessageParent"); }
    void SetDontMessageParent(int32_t value) { SetSchemaValue(m_ptr, "CTriggerBrush", "m_iDontMessageParent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif