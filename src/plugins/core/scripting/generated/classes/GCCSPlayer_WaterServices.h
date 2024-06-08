class GCCSPlayer_WaterServices;

#ifndef _gcccsplayer_waterservices_h
#define _gcccsplayer_waterservices_h

#include "../../../scripting.h"




class GCCSPlayer_WaterServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_WaterServices() {}
    GCCSPlayer_WaterServices(void *ptr) : m_ptr(ptr) {}

    float GetNextDrownDamageTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_WaterServices", "m_NextDrownDamageTime"); }
    void SetNextDrownDamageTime(float value) { SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_NextDrownDamageTime", false, value); }
    int32_t GetDrownDmgRate() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WaterServices", "m_nDrownDmgRate"); }
    void SetDrownDmgRate(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_nDrownDmgRate", false, value); }
    float GetWaterJumpTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_WaterServices", "m_flWaterJumpTime"); }
    void SetWaterJumpTime(float value) { SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_flWaterJumpTime", false, value); }
    Vector GetWaterJumpVel() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayer_WaterServices", "m_vecWaterJumpVel"); }
    void SetWaterJumpVel(Vector value) { SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_vecWaterJumpVel", false, value); }
    float GetSwimSoundTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayer_WaterServices", "m_flSwimSoundTime"); }
    void SetSwimSoundTime(float value) { SetSchemaValue(m_ptr, "CCSPlayer_WaterServices", "m_flSwimSoundTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif