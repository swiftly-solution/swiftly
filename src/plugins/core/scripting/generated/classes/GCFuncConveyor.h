class GCFuncConveyor;

#ifndef _gccfuncconveyor_h
#define _gccfuncconveyor_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCFuncConveyor
{
private:
    void *m_ptr;

public:
    GCFuncConveyor() {}
    GCFuncConveyor(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetConveyorModels() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncConveyor", "m_szConveyorModels"); }
    void SetConveyorModels(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncConveyor", "m_szConveyorModels", false, value); }
    float GetTransitionDurationSeconds() const { return GetSchemaValue<float>(m_ptr, "CFuncConveyor", "m_flTransitionDurationSeconds"); }
    void SetTransitionDurationSeconds(float value) { SetSchemaValue(m_ptr, "CFuncConveyor", "m_flTransitionDurationSeconds", false, value); }
    QAngle GetMoveEntitySpace() const { return GetSchemaValue<QAngle>(m_ptr, "CFuncConveyor", "m_angMoveEntitySpace"); }
    void SetMoveEntitySpace(QAngle value) { SetSchemaValue(m_ptr, "CFuncConveyor", "m_angMoveEntitySpace", false, value); }
    Vector GetMoveDirEntitySpace() const { return GetSchemaValue<Vector>(m_ptr, "CFuncConveyor", "m_vecMoveDirEntitySpace"); }
    void SetMoveDirEntitySpace(Vector value) { SetSchemaValue(m_ptr, "CFuncConveyor", "m_vecMoveDirEntitySpace", false, value); }
    float GetTargetSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncConveyor", "m_flTargetSpeed"); }
    void SetTargetSpeed(float value) { SetSchemaValue(m_ptr, "CFuncConveyor", "m_flTargetSpeed", false, value); }
    int32_t GetTransitionDurationTicks() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncConveyor", "m_nTransitionDurationTicks"); }
    void SetTransitionDurationTicks(int32_t value) { SetSchemaValue(m_ptr, "CFuncConveyor", "m_nTransitionDurationTicks", false, value); }
    float GetTransitionStartSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncConveyor", "m_flTransitionStartSpeed"); }
    void SetTransitionStartSpeed(float value) { SetSchemaValue(m_ptr, "CFuncConveyor", "m_flTransitionStartSpeed", false, value); }
    GCBaseEntity* GetConveyorModels1() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CFuncConveyor", "m_hConveyorModels"); }
    void SetConveyorModels1(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ConveyorModels1' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif