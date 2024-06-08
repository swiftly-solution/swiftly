class GCFuncMoveLinear;

#ifndef _gccfuncmovelinear_h
#define _gccfuncmovelinear_h

#include "../../../scripting.h"

#include "../types/GMoveLinearAuthoredPos_t.h"
#include "GCEntityIOOutput.h"

class GCFuncMoveLinear
{
private:
    void *m_ptr;

public:
    GCFuncMoveLinear() {}
    GCFuncMoveLinear(void *ptr) : m_ptr(ptr) {}

    MoveLinearAuthoredPos_t GetAuthoredPosition() const { return GetSchemaValue<MoveLinearAuthoredPos_t>(m_ptr, "CFuncMoveLinear", "m_authoredPosition"); }
    void SetAuthoredPosition(MoveLinearAuthoredPos_t value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_authoredPosition", false, value); }
    QAngle GetMoveEntitySpace() const { return GetSchemaValue<QAngle>(m_ptr, "CFuncMoveLinear", "m_angMoveEntitySpace"); }
    void SetMoveEntitySpace(QAngle value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_angMoveEntitySpace", false, value); }
    Vector GetMoveDirParentSpace() const { return GetSchemaValue<Vector>(m_ptr, "CFuncMoveLinear", "m_vecMoveDirParentSpace"); }
    void SetMoveDirParentSpace(Vector value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_vecMoveDirParentSpace", false, value); }
    CUtlSymbolLarge GetSoundStart() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMoveLinear", "m_soundStart"); }
    void SetSoundStart(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_soundStart", false, value); }
    CUtlSymbolLarge GetSoundStop() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMoveLinear", "m_soundStop"); }
    void SetSoundStop(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_soundStop", false, value); }
    CUtlSymbolLarge GetCurrentSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMoveLinear", "m_currentSound"); }
    void SetCurrentSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_currentSound", false, value); }
    float GetBlockDamage() const { return GetSchemaValue<float>(m_ptr, "CFuncMoveLinear", "m_flBlockDamage"); }
    void SetBlockDamage(float value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_flBlockDamage", false, value); }
    float GetStartPosition() const { return GetSchemaValue<float>(m_ptr, "CFuncMoveLinear", "m_flStartPosition"); }
    void SetStartPosition(float value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_flStartPosition", false, value); }
    GCEntityIOOutput GetOnFullyOpen() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncMoveLinear", "m_OnFullyOpen"); }
    void SetOnFullyOpen(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_OnFullyOpen", false, value); }
    GCEntityIOOutput GetOnFullyClosed() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncMoveLinear", "m_OnFullyClosed"); }
    void SetOnFullyClosed(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_OnFullyClosed", false, value); }
    bool GetCreateMovableNavMesh() const { return GetSchemaValue<bool>(m_ptr, "CFuncMoveLinear", "m_bCreateMovableNavMesh"); }
    void SetCreateMovableNavMesh(bool value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_bCreateMovableNavMesh", false, value); }
    bool GetCreateNavObstacle() const { return GetSchemaValue<bool>(m_ptr, "CFuncMoveLinear", "m_bCreateNavObstacle"); }
    void SetCreateNavObstacle(bool value) { SetSchemaValue(m_ptr, "CFuncMoveLinear", "m_bCreateNavObstacle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif