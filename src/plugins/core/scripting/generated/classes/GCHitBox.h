class GCHitBox;

#ifndef _gcchitbox_h
#define _gcchitbox_h

#include "../../../scripting.h"




class GCHitBox
{
private:
    void *m_ptr;

public:
    GCHitBox() {}
    GCHitBox(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CHitBox", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CHitBox", "m_name", false, value); }
    CUtlString GetSurfaceProperty() const { return GetSchemaValue<CUtlString>(m_ptr, "CHitBox", "m_sSurfaceProperty"); }
    void SetSurfaceProperty(CUtlString value) { SetSchemaValue(m_ptr, "CHitBox", "m_sSurfaceProperty", false, value); }
    CUtlString GetBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "CHitBox", "m_sBoneName"); }
    void SetBoneName(CUtlString value) { SetSchemaValue(m_ptr, "CHitBox", "m_sBoneName", false, value); }
    Vector GetMinBounds() const { return GetSchemaValue<Vector>(m_ptr, "CHitBox", "m_vMinBounds"); }
    void SetMinBounds(Vector value) { SetSchemaValue(m_ptr, "CHitBox", "m_vMinBounds", false, value); }
    Vector GetMaxBounds() const { return GetSchemaValue<Vector>(m_ptr, "CHitBox", "m_vMaxBounds"); }
    void SetMaxBounds(Vector value) { SetSchemaValue(m_ptr, "CHitBox", "m_vMaxBounds", false, value); }
    float GetShapeRadius() const { return GetSchemaValue<float>(m_ptr, "CHitBox", "m_flShapeRadius"); }
    void SetShapeRadius(float value) { SetSchemaValue(m_ptr, "CHitBox", "m_flShapeRadius", false, value); }
    uint32_t GetBoneNameHash() const { return GetSchemaValue<uint32_t>(m_ptr, "CHitBox", "m_nBoneNameHash"); }
    void SetBoneNameHash(uint32_t value) { SetSchemaValue(m_ptr, "CHitBox", "m_nBoneNameHash", false, value); }
    int32_t GetGroupId() const { return GetSchemaValue<int32_t>(m_ptr, "CHitBox", "m_nGroupId"); }
    void SetGroupId(int32_t value) { SetSchemaValue(m_ptr, "CHitBox", "m_nGroupId", false, value); }
    uint8_t GetShapeType() const { return GetSchemaValue<uint8_t>(m_ptr, "CHitBox", "m_nShapeType"); }
    void SetShapeType(uint8_t value) { SetSchemaValue(m_ptr, "CHitBox", "m_nShapeType", false, value); }
    bool GetTranslationOnly() const { return GetSchemaValue<bool>(m_ptr, "CHitBox", "m_bTranslationOnly"); }
    void SetTranslationOnly(bool value) { SetSchemaValue(m_ptr, "CHitBox", "m_bTranslationOnly", false, value); }
    uint32_t GetCRC() const { return GetSchemaValue<uint32_t>(m_ptr, "CHitBox", "m_CRC"); }
    void SetCRC(uint32_t value) { SetSchemaValue(m_ptr, "CHitBox", "m_CRC", false, value); }
    Color GetCRenderColor() const { return GetSchemaValue<Color>(m_ptr, "CHitBox", "m_cRenderColor"); }
    void SetCRenderColor(Color value) { SetSchemaValue(m_ptr, "CHitBox", "m_cRenderColor", false, value); }
    uint16_t GetHitBoxIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CHitBox", "m_nHitBoxIndex"); }
    void SetHitBoxIndex(uint16_t value) { SetSchemaValue(m_ptr, "CHitBox", "m_nHitBoxIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif