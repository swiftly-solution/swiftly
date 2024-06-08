class GCModelConfigElement_SetRenderColor;

#ifndef _gccmodelconfigelement_setrendercolor_h
#define _gccmodelconfigelement_setrendercolor_h

#include "../../../scripting.h"




class GCModelConfigElement_SetRenderColor
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_SetRenderColor() {}
    GCModelConfigElement_SetRenderColor(void *ptr) : m_ptr(ptr) {}

    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CModelConfigElement_SetRenderColor", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CModelConfigElement_SetRenderColor", "m_Color", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif