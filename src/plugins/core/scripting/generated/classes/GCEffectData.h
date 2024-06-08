class GCEffectData;

#ifndef _gcceffectdata_h
#define _gcceffectdata_h

#include "../../../scripting.h"


#include "GCEntityInstance.h"

class GCEffectData
{
private:
    void *m_ptr;

public:
    GCEffectData() {}
    GCEffectData(void *ptr) : m_ptr(ptr) {}

    Vector GetOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CEffectData", "m_vOrigin"); }
    void SetOrigin(Vector value) { SetSchemaValue(m_ptr, "CEffectData", "m_vOrigin", false, value); }
    Vector GetStart() const { return GetSchemaValue<Vector>(m_ptr, "CEffectData", "m_vStart"); }
    void SetStart(Vector value) { SetSchemaValue(m_ptr, "CEffectData", "m_vStart", false, value); }
    Vector GetNormal() const { return GetSchemaValue<Vector>(m_ptr, "CEffectData", "m_vNormal"); }
    void SetNormal(Vector value) { SetSchemaValue(m_ptr, "CEffectData", "m_vNormal", false, value); }
    QAngle GetAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CEffectData", "m_vAngles"); }
    void SetAngles(QAngle value) { SetSchemaValue(m_ptr, "CEffectData", "m_vAngles", false, value); }
    GCEntityInstance* GetEntity() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CEffectData", "m_hEntity"); }
    void SetEntity(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n"); }
    GCEntityInstance* GetOtherEntity() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CEffectData", "m_hOtherEntity"); }
    void SetOtherEntity(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OtherEntity' is not possible.\n"); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CEffectData", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CEffectData", "m_flScale", false, value); }
    float GetMagnitude() const { return GetSchemaValue<float>(m_ptr, "CEffectData", "m_flMagnitude"); }
    void SetMagnitude(float value) { SetSchemaValue(m_ptr, "CEffectData", "m_flMagnitude", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CEffectData", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CEffectData", "m_flRadius", false, value); }
    CUtlStringToken GetSurfaceProp() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CEffectData", "m_nSurfaceProp"); }
    void SetSurfaceProp(CUtlStringToken value) { SetSchemaValue(m_ptr, "CEffectData", "m_nSurfaceProp", false, value); }
    uint32_t GetDamageType() const { return GetSchemaValue<uint32_t>(m_ptr, "CEffectData", "m_nDamageType"); }
    void SetDamageType(uint32_t value) { SetSchemaValue(m_ptr, "CEffectData", "m_nDamageType", false, value); }
    uint8_t GetPenetrate() const { return GetSchemaValue<uint8_t>(m_ptr, "CEffectData", "m_nPenetrate"); }
    void SetPenetrate(uint8_t value) { SetSchemaValue(m_ptr, "CEffectData", "m_nPenetrate", false, value); }
    uint16_t GetMaterial() const { return GetSchemaValue<uint16_t>(m_ptr, "CEffectData", "m_nMaterial"); }
    void SetMaterial(uint16_t value) { SetSchemaValue(m_ptr, "CEffectData", "m_nMaterial", false, value); }
    uint16_t GetHitBox() const { return GetSchemaValue<uint16_t>(m_ptr, "CEffectData", "m_nHitBox"); }
    void SetHitBox(uint16_t value) { SetSchemaValue(m_ptr, "CEffectData", "m_nHitBox", false, value); }
    uint8_t GetColor() const { return GetSchemaValue<uint8_t>(m_ptr, "CEffectData", "m_nColor"); }
    void SetColor(uint8_t value) { SetSchemaValue(m_ptr, "CEffectData", "m_nColor", false, value); }
    uint8_t GetFlags() const { return GetSchemaValue<uint8_t>(m_ptr, "CEffectData", "m_fFlags"); }
    void SetFlags(uint8_t value) { SetSchemaValue(m_ptr, "CEffectData", "m_fFlags", false, value); }
    CUtlStringToken GetAttachmentName() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CEffectData", "m_nAttachmentName"); }
    void SetAttachmentName(CUtlStringToken value) { SetSchemaValue(m_ptr, "CEffectData", "m_nAttachmentName", false, value); }
    uint16_t GetEffectName() const { return GetSchemaValue<uint16_t>(m_ptr, "CEffectData", "m_iEffectName"); }
    void SetEffectName(uint16_t value) { SetSchemaValue(m_ptr, "CEffectData", "m_iEffectName", false, value); }
    uint8_t GetExplosionType() const { return GetSchemaValue<uint8_t>(m_ptr, "CEffectData", "m_nExplosionType"); }
    void SetExplosionType(uint8_t value) { SetSchemaValue(m_ptr, "CEffectData", "m_nExplosionType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif