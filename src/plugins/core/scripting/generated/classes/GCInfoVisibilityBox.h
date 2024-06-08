class GCInfoVisibilityBox;

#ifndef _gccinfovisibilitybox_h
#define _gccinfovisibilitybox_h

#include "../../../scripting.h"




class GCInfoVisibilityBox
{
private:
    void *m_ptr;

public:
    GCInfoVisibilityBox() {}
    GCInfoVisibilityBox(void *ptr) : m_ptr(ptr) {}

    int32_t GetMode() const { return GetSchemaValue<int32_t>(m_ptr, "CInfoVisibilityBox", "m_nMode"); }
    void SetMode(int32_t value) { SetSchemaValue(m_ptr, "CInfoVisibilityBox", "m_nMode", false, value); }
    Vector GetBoxSize() const { return GetSchemaValue<Vector>(m_ptr, "CInfoVisibilityBox", "m_vBoxSize"); }
    void SetBoxSize(Vector value) { SetSchemaValue(m_ptr, "CInfoVisibilityBox", "m_vBoxSize", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CInfoVisibilityBox", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CInfoVisibilityBox", "m_bEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif