class GCFuncMover;

#ifndef _gccfuncmover_h
#define _gccfuncmover_h

#include "../../../scripting.h"


#include "GCPathMover.h"
#include "GCFuncMover.h"
#include "GCMoverPathNode.h"

class GCFuncMover
{
private:
    void *m_ptr;

public:
    GCFuncMover() {}
    GCFuncMover(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetPathName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMover", "m_iszPathName"); }
    void SetPathName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncMover", "m_iszPathName", false, value); }
    GCPathMover* GetPathMover() const { return GetSchemaValue<GCPathMover*>(m_ptr, "CFuncMover", "m_hPathMover"); }
    void SetPathMover(GCPathMover* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PathMover' is not possible.\n"); }
    CUtlSymbolLarge GetPathNodeStart() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMover", "m_iszPathNodeStart"); }
    void SetPathNodeStart(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncMover", "m_iszPathNodeStart", false, value); }
    GCFuncMover GetMoveType() const { return GetSchemaValue<GCFuncMover>(m_ptr, "CFuncMover", "m_eMoveType"); }
    void SetMoveType(GCFuncMover value) { SetSchemaValue(m_ptr, "CFuncMover", "m_eMoveType", false, value); }
    bool GetIsReversing() const { return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bIsReversing"); }
    void SetIsReversing(bool value) { SetSchemaValue(m_ptr, "CFuncMover", "m_bIsReversing", false, value); }
    Vector GetTarget() const { return GetSchemaValue<Vector>(m_ptr, "CFuncMover", "m_vTarget"); }
    void SetTarget(Vector value) { SetSchemaValue(m_ptr, "CFuncMover", "m_vTarget", false, value); }
    float GetStartSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flStartSpeed"); }
    void SetStartSpeed(float value) { SetSchemaValue(m_ptr, "CFuncMover", "m_flStartSpeed", false, value); }
    float GetPathLocation() const { return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flPathLocation"); }
    void SetPathLocation(float value) { SetSchemaValue(m_ptr, "CFuncMover", "m_flPathLocation", false, value); }
    float GetT() const { return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flT"); }
    void SetT(float value) { SetSchemaValue(m_ptr, "CFuncMover", "m_flT", false, value); }
    int32_t GetCurrentNodeIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncMover", "m_nCurrentNodeIndex"); }
    void SetCurrentNodeIndex(int32_t value) { SetSchemaValue(m_ptr, "CFuncMover", "m_nCurrentNodeIndex", false, value); }
    int32_t GetPreviousNodeIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncMover", "m_nPreviousNodeIndex"); }
    void SetPreviousNodeIndex(int32_t value) { SetSchemaValue(m_ptr, "CFuncMover", "m_nPreviousNodeIndex", false, value); }
    bool GetFixedOrientation() const { return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bFixedOrientation"); }
    void SetFixedOrientation(bool value) { SetSchemaValue(m_ptr, "CFuncMover", "m_bFixedOrientation", false, value); }
    bool GetFixedPitch() const { return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bFixedPitch"); }
    void SetFixedPitch(bool value) { SetSchemaValue(m_ptr, "CFuncMover", "m_bFixedPitch", false, value); }
    SolidType_t GetSolidType() const { return GetSchemaValue<SolidType_t>(m_ptr, "CFuncMover", "m_eSolidType"); }
    void SetSolidType(SolidType_t value) { SetSchemaValue(m_ptr, "CFuncMover", "m_eSolidType", false, value); }
    bool GetIsMoving() const { return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bIsMoving"); }
    void SetIsMoving(bool value) { SetSchemaValue(m_ptr, "CFuncMover", "m_bIsMoving", false, value); }
    float GetTimeToReachMaxSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flTimeToReachMaxSpeed"); }
    void SetTimeToReachMaxSpeed(float value) { SetSchemaValue(m_ptr, "CFuncMover", "m_flTimeToReachMaxSpeed", false, value); }
    float GetTimeToReachZeroSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flTimeToReachZeroSpeed"); }
    void SetTimeToReachZeroSpeed(float value) { SetSchemaValue(m_ptr, "CFuncMover", "m_flTimeToReachZeroSpeed", false, value); }
    GCMoverPathNode* GetStopAtNode() const { return GetSchemaValue<GCMoverPathNode*>(m_ptr, "CFuncMover", "m_hStopAtNode"); }
    void SetStopAtNode(GCMoverPathNode* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'StopAtNode' is not possible.\n"); }
    float GetPathLocationToBeginStop() const { return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flPathLocationToBeginStop"); }
    void SetPathLocationToBeginStop(float value) { SetSchemaValue(m_ptr, "CFuncMover", "m_flPathLocationToBeginStop", false, value); }
    bool GetMatchPathNodeUp() const { return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bMatchPathNodeUp"); }
    void SetMatchPathNodeUp(bool value) { SetSchemaValue(m_ptr, "CFuncMover", "m_bMatchPathNodeUp", false, value); }
    bool GetFacePlayer() const { return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bFacePlayer"); }
    void SetFacePlayer(bool value) { SetSchemaValue(m_ptr, "CFuncMover", "m_bFacePlayer", false, value); }
    Vector GetOriginalUp() const { return GetSchemaValue<Vector>(m_ptr, "CFuncMover", "m_vOriginalUp"); }
    void SetOriginalUp(Vector value) { SetSchemaValue(m_ptr, "CFuncMover", "m_vOriginalUp", false, value); }
    float GetTimeToRollToNewUp() const { return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flTimeToRollToNewUp"); }
    void SetTimeToRollToNewUp(float value) { SetSchemaValue(m_ptr, "CFuncMover", "m_flTimeToRollToNewUp", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif