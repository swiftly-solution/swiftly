class GCLogicDistanceCheck;

#ifndef _gcclogicdistancecheck_h
#define _gcclogicdistancecheck_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCLogicDistanceCheck
{
private:
    void *m_ptr;

public:
    GCLogicDistanceCheck() {}
    GCLogicDistanceCheck(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetEntityA() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicDistanceCheck", "m_iszEntityA"); }
    void SetEntityA(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_iszEntityA", false, value); }
    CUtlSymbolLarge GetEntityB() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicDistanceCheck", "m_iszEntityB"); }
    void SetEntityB(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_iszEntityB", false, value); }
    float GetZone1Distance() const { return GetSchemaValue<float>(m_ptr, "CLogicDistanceCheck", "m_flZone1Distance"); }
    void SetZone1Distance(float value) { SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_flZone1Distance", false, value); }
    float GetZone2Distance() const { return GetSchemaValue<float>(m_ptr, "CLogicDistanceCheck", "m_flZone2Distance"); }
    void SetZone2Distance(float value) { SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_flZone2Distance", false, value); }
    GCEntityIOOutput GetInZone1() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicDistanceCheck", "m_InZone1"); }
    void SetInZone1(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_InZone1", false, value); }
    GCEntityIOOutput GetInZone2() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicDistanceCheck", "m_InZone2"); }
    void SetInZone2(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_InZone2", false, value); }
    GCEntityIOOutput GetInZone3() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicDistanceCheck", "m_InZone3"); }
    void SetInZone3(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_InZone3", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif