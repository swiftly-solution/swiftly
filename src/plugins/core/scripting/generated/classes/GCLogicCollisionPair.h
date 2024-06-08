class GCLogicCollisionPair;

#ifndef _gcclogiccollisionpair_h
#define _gcclogiccollisionpair_h

#include "../../../scripting.h"




class GCLogicCollisionPair
{
private:
    void *m_ptr;

public:
    GCLogicCollisionPair() {}
    GCLogicCollisionPair(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetNameAttach1() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicCollisionPair", "m_nameAttach1"); }
    void SetNameAttach1(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_nameAttach1", false, value); }
    CUtlSymbolLarge GetNameAttach2() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicCollisionPair", "m_nameAttach2"); }
    void SetNameAttach2(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_nameAttach2", false, value); }
    bool GetSupportMultipleEntitiesWithSameName() const { return GetSchemaValue<bool>(m_ptr, "CLogicCollisionPair", "m_supportMultipleEntitiesWithSameName"); }
    void SetSupportMultipleEntitiesWithSameName(bool value) { SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_supportMultipleEntitiesWithSameName", false, value); }
    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CLogicCollisionPair", "m_disabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_disabled", false, value); }
    bool GetSucceeded() const { return GetSchemaValue<bool>(m_ptr, "CLogicCollisionPair", "m_succeeded"); }
    void SetSucceeded(bool value) { SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_succeeded", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif