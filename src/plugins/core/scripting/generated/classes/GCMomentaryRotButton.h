class GCMomentaryRotButton;

#ifndef _gccmomentaryrotbutton_h
#define _gccmomentaryrotbutton_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCMomentaryRotButton
{
private:
    void *m_ptr;

public:
    GCMomentaryRotButton() {}
    GCMomentaryRotButton(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnUnpressed() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMomentaryRotButton", "m_OnUnpressed"); }
    void SetOnUnpressed(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_OnUnpressed", false, value); }
    GCEntityIOOutput GetOnFullyOpen() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMomentaryRotButton", "m_OnFullyOpen"); }
    void SetOnFullyOpen(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_OnFullyOpen", false, value); }
    GCEntityIOOutput GetOnFullyClosed() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMomentaryRotButton", "m_OnFullyClosed"); }
    void SetOnFullyClosed(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_OnFullyClosed", false, value); }
    GCEntityIOOutput GetOnReachedPosition() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMomentaryRotButton", "m_OnReachedPosition"); }
    void SetOnReachedPosition(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_OnReachedPosition", false, value); }
    int32_t GetLastUsed() const { return GetSchemaValue<int32_t>(m_ptr, "CMomentaryRotButton", "m_lastUsed"); }
    void SetLastUsed(int32_t value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_lastUsed", false, value); }
    QAngle GetStart() const { return GetSchemaValue<QAngle>(m_ptr, "CMomentaryRotButton", "m_start"); }
    void SetStart(QAngle value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_start", false, value); }
    QAngle GetEnd() const { return GetSchemaValue<QAngle>(m_ptr, "CMomentaryRotButton", "m_end"); }
    void SetEnd(QAngle value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_end", false, value); }
    float GetIdealYaw() const { return GetSchemaValue<float>(m_ptr, "CMomentaryRotButton", "m_IdealYaw"); }
    void SetIdealYaw(float value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_IdealYaw", false, value); }
    CUtlSymbolLarge GetNoise() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMomentaryRotButton", "m_sNoise"); }
    void SetNoise(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_sNoise", false, value); }
    bool GetUpdateTarget() const { return GetSchemaValue<bool>(m_ptr, "CMomentaryRotButton", "m_bUpdateTarget"); }
    void SetUpdateTarget(bool value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_bUpdateTarget", false, value); }
    int32_t GetDirection() const { return GetSchemaValue<int32_t>(m_ptr, "CMomentaryRotButton", "m_direction"); }
    void SetDirection(int32_t value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_direction", false, value); }
    float GetReturnSpeed() const { return GetSchemaValue<float>(m_ptr, "CMomentaryRotButton", "m_returnSpeed"); }
    void SetReturnSpeed(float value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_returnSpeed", false, value); }
    float GetStartPosition() const { return GetSchemaValue<float>(m_ptr, "CMomentaryRotButton", "m_flStartPosition"); }
    void SetStartPosition(float value) { SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_flStartPosition", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif