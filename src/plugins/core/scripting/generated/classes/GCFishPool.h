class GCFishPool;

#ifndef _gccfishpool_h
#define _gccfishpool_h

#include "../../../scripting.h"


#include "GCountdownTimer.h"

class GCFishPool
{
private:
    void *m_ptr;

public:
    GCFishPool() {}
    GCFishPool(void *ptr) : m_ptr(ptr) {}

    int32_t GetFishCount() const { return GetSchemaValue<int32_t>(m_ptr, "CFishPool", "m_fishCount"); }
    void SetFishCount(int32_t value) { SetSchemaValue(m_ptr, "CFishPool", "m_fishCount", false, value); }
    float GetMaxRange() const { return GetSchemaValue<float>(m_ptr, "CFishPool", "m_maxRange"); }
    void SetMaxRange(float value) { SetSchemaValue(m_ptr, "CFishPool", "m_maxRange", false, value); }
    float GetSwimDepth() const { return GetSchemaValue<float>(m_ptr, "CFishPool", "m_swimDepth"); }
    void SetSwimDepth(float value) { SetSchemaValue(m_ptr, "CFishPool", "m_swimDepth", false, value); }
    float GetWaterLevel() const { return GetSchemaValue<float>(m_ptr, "CFishPool", "m_waterLevel"); }
    void SetWaterLevel(float value) { SetSchemaValue(m_ptr, "CFishPool", "m_waterLevel", false, value); }
    bool GetIsDormant() const { return GetSchemaValue<bool>(m_ptr, "CFishPool", "m_isDormant"); }
    void SetIsDormant(bool value) { SetSchemaValue(m_ptr, "CFishPool", "m_isDormant", false, value); }
    GCountdownTimer GetVisTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CFishPool", "m_visTimer"); }
    void SetVisTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CFishPool", "m_visTimer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif