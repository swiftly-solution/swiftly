class GCGlowOverlay;

#ifndef _gccglowoverlay_h
#define _gccglowoverlay_h

#include "../../../scripting.h"


#include "GCGlowSprite.h"

class GCGlowOverlay
{
private:
    void *m_ptr;

public:
    GCGlowOverlay() {}
    GCGlowOverlay(void *ptr) : m_ptr(ptr) {}

    Vector GetPos() const { return GetSchemaValue<Vector>(m_ptr, "CGlowOverlay", "m_vPos"); }
    void SetPos(Vector value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_vPos", false, value); }
    bool GetDirectional() const { return GetSchemaValue<bool>(m_ptr, "CGlowOverlay", "m_bDirectional"); }
    void SetDirectional(bool value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_bDirectional", false, value); }
    Vector GetDirection() const { return GetSchemaValue<Vector>(m_ptr, "CGlowOverlay", "m_vDirection"); }
    void SetDirection(Vector value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_vDirection", false, value); }
    bool GetInSky() const { return GetSchemaValue<bool>(m_ptr, "CGlowOverlay", "m_bInSky"); }
    void SetInSky(bool value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_bInSky", false, value); }
    float GetSkyObstructionScale() const { return GetSchemaValue<float>(m_ptr, "CGlowOverlay", "m_skyObstructionScale"); }
    void SetSkyObstructionScale(float value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_skyObstructionScale", false, value); }
    std::vector<GCGlowSprite> GetSprites() const { GCGlowSprite* outValue = GetSchemaValue<GCGlowSprite*>(m_ptr, "CGlowOverlay", "m_Sprites"); std::vector<GCGlowSprite> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetSprites(std::vector<GCGlowSprite> value) { GCGlowSprite* outValue = GetSchemaValue<GCGlowSprite*>(m_ptr, "CGlowOverlay", "m_Sprites"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CGlowOverlay", "m_Sprites", false, outValue); }
    int32_t GetSprites1() const { return GetSchemaValue<int32_t>(m_ptr, "CGlowOverlay", "m_nSprites"); }
    void SetSprites1(int32_t value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_nSprites", false, value); }
    float GetProxyRadius() const { return GetSchemaValue<float>(m_ptr, "CGlowOverlay", "m_flProxyRadius"); }
    void SetProxyRadius(float value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_flProxyRadius", false, value); }
    float GetHDRColorScale() const { return GetSchemaValue<float>(m_ptr, "CGlowOverlay", "m_flHDRColorScale"); }
    void SetHDRColorScale(float value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_flHDRColorScale", false, value); }
    float GetGlowObstructionScale() const { return GetSchemaValue<float>(m_ptr, "CGlowOverlay", "m_flGlowObstructionScale"); }
    void SetGlowObstructionScale(float value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_flGlowObstructionScale", false, value); }
    bool GetCacheGlowObstruction() const { return GetSchemaValue<bool>(m_ptr, "CGlowOverlay", "m_bCacheGlowObstruction"); }
    void SetCacheGlowObstruction(bool value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_bCacheGlowObstruction", false, value); }
    bool GetCacheSkyObstruction() const { return GetSchemaValue<bool>(m_ptr, "CGlowOverlay", "m_bCacheSkyObstruction"); }
    void SetCacheSkyObstruction(bool value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_bCacheSkyObstruction", false, value); }
    int16_t GetActivated() const { return GetSchemaValue<int16_t>(m_ptr, "CGlowOverlay", "m_bActivated"); }
    void SetActivated(int16_t value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_bActivated", false, value); }
    uint16_t GetListIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CGlowOverlay", "m_ListIndex"); }
    void SetListIndex(uint16_t value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_ListIndex", false, value); }
    int32_t GetQueryHandle() const { return GetSchemaValue<int32_t>(m_ptr, "CGlowOverlay", "m_queryHandle"); }
    void SetQueryHandle(int32_t value) { SetSchemaValue(m_ptr, "CGlowOverlay", "m_queryHandle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif