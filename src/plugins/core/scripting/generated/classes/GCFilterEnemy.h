class GCFilterEnemy;

#ifndef _gccfilterenemy_h
#define _gccfilterenemy_h

#include "../../../scripting.h"




class GCFilterEnemy
{
private:
    void *m_ptr;

public:
    GCFilterEnemy() {}
    GCFilterEnemy(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetEnemyName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterEnemy", "m_iszEnemyName"); }
    void SetEnemyName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFilterEnemy", "m_iszEnemyName", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CFilterEnemy", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CFilterEnemy", "m_flRadius", false, value); }
    float GetOuterRadius() const { return GetSchemaValue<float>(m_ptr, "CFilterEnemy", "m_flOuterRadius"); }
    void SetOuterRadius(float value) { SetSchemaValue(m_ptr, "CFilterEnemy", "m_flOuterRadius", false, value); }
    int32_t GetMaxSquadmatesPerEnemy() const { return GetSchemaValue<int32_t>(m_ptr, "CFilterEnemy", "m_nMaxSquadmatesPerEnemy"); }
    void SetMaxSquadmatesPerEnemy(int32_t value) { SetSchemaValue(m_ptr, "CFilterEnemy", "m_nMaxSquadmatesPerEnemy", false, value); }
    CUtlSymbolLarge GetPlayerName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterEnemy", "m_iszPlayerName"); }
    void SetPlayerName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFilterEnemy", "m_iszPlayerName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif