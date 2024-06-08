class GCGameScriptedMoveData;

#ifndef _gccgamescriptedmovedata_h
#define _gccgamescriptedmovedata_h

#include "../../../scripting.h"

#include "../types/GScriptedMoveType_t.h"
#include "../types/GForcedCrouchState_t.h"


class GCGameScriptedMoveData
{
private:
    void *m_ptr;

public:
    GCGameScriptedMoveData() {}
    GCGameScriptedMoveData(void *ptr) : m_ptr(ptr) {}

    Vector GetAccumulatedRootMotion() const { return GetSchemaValue<Vector>(m_ptr, "CGameScriptedMoveData", "m_vAccumulatedRootMotion"); }
    void SetAccumulatedRootMotion(Vector value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_vAccumulatedRootMotion", false, value); }
    Vector GetDest() const { return GetSchemaValue<Vector>(m_ptr, "CGameScriptedMoveData", "m_vDest"); }
    void SetDest(Vector value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_vDest", false, value); }
    Vector GetSrc() const { return GetSchemaValue<Vector>(m_ptr, "CGameScriptedMoveData", "m_vSrc"); }
    void SetSrc(Vector value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_vSrc", false, value); }
    QAngle GetSrc1() const { return GetSchemaValue<QAngle>(m_ptr, "CGameScriptedMoveData", "m_angSrc"); }
    void SetSrc1(QAngle value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_angSrc", false, value); }
    QAngle GetDst() const { return GetSchemaValue<QAngle>(m_ptr, "CGameScriptedMoveData", "m_angDst"); }
    void SetDst(QAngle value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_angDst", false, value); }
    QAngle GetCurrent() const { return GetSchemaValue<QAngle>(m_ptr, "CGameScriptedMoveData", "m_angCurrent"); }
    void SetCurrent(QAngle value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_angCurrent", false, value); }
    float GetAngRate() const { return GetSchemaValue<float>(m_ptr, "CGameScriptedMoveData", "m_flAngRate"); }
    void SetAngRate(float value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_flAngRate", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CGameScriptedMoveData", "m_flDuration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_flDuration", false, value); }
    bool GetActive() const { return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bActive"); }
    void SetActive(bool value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bActive", false, value); }
    bool GetTeleportOnEnd() const { return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bTeleportOnEnd"); }
    void SetTeleportOnEnd(bool value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bTeleportOnEnd", false, value); }
    bool GetIgnoreRotation() const { return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bIgnoreRotation"); }
    void SetIgnoreRotation(bool value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bIgnoreRotation", false, value); }
    ScriptedMoveType_t GetType() const { return GetSchemaValue<ScriptedMoveType_t>(m_ptr, "CGameScriptedMoveData", "m_nType"); }
    void SetType(ScriptedMoveType_t value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_nType", false, value); }
    bool GetSuccess() const { return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bSuccess"); }
    void SetSuccess(bool value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bSuccess", false, value); }
    ForcedCrouchState_t GetForcedCrouchState() const { return GetSchemaValue<ForcedCrouchState_t>(m_ptr, "CGameScriptedMoveData", "m_nForcedCrouchState"); }
    void SetForcedCrouchState(ForcedCrouchState_t value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_nForcedCrouchState", false, value); }
    bool GetIgnoreCollisions() const { return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bIgnoreCollisions"); }
    void SetIgnoreCollisions(bool value) { SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bIgnoreCollisions", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif