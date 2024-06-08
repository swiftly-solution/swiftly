class GCCitadelSoundOpvarSetOBB;

#ifndef _gcccitadelsoundopvarsetobb_h
#define _gcccitadelsoundopvarsetobb_h

#include "../../../scripting.h"




class GCCitadelSoundOpvarSetOBB
{
private:
    void *m_ptr;

public:
    GCCitadelSoundOpvarSetOBB() {}
    GCCitadelSoundOpvarSetOBB(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetStackName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszStackName"); }
    void SetStackName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszStackName", false, value); }
    CUtlSymbolLarge GetOperatorName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszOperatorName"); }
    void SetOperatorName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszOperatorName", false, value); }
    CUtlSymbolLarge GetOpvarName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszOpvarName"); }
    void SetOpvarName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszOpvarName", false, value); }
    Vector GetDistanceInnerMins() const { return GetSchemaValue<Vector>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMins"); }
    void SetDistanceInnerMins(Vector value) { SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMins", false, value); }
    Vector GetDistanceInnerMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMaxs"); }
    void SetDistanceInnerMaxs(Vector value) { SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMaxs", false, value); }
    Vector GetDistanceOuterMins() const { return GetSchemaValue<Vector>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMins"); }
    void SetDistanceOuterMins(Vector value) { SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMins", false, value); }
    Vector GetDistanceOuterMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMaxs"); }
    void SetDistanceOuterMaxs(Vector value) { SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMaxs", false, value); }
    int32_t GetAABBDirection() const { return GetSchemaValue<int32_t>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_nAABBDirection"); }
    void SetAABBDirection(int32_t value) { SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_nAABBDirection", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif