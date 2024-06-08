class GC_OP_HSVShiftToCP;

#ifndef _gcc_op_hsvshifttocp_h
#define _gcc_op_hsvshifttocp_h

#include "../../../scripting.h"




class GC_OP_HSVShiftToCP
{
private:
    void *m_ptr;

public:
    GC_OP_HSVShiftToCP() {}
    GC_OP_HSVShiftToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetColorCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_HSVShiftToCP", "m_nColorCP"); }
    void SetColorCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_HSVShiftToCP", "m_nColorCP", false, value); }
    int32_t GetColorGemEnableCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_HSVShiftToCP", "m_nColorGemEnableCP"); }
    void SetColorGemEnableCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_HSVShiftToCP", "m_nColorGemEnableCP", false, value); }
    int32_t GetOutputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_HSVShiftToCP", "m_nOutputCP"); }
    void SetOutputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_HSVShiftToCP", "m_nOutputCP", false, value); }
    Color GetDefaultHSVColor() const { return GetSchemaValue<Color>(m_ptr, "C_OP_HSVShiftToCP", "m_DefaultHSVColor"); }
    void SetDefaultHSVColor(Color value) { SetSchemaValue(m_ptr, "C_OP_HSVShiftToCP", "m_DefaultHSVColor", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif