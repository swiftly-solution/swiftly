class GCFuncLadder;

#ifndef _gccfuncladder_h
#define _gccfuncladder_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCFuncLadder
{
private:
    void *m_ptr;

public:
    GCFuncLadder() {}
    GCFuncLadder(void *ptr) : m_ptr(ptr) {}

    Vector GetLadderDir() const { return GetSchemaValue<Vector>(m_ptr, "CFuncLadder", "m_vecLadderDir"); }
    void SetLadderDir(Vector value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_vecLadderDir", false, value); }
    Vector GetLocalTop() const { return GetSchemaValue<Vector>(m_ptr, "CFuncLadder", "m_vecLocalTop"); }
    void SetLocalTop(Vector value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_vecLocalTop", false, value); }
    Vector GetPlayerMountPositionTop() const { return GetSchemaValue<Vector>(m_ptr, "CFuncLadder", "m_vecPlayerMountPositionTop"); }
    void SetPlayerMountPositionTop(Vector value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_vecPlayerMountPositionTop", false, value); }
    Vector GetPlayerMountPositionBottom() const { return GetSchemaValue<Vector>(m_ptr, "CFuncLadder", "m_vecPlayerMountPositionBottom"); }
    void SetPlayerMountPositionBottom(Vector value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_vecPlayerMountPositionBottom", false, value); }
    float GetAutoRideSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncLadder", "m_flAutoRideSpeed"); }
    void SetAutoRideSpeed(float value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_flAutoRideSpeed", false, value); }
    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CFuncLadder", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_bDisabled", false, value); }
    bool GetFakeLadder() const { return GetSchemaValue<bool>(m_ptr, "CFuncLadder", "m_bFakeLadder"); }
    void SetFakeLadder(bool value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_bFakeLadder", false, value); }
    bool GetHasSlack() const { return GetSchemaValue<bool>(m_ptr, "CFuncLadder", "m_bHasSlack"); }
    void SetHasSlack(bool value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_bHasSlack", false, value); }
    CUtlSymbolLarge GetSurfacePropName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncLadder", "m_surfacePropName"); }
    void SetSurfacePropName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_surfacePropName", false, value); }
    GCEntityIOOutput GetOnPlayerGotOnLadder() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncLadder", "m_OnPlayerGotOnLadder"); }
    void SetOnPlayerGotOnLadder(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_OnPlayerGotOnLadder", false, value); }
    GCEntityIOOutput GetOnPlayerGotOffLadder() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncLadder", "m_OnPlayerGotOffLadder"); }
    void SetOnPlayerGotOffLadder(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncLadder", "m_OnPlayerGotOffLadder", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif