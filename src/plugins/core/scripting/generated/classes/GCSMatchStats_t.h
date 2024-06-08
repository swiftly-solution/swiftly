class GCSMatchStats_t;

#ifndef _gccsmatchstats_t_h
#define _gccsmatchstats_t_h

#include "../../../scripting.h"




class GCSMatchStats_t
{
private:
    void *m_ptr;

public:
    GCSMatchStats_t() {}
    GCSMatchStats_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetEnemy5Ks() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemy5Ks"); }
    void SetEnemy5Ks(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemy5Ks", true, value); }
    int32_t GetEnemy4Ks() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemy4Ks"); }
    void SetEnemy4Ks(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemy4Ks", true, value); }
    int32_t GetEnemy3Ks() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemy3Ks"); }
    void SetEnemy3Ks(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemy3Ks", true, value); }
    int32_t GetEnemyKnifeKills() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemyKnifeKills"); }
    void SetEnemyKnifeKills(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemyKnifeKills", true, value); }
    int32_t GetEnemyTaserKills() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemyTaserKills"); }
    void SetEnemyTaserKills(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemyTaserKills", true, value); }
    int32_t GetEnemy2Ks() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEnemy2Ks"); }
    void SetEnemy2Ks(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEnemy2Ks", true, value); }
    int32_t GetUtility_Count() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iUtility_Count"); }
    void SetUtility_Count(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iUtility_Count", true, value); }
    int32_t GetUtility_Successes() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iUtility_Successes"); }
    void SetUtility_Successes(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iUtility_Successes", true, value); }
    int32_t GetUtility_Enemies() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iUtility_Enemies"); }
    void SetUtility_Enemies(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iUtility_Enemies", true, value); }
    int32_t GetFlash_Count() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iFlash_Count"); }
    void SetFlash_Count(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iFlash_Count", true, value); }
    int32_t GetFlash_Successes() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iFlash_Successes"); }
    void SetFlash_Successes(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iFlash_Successes", true, value); }
    int32_t GetHealthPointsRemovedTotal() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_nHealthPointsRemovedTotal"); }
    void SetHealthPointsRemovedTotal(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_nHealthPointsRemovedTotal", true, value); }
    int32_t GetHealthPointsDealtTotal() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_nHealthPointsDealtTotal"); }
    void SetHealthPointsDealtTotal(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_nHealthPointsDealtTotal", true, value); }
    int32_t GetShotsFiredTotal() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_nShotsFiredTotal"); }
    void SetShotsFiredTotal(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_nShotsFiredTotal", true, value); }
    int32_t GetShotsOnTargetTotal() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_nShotsOnTargetTotal"); }
    void SetShotsOnTargetTotal(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_nShotsOnTargetTotal", true, value); }
    int32_t Get1v1Count() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_i1v1Count"); }
    void Set1v1Count(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_i1v1Count", true, value); }
    int32_t Get1v1Wins() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_i1v1Wins"); }
    void Set1v1Wins(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_i1v1Wins", true, value); }
    int32_t Get1v2Count() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_i1v2Count"); }
    void Set1v2Count(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_i1v2Count", true, value); }
    int32_t Get1v2Wins() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_i1v2Wins"); }
    void Set1v2Wins(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_i1v2Wins", true, value); }
    int32_t GetEntryCount() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEntryCount"); }
    void SetEntryCount(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEntryCount", true, value); }
    int32_t GetEntryWins() const { return GetSchemaValue<int32_t>(m_ptr, "CSMatchStats_t", "m_iEntryWins"); }
    void SetEntryWins(int32_t value) { SetSchemaValue(m_ptr, "CSMatchStats_t", "m_iEntryWins", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif