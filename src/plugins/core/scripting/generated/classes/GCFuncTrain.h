class GCFuncTrain;

#ifndef _gccfunctrain_h
#define _gccfunctrain_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCFuncTrain
{
private:
    void *m_ptr;

public:
    GCFuncTrain() {}
    GCFuncTrain(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetCurrentTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CFuncTrain", "m_hCurrentTarget"); }
    void SetCurrentTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CurrentTarget' is not possible.\n"); }
    bool GetActivated() const { return GetSchemaValue<bool>(m_ptr, "CFuncTrain", "m_activated"); }
    void SetActivated(bool value) { SetSchemaValue(m_ptr, "CFuncTrain", "m_activated", false, value); }
    GCBaseEntity* GetEnemy() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CFuncTrain", "m_hEnemy"); }
    void SetEnemy(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Enemy' is not possible.\n"); }
    float GetBlockDamage() const { return GetSchemaValue<float>(m_ptr, "CFuncTrain", "m_flBlockDamage"); }
    void SetBlockDamage(float value) { SetSchemaValue(m_ptr, "CFuncTrain", "m_flBlockDamage", false, value); }
    CUtlSymbolLarge GetLastTarget() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrain", "m_iszLastTarget"); }
    void SetLastTarget(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncTrain", "m_iszLastTarget", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif