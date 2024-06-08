class GCCSPlayerController_ActionTrackingServices;

#ifndef _gcccsplayercontroller_actiontrackingservices_h
#define _gcccsplayercontroller_actiontrackingservices_h

#include "../../../scripting.h"


#include "GCSPerRoundStats_t.h"
#include "GCSMatchStats_t.h"

class GCCSPlayerController_ActionTrackingServices
{
private:
    void *m_ptr;

public:
    GCCSPlayerController_ActionTrackingServices() {}
    GCCSPlayerController_ActionTrackingServices(void *ptr) : m_ptr(ptr) {}

    std::vector<GCSPerRoundStats_t> GetPerRoundStats() const { CUtlVector<GCSPerRoundStats_t>* vec = GetSchemaValue<CUtlVector<GCSPerRoundStats_t>*>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_perRoundStats"); std::vector<GCSPerRoundStats_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPerRoundStats(std::vector<GCSPerRoundStats_t> value) { SetSchemaValueCUtlVector<GCSPerRoundStats_t>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_perRoundStats", false, value); }
    GCSMatchStats_t GetMatchStats() const { return GetSchemaValue<GCSMatchStats_t>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_matchStats"); }
    void SetMatchStats(GCSMatchStats_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_matchStats", false, value); }
    int32_t GetNumRoundKills() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKills"); }
    void SetNumRoundKills(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKills", false, value); }
    int32_t GetNumRoundKillsHeadshots() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKillsHeadshots"); }
    void SetNumRoundKillsHeadshots(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKillsHeadshots", false, value); }
    uint32_t GetTotalRoundDamageDealt() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_unTotalRoundDamageDealt"); }
    void SetTotalRoundDamageDealt(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_ActionTrackingServices", "m_unTotalRoundDamageDealt", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif