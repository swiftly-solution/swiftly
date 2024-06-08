class GRenderInputLayoutField_t;

#ifndef _gcrenderinputlayoutfield_t_h
#define _gcrenderinputlayoutfield_t_h

#include "../../../scripting.h"

#include "../types/GRenderSlotType_t.h"


class GRenderInputLayoutField_t
{
private:
    void *m_ptr;

public:
    GRenderInputLayoutField_t() {}
    GRenderInputLayoutField_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint8_t> GetSemanticName() const { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "RenderInputLayoutField_t", "m_pSemanticName"); std::vector<uint8_t> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetSemanticName(std::vector<uint8_t> value) { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "RenderInputLayoutField_t", "m_pSemanticName"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_pSemanticName", true, outValue); }
    int32_t GetSemanticIndex() const { return GetSchemaValue<int32_t>(m_ptr, "RenderInputLayoutField_t", "m_nSemanticIndex"); }
    void SetSemanticIndex(int32_t value) { SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nSemanticIndex", true, value); }
    uint32_t GetFormat() const { return GetSchemaValue<uint32_t>(m_ptr, "RenderInputLayoutField_t", "m_Format"); }
    void SetFormat(uint32_t value) { SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_Format", true, value); }
    int32_t GetOffset() const { return GetSchemaValue<int32_t>(m_ptr, "RenderInputLayoutField_t", "m_nOffset"); }
    void SetOffset(int32_t value) { SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nOffset", true, value); }
    int32_t GetSlot() const { return GetSchemaValue<int32_t>(m_ptr, "RenderInputLayoutField_t", "m_nSlot"); }
    void SetSlot(int32_t value) { SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nSlot", true, value); }
    RenderSlotType_t GetSlotType() const { return GetSchemaValue<RenderSlotType_t>(m_ptr, "RenderInputLayoutField_t", "m_nSlotType"); }
    void SetSlotType(RenderSlotType_t value) { SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nSlotType", true, value); }
    int32_t GetInstanceStepRate() const { return GetSchemaValue<int32_t>(m_ptr, "RenderInputLayoutField_t", "m_nInstanceStepRate"); }
    void SetInstanceStepRate(int32_t value) { SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nInstanceStepRate", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif