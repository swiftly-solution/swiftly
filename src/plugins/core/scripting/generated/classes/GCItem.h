class GCItem;

#ifndef _gccitem_h
#define _gccitem_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCItem
{
private:
    void *m_ptr;

public:
    GCItem() {}
    GCItem(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnPlayerTouch() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CItem", "m_OnPlayerTouch"); }
    void SetOnPlayerTouch(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CItem", "m_OnPlayerTouch", false, value); }
    GCEntityIOOutput GetOnPlayerPickup() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CItem", "m_OnPlayerPickup"); }
    void SetOnPlayerPickup(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CItem", "m_OnPlayerPickup", false, value); }
    bool GetActivateWhenAtRest() const { return GetSchemaValue<bool>(m_ptr, "CItem", "m_bActivateWhenAtRest"); }
    void SetActivateWhenAtRest(bool value) { SetSchemaValue(m_ptr, "CItem", "m_bActivateWhenAtRest", false, value); }
    GCEntityIOOutput GetOnCacheInteraction() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CItem", "m_OnCacheInteraction"); }
    void SetOnCacheInteraction(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CItem", "m_OnCacheInteraction", false, value); }
    GCEntityIOOutput GetOnGlovePulled() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CItem", "m_OnGlovePulled"); }
    void SetOnGlovePulled(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CItem", "m_OnGlovePulled", false, value); }
    Vector GetOriginalSpawnOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CItem", "m_vOriginalSpawnOrigin"); }
    void SetOriginalSpawnOrigin(Vector value) { SetSchemaValue(m_ptr, "CItem", "m_vOriginalSpawnOrigin", false, value); }
    QAngle GetOriginalSpawnAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CItem", "m_vOriginalSpawnAngles"); }
    void SetOriginalSpawnAngles(QAngle value) { SetSchemaValue(m_ptr, "CItem", "m_vOriginalSpawnAngles", false, value); }
    bool GetPhysStartAsleep() const { return GetSchemaValue<bool>(m_ptr, "CItem", "m_bPhysStartAsleep"); }
    void SetPhysStartAsleep(bool value) { SetSchemaValue(m_ptr, "CItem", "m_bPhysStartAsleep", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif