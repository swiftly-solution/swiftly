class GCFlashlightEffect;

#ifndef _gccflashlighteffect_h
#define _gccflashlighteffect_h

#include "../../../scripting.h"




class GCFlashlightEffect
{
private:
    void *m_ptr;

public:
    GCFlashlightEffect() {}
    GCFlashlightEffect(void *ptr) : m_ptr(ptr) {}

    bool GetIsOn() const { return GetSchemaValue<bool>(m_ptr, "CFlashlightEffect", "m_bIsOn"); }
    void SetIsOn(bool value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_bIsOn", false, value); }
    bool GetMuzzleFlashEnabled() const { return GetSchemaValue<bool>(m_ptr, "CFlashlightEffect", "m_bMuzzleFlashEnabled"); }
    void SetMuzzleFlashEnabled(bool value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_bMuzzleFlashEnabled", false, value); }
    float GetMuzzleFlashBrightness() const { return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flMuzzleFlashBrightness"); }
    void SetMuzzleFlashBrightness(float value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flMuzzleFlashBrightness", false, value); }
    Quaternion GetQuatMuzzleFlashOrientation() const { return GetSchemaValue<Quaternion>(m_ptr, "CFlashlightEffect", "m_quatMuzzleFlashOrientation"); }
    void SetQuatMuzzleFlashOrientation(Quaternion value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_quatMuzzleFlashOrientation", false, value); }
    Vector GetMuzzleFlashOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CFlashlightEffect", "m_vecMuzzleFlashOrigin"); }
    void SetMuzzleFlashOrigin(Vector value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_vecMuzzleFlashOrigin", false, value); }
    float GetFov() const { return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flFov"); }
    void SetFov(float value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flFov", false, value); }
    float GetFarZ() const { return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flFarZ"); }
    void SetFarZ(float value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flFarZ", false, value); }
    float GetLinearAtten() const { return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flLinearAtten"); }
    void SetLinearAtten(float value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flLinearAtten", false, value); }
    bool GetCastsShadows() const { return GetSchemaValue<bool>(m_ptr, "CFlashlightEffect", "m_bCastsShadows"); }
    void SetCastsShadows(bool value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_bCastsShadows", false, value); }
    float GetCurrentPullBackDist() const { return GetSchemaValue<float>(m_ptr, "CFlashlightEffect", "m_flCurrentPullBackDist"); }
    void SetCurrentPullBackDist(float value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_flCurrentPullBackDist", false, value); }
    std::string GetTextureName() const { return GetSchemaValue<char*>(m_ptr, "CFlashlightEffect", "m_textureName"); }
    void SetTextureName(std::string value) { SetSchemaValue(m_ptr, "CFlashlightEffect", "m_textureName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif