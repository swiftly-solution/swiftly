class GCSprite;

#ifndef _gccsprite_h
#define _gccsprite_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCSprite
{
private:
    void *m_ptr;

public:
    GCSprite() {}
    GCSprite(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetAttachedToEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSprite", "m_hAttachedToEntity"); }
    void SetAttachedToEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'AttachedToEntity' is not possible.\n"); }
    float GetSpriteFramerate() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flSpriteFramerate"); }
    void SetSpriteFramerate(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flSpriteFramerate", false, value); }
    float GetFrame() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flFrame"); }
    void SetFrame(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flFrame", false, value); }
    uint32_t GetBrightness() const { return GetSchemaValue<uint32_t>(m_ptr, "CSprite", "m_nBrightness"); }
    void SetBrightness(uint32_t value) { SetSchemaValue(m_ptr, "CSprite", "m_nBrightness", false, value); }
    float GetBrightnessDuration() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flBrightnessDuration"); }
    void SetBrightnessDuration(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flBrightnessDuration", false, value); }
    float GetSpriteScale() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flSpriteScale"); }
    void SetSpriteScale(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flSpriteScale", false, value); }
    float GetScaleDuration() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flScaleDuration"); }
    void SetScaleDuration(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flScaleDuration", false, value); }
    bool GetWorldSpaceScale() const { return GetSchemaValue<bool>(m_ptr, "CSprite", "m_bWorldSpaceScale"); }
    void SetWorldSpaceScale(bool value) { SetSchemaValue(m_ptr, "CSprite", "m_bWorldSpaceScale", false, value); }
    float GetGlowProxySize() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flGlowProxySize"); }
    void SetGlowProxySize(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flGlowProxySize", false, value); }
    float GetHDRColorScale() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flHDRColorScale"); }
    void SetHDRColorScale(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flHDRColorScale", false, value); }
    float GetMaxFrame() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flMaxFrame"); }
    void SetMaxFrame(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flMaxFrame", false, value); }
    float GetStartScale() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flStartScale"); }
    void SetStartScale(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flStartScale", false, value); }
    float GetDestScale() const { return GetSchemaValue<float>(m_ptr, "CSprite", "m_flDestScale"); }
    void SetDestScale(float value) { SetSchemaValue(m_ptr, "CSprite", "m_flDestScale", false, value); }
    int32_t GetStartBrightness() const { return GetSchemaValue<int32_t>(m_ptr, "CSprite", "m_nStartBrightness"); }
    void SetStartBrightness(int32_t value) { SetSchemaValue(m_ptr, "CSprite", "m_nStartBrightness", false, value); }
    int32_t GetDestBrightness() const { return GetSchemaValue<int32_t>(m_ptr, "CSprite", "m_nDestBrightness"); }
    void SetDestBrightness(int32_t value) { SetSchemaValue(m_ptr, "CSprite", "m_nDestBrightness", false, value); }
    int32_t GetSpriteWidth() const { return GetSchemaValue<int32_t>(m_ptr, "CSprite", "m_nSpriteWidth"); }
    void SetSpriteWidth(int32_t value) { SetSchemaValue(m_ptr, "CSprite", "m_nSpriteWidth", false, value); }
    int32_t GetSpriteHeight() const { return GetSchemaValue<int32_t>(m_ptr, "CSprite", "m_nSpriteHeight"); }
    void SetSpriteHeight(int32_t value) { SetSchemaValue(m_ptr, "CSprite", "m_nSpriteHeight", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif