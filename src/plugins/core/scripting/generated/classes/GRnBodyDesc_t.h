class GRnBodyDesc_t;

#ifndef _gcrnbodydesc_t_h
#define _gcrnbodydesc_t_h

#include "../../../scripting.h"




class GRnBodyDesc_t
{
private:
    void *m_ptr;

public:
    GRnBodyDesc_t() {}
    GRnBodyDesc_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetDebugName() const { return GetSchemaValue<CUtlString>(m_ptr, "RnBodyDesc_t", "m_sDebugName"); }
    void SetDebugName(CUtlString value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_sDebugName", true, value); }
    Vector GetPosition() const { return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vPosition"); }
    void SetPosition(Vector value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vPosition", true, value); }
    Vector GetLinearVelocity() const { return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vLinearVelocity"); }
    void SetLinearVelocity(Vector value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vLinearVelocity", true, value); }
    Vector GetAngularVelocity() const { return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vAngularVelocity"); }
    void SetAngularVelocity(Vector value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vAngularVelocity", true, value); }
    Vector GetLocalMassCenter() const { return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vLocalMassCenter"); }
    void SetLocalMassCenter(Vector value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vLocalMassCenter", true, value); }
    std::vector<Vector> GetLocalInertiaInv() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnBodyDesc_t", "m_LocalInertiaInv"); std::vector<Vector> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetLocalInertiaInv(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnBodyDesc_t", "m_LocalInertiaInv"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_LocalInertiaInv", true, outValue); }
    float GetMassInv() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flMassInv"); }
    void SetMassInv(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flMassInv", true, value); }
    float GetGameMass() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flGameMass"); }
    void SetGameMass(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flGameMass", true, value); }
    float GetInertiaScaleInv() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flInertiaScaleInv"); }
    void SetInertiaScaleInv(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flInertiaScaleInv", true, value); }
    float GetLinearDamping() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flLinearDamping"); }
    void SetLinearDamping(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flLinearDamping", true, value); }
    float GetAngularDamping() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flAngularDamping"); }
    void SetAngularDamping(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flAngularDamping", true, value); }
    float GetLinearDrag() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flLinearDrag"); }
    void SetLinearDrag(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flLinearDrag", true, value); }
    float GetAngularDrag() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flAngularDrag"); }
    void SetAngularDrag(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flAngularDrag", true, value); }
    float GetLinearBuoyancyDrag() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flLinearBuoyancyDrag"); }
    void SetLinearBuoyancyDrag(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flLinearBuoyancyDrag", true, value); }
    float GetAngularBuoyancyDrag() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flAngularBuoyancyDrag"); }
    void SetAngularBuoyancyDrag(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flAngularBuoyancyDrag", true, value); }
    Vector GetLastAwakeForceAccum() const { return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vLastAwakeForceAccum"); }
    void SetLastAwakeForceAccum(Vector value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vLastAwakeForceAccum", true, value); }
    Vector GetLastAwakeTorqueAccum() const { return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vLastAwakeTorqueAccum"); }
    void SetLastAwakeTorqueAccum(Vector value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vLastAwakeTorqueAccum", true, value); }
    float GetBuoyancyFactor() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flBuoyancyFactor"); }
    void SetBuoyancyFactor(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flBuoyancyFactor", true, value); }
    float GetGravityScale() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flGravityScale"); }
    void SetGravityScale(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flGravityScale", true, value); }
    float GetTimeScale() const { return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flTimeScale"); }
    void SetTimeScale(float value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flTimeScale", true, value); }
    int32_t GetBodyType() const { return GetSchemaValue<int32_t>(m_ptr, "RnBodyDesc_t", "m_nBodyType"); }
    void SetBodyType(int32_t value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nBodyType", true, value); }
    uint32_t GetGameIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "RnBodyDesc_t", "m_nGameIndex"); }
    void SetGameIndex(uint32_t value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nGameIndex", true, value); }
    uint32_t GetGameFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "RnBodyDesc_t", "m_nGameFlags"); }
    void SetGameFlags(uint32_t value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nGameFlags", true, value); }
    int8_t GetMinVelocityIterations() const { return GetSchemaValue<int8_t>(m_ptr, "RnBodyDesc_t", "m_nMinVelocityIterations"); }
    void SetMinVelocityIterations(int8_t value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nMinVelocityIterations", true, value); }
    int8_t GetMinPositionIterations() const { return GetSchemaValue<int8_t>(m_ptr, "RnBodyDesc_t", "m_nMinPositionIterations"); }
    void SetMinPositionIterations(int8_t value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nMinPositionIterations", true, value); }
    int8_t GetMassPriority() const { return GetSchemaValue<int8_t>(m_ptr, "RnBodyDesc_t", "m_nMassPriority"); }
    void SetMassPriority(int8_t value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nMassPriority", true, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bEnabled", true, value); }
    bool GetSleeping() const { return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bSleeping"); }
    void SetSleeping(bool value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bSleeping", true, value); }
    bool GetIsContinuousEnabled() const { return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bIsContinuousEnabled"); }
    void SetIsContinuousEnabled(bool value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bIsContinuousEnabled", true, value); }
    bool GetDragEnabled() const { return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bDragEnabled"); }
    void SetDragEnabled(bool value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bDragEnabled", true, value); }
    bool GetBuoyancyDragEnabled() const { return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bBuoyancyDragEnabled"); }
    void SetBuoyancyDragEnabled(bool value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bBuoyancyDragEnabled", true, value); }
    bool GetGravityDisabled() const { return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bGravityDisabled"); }
    void SetGravityDisabled(bool value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bGravityDisabled", true, value); }
    bool GetSpeculativeEnabled() const { return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bSpeculativeEnabled"); }
    void SetSpeculativeEnabled(bool value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bSpeculativeEnabled", true, value); }
    bool GetHasShadowController() const { return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bHasShadowController"); }
    void SetHasShadowController(bool value) { SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bHasShadowController", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif