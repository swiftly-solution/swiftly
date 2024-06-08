class GCLogicMeasureMovement;

#ifndef _gcclogicmeasuremovement_h
#define _gcclogicmeasuremovement_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCLogicMeasureMovement
{
private:
    void *m_ptr;

public:
    GCLogicMeasureMovement() {}
    GCLogicMeasureMovement(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetStrMeasureTarget() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicMeasureMovement", "m_strMeasureTarget"); }
    void SetStrMeasureTarget(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_strMeasureTarget", false, value); }
    CUtlSymbolLarge GetStrMeasureReference() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicMeasureMovement", "m_strMeasureReference"); }
    void SetStrMeasureReference(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_strMeasureReference", false, value); }
    CUtlSymbolLarge GetStrTargetReference() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicMeasureMovement", "m_strTargetReference"); }
    void SetStrTargetReference(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_strTargetReference", false, value); }
    GCBaseEntity* GetMeasureTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CLogicMeasureMovement", "m_hMeasureTarget"); }
    void SetMeasureTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'MeasureTarget' is not possible.\n"); }
    GCBaseEntity* GetMeasureReference() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CLogicMeasureMovement", "m_hMeasureReference"); }
    void SetMeasureReference(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'MeasureReference' is not possible.\n"); }
    GCBaseEntity* GetTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CLogicMeasureMovement", "m_hTarget"); }
    void SetTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n"); }
    GCBaseEntity* GetTargetReference() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CLogicMeasureMovement", "m_hTargetReference"); }
    void SetTargetReference(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetReference' is not possible.\n"); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CLogicMeasureMovement", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_flScale", false, value); }
    int32_t GetMeasureType() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicMeasureMovement", "m_nMeasureType"); }
    void SetMeasureType(int32_t value) { SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_nMeasureType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif