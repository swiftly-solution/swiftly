class GC_OP_RenderText;

#ifndef _gcc_op_rendertext_h
#define _gcc_op_rendertext_h

#include "../../../scripting.h"




class GC_OP_RenderText
{
private:
    void *m_ptr;

public:
    GC_OP_RenderText() {}
    GC_OP_RenderText(void *ptr) : m_ptr(ptr) {}

    Color GetOutlineColor() const { return GetSchemaValue<Color>(m_ptr, "C_OP_RenderText", "m_OutlineColor"); }
    void SetOutlineColor(Color value) { SetSchemaValue(m_ptr, "C_OP_RenderText", "m_OutlineColor", false, value); }
    CUtlString GetDefaultText() const { return GetSchemaValue<CUtlString>(m_ptr, "C_OP_RenderText", "m_DefaultText"); }
    void SetDefaultText(CUtlString value) { SetSchemaValue(m_ptr, "C_OP_RenderText", "m_DefaultText", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif