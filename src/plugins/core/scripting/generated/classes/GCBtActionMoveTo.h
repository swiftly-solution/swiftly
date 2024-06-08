class GCBtActionMoveTo;

#ifndef _gccbtactionmoveto_h
#define _gccbtactionmoveto_h

#include "../../../scripting.h"


#include "GCountdownTimer.h"

class GCBtActionMoveTo
{
private:
    void *m_ptr;

public:
    GCBtActionMoveTo() {}
    GCBtActionMoveTo(void *ptr) : m_ptr(ptr) {}

    CUtlString GetDestinationInputKey() const { return GetSchemaValue<CUtlString>(m_ptr, "CBtActionMoveTo", "m_szDestinationInputKey"); }
    void SetDestinationInputKey(CUtlString value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_szDestinationInputKey", false, value); }
    CUtlString GetHidingSpotInputKey() const { return GetSchemaValue<CUtlString>(m_ptr, "CBtActionMoveTo", "m_szHidingSpotInputKey"); }
    void SetHidingSpotInputKey(CUtlString value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_szHidingSpotInputKey", false, value); }
    CUtlString GetThreatInputKey() const { return GetSchemaValue<CUtlString>(m_ptr, "CBtActionMoveTo", "m_szThreatInputKey"); }
    void SetThreatInputKey(CUtlString value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_szThreatInputKey", false, value); }
    Vector GetDestination() const { return GetSchemaValue<Vector>(m_ptr, "CBtActionMoveTo", "m_vecDestination"); }
    void SetDestination(Vector value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_vecDestination", false, value); }
    bool GetAutoLookAdjust() const { return GetSchemaValue<bool>(m_ptr, "CBtActionMoveTo", "m_bAutoLookAdjust"); }
    void SetAutoLookAdjust(bool value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_bAutoLookAdjust", false, value); }
    bool GetComputePath() const { return GetSchemaValue<bool>(m_ptr, "CBtActionMoveTo", "m_bComputePath"); }
    void SetComputePath(bool value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_bComputePath", false, value); }
    float GetDamagingAreasPenaltyCost() const { return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flDamagingAreasPenaltyCost"); }
    void SetDamagingAreasPenaltyCost(float value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flDamagingAreasPenaltyCost", false, value); }
    GCountdownTimer GetCheckApproximateCornersTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CBtActionMoveTo", "m_CheckApproximateCornersTimer"); }
    void SetCheckApproximateCornersTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_CheckApproximateCornersTimer", false, value); }
    GCountdownTimer GetCheckHighPriorityItem() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CBtActionMoveTo", "m_CheckHighPriorityItem"); }
    void SetCheckHighPriorityItem(GCountdownTimer value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_CheckHighPriorityItem", false, value); }
    GCountdownTimer GetRepathTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CBtActionMoveTo", "m_RepathTimer"); }
    void SetRepathTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_RepathTimer", false, value); }
    float GetArrivalEpsilon() const { return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flArrivalEpsilon"); }
    void SetArrivalEpsilon(float value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flArrivalEpsilon", false, value); }
    float GetAdditionalArrivalEpsilon2D() const { return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flAdditionalArrivalEpsilon2D"); }
    void SetAdditionalArrivalEpsilon2D(float value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flAdditionalArrivalEpsilon2D", false, value); }
    float GetHidingSpotCheckDistanceThreshold() const { return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flHidingSpotCheckDistanceThreshold"); }
    void SetHidingSpotCheckDistanceThreshold(float value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flHidingSpotCheckDistanceThreshold", false, value); }
    float GetNearestAreaDistanceThreshold() const { return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flNearestAreaDistanceThreshold"); }
    void SetNearestAreaDistanceThreshold(float value) { SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flNearestAreaDistanceThreshold", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif