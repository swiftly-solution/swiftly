class GCPlayer_MovementServices_Humanoid;

#ifndef _gccplayer_movementservices_humanoid_h
#define _gccplayer_movementservices_humanoid_h

#include "../../../scripting.h"




class GCPlayer_MovementServices_Humanoid
{
private:
    void *m_ptr;

public:
    GCPlayer_MovementServices_Humanoid() {}
    GCPlayer_MovementServices_Humanoid(void *ptr) : m_ptr(ptr) {}

    float GetStepSoundTime() const { return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flStepSoundTime"); }
    void SetStepSoundTime(float value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flStepSoundTime", false, value); }
    float GetFallVelocity() const { return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flFallVelocity"); }
    void SetFallVelocity(float value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flFallVelocity", false, value); }
    bool GetInCrouch() const { return GetSchemaValue<bool>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bInCrouch"); }
    void SetInCrouch(bool value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bInCrouch", false, value); }
    uint32_t GetCrouchState() const { return GetSchemaValue<uint32_t>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_nCrouchState"); }
    void SetCrouchState(uint32_t value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_nCrouchState", false, value); }
    bool GetDucked() const { return GetSchemaValue<bool>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bDucked"); }
    void SetDucked(bool value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bDucked", false, value); }
    bool GetDucking() const { return GetSchemaValue<bool>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bDucking"); }
    void SetDucking(bool value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bDucking", false, value); }
    bool GetInDuckJump() const { return GetSchemaValue<bool>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bInDuckJump"); }
    void SetInDuckJump(bool value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bInDuckJump", false, value); }
    Vector GetGroundNormal() const { return GetSchemaValue<Vector>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_groundNormal"); }
    void SetGroundNormal(Vector value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_groundNormal", false, value); }
    float GetSurfaceFriction() const { return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flSurfaceFriction"); }
    void SetSurfaceFriction(float value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flSurfaceFriction", false, value); }
    CUtlStringToken GetSurfaceProps() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_surfaceProps"); }
    void SetSurfaceProps(CUtlStringToken value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_surfaceProps", false, value); }
    int32_t GetStepside() const { return GetSchemaValue<int32_t>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_nStepside"); }
    void SetStepside(int32_t value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_nStepside", false, value); }
    int32_t GetTargetVolume() const { return GetSchemaValue<int32_t>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_iTargetVolume"); }
    void SetTargetVolume(int32_t value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_iTargetVolume", false, value); }
    Vector GetSmoothedVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_vecSmoothedVelocity"); }
    void SetSmoothedVelocity(Vector value) { SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_vecSmoothedVelocity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif