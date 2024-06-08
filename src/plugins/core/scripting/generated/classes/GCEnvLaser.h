class GCEnvLaser;

#ifndef _gccenvlaser_h
#define _gccenvlaser_h

#include "../../../scripting.h"


#include "GCSprite.h"

class GCEnvLaser
{
private:
    void *m_ptr;

public:
    GCEnvLaser() {}
    GCEnvLaser(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetLaserTarget() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvLaser", "m_iszLaserTarget"); }
    void SetLaserTarget(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvLaser", "m_iszLaserTarget", false, value); }
    GCSprite* GetSprite() const { return GetSchemaValue<GCSprite*>(m_ptr, "CEnvLaser", "m_pSprite"); }
    void SetSprite(GCSprite* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Sprite' is not possible.\n"); }
    CUtlSymbolLarge GetSpriteName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvLaser", "m_iszSpriteName"); }
    void SetSpriteName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvLaser", "m_iszSpriteName", false, value); }
    Vector GetFirePosition() const { return GetSchemaValue<Vector>(m_ptr, "CEnvLaser", "m_firePosition"); }
    void SetFirePosition(Vector value) { SetSchemaValue(m_ptr, "CEnvLaser", "m_firePosition", false, value); }
    float GetStartFrame() const { return GetSchemaValue<float>(m_ptr, "CEnvLaser", "m_flStartFrame"); }
    void SetStartFrame(float value) { SetSchemaValue(m_ptr, "CEnvLaser", "m_flStartFrame", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif