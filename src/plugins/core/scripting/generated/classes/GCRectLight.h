class GCRectLight;

#ifndef _gccrectlight_h
#define _gccrectlight_h

#include "../../../scripting.h"




class GCRectLight
{
private:
    void *m_ptr;

public:
    GCRectLight() {}
    GCRectLight(void *ptr) : m_ptr(ptr) {}

    bool GetShowLight() const { return GetSchemaValue<bool>(m_ptr, "CRectLight", "m_bShowLight"); }
    void SetShowLight(bool value) { SetSchemaValue(m_ptr, "CRectLight", "m_bShowLight", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif