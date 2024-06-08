class GFeCtrlSoftOffset_t;

#ifndef _gcfectrlsoftoffset_t_h
#define _gcfectrlsoftoffset_t_h

#include "../../../scripting.h"




class GFeCtrlSoftOffset_t
{
private:
    void *m_ptr;

public:
    GFeCtrlSoftOffset_t() {}
    GFeCtrlSoftOffset_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetCtrlParent() const { return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlSoftOffset_t", "nCtrlParent"); }
    void SetCtrlParent(uint16_t value) { SetSchemaValue(m_ptr, "FeCtrlSoftOffset_t", "nCtrlParent", true, value); }
    uint16_t GetCtrlChild() const { return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlSoftOffset_t", "nCtrlChild"); }
    void SetCtrlChild(uint16_t value) { SetSchemaValue(m_ptr, "FeCtrlSoftOffset_t", "nCtrlChild", true, value); }
    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "FeCtrlSoftOffset_t", "vOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "FeCtrlSoftOffset_t", "vOffset", true, value); }
    float GetAlpha() const { return GetSchemaValue<float>(m_ptr, "FeCtrlSoftOffset_t", "flAlpha"); }
    void SetAlpha(float value) { SetSchemaValue(m_ptr, "FeCtrlSoftOffset_t", "flAlpha", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif