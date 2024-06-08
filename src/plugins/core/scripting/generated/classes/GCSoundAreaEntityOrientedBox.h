class GCSoundAreaEntityOrientedBox;

#ifndef _gccsoundareaentityorientedbox_h
#define _gccsoundareaentityorientedbox_h

#include "../../../scripting.h"




class GCSoundAreaEntityOrientedBox
{
private:
    void *m_ptr;

public:
    GCSoundAreaEntityOrientedBox() {}
    GCSoundAreaEntityOrientedBox(void *ptr) : m_ptr(ptr) {}

    Vector GetMin() const { return GetSchemaValue<Vector>(m_ptr, "CSoundAreaEntityOrientedBox", "m_vMin"); }
    void SetMin(Vector value) { SetSchemaValue(m_ptr, "CSoundAreaEntityOrientedBox", "m_vMin", false, value); }
    Vector GetMax() const { return GetSchemaValue<Vector>(m_ptr, "CSoundAreaEntityOrientedBox", "m_vMax"); }
    void SetMax(Vector value) { SetSchemaValue(m_ptr, "CSoundAreaEntityOrientedBox", "m_vMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif