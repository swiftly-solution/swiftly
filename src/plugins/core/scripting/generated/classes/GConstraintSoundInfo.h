class GConstraintSoundInfo;

#ifndef _gcconstraintsoundinfo_h
#define _gcconstraintsoundinfo_h

#include "../../../scripting.h"


#include "GVelocitySampler.h"
#include "GSimpleConstraintSoundProfile.h"

class GConstraintSoundInfo
{
private:
    void *m_ptr;

public:
    GConstraintSoundInfo() {}
    GConstraintSoundInfo(void *ptr) : m_ptr(ptr) {}

    GVelocitySampler GetSampler() const { return GetSchemaValue<GVelocitySampler>(m_ptr, "ConstraintSoundInfo", "m_vSampler"); }
    void SetSampler(GVelocitySampler value) { SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_vSampler", false, value); }
    GSimpleConstraintSoundProfile GetSoundProfile() const { return GetSchemaValue<GSimpleConstraintSoundProfile>(m_ptr, "ConstraintSoundInfo", "m_soundProfile"); }
    void SetSoundProfile(GSimpleConstraintSoundProfile value) { SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_soundProfile", false, value); }
    Vector GetForwardAxis() const { return GetSchemaValue<Vector>(m_ptr, "ConstraintSoundInfo", "m_forwardAxis"); }
    void SetForwardAxis(Vector value) { SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_forwardAxis", false, value); }
    CUtlSymbolLarge GetTravelSoundFwd() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ConstraintSoundInfo", "m_iszTravelSoundFwd"); }
    void SetTravelSoundFwd(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_iszTravelSoundFwd", false, value); }
    CUtlSymbolLarge GetTravelSoundBack() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ConstraintSoundInfo", "m_iszTravelSoundBack"); }
    void SetTravelSoundBack(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_iszTravelSoundBack", false, value); }
    std::vector<CUtlSymbolLarge> GetReversalSounds() const { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "ConstraintSoundInfo", "m_iszReversalSounds"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetReversalSounds(std::vector<CUtlSymbolLarge> value) { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "ConstraintSoundInfo", "m_iszReversalSounds"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_iszReversalSounds", false, outValue); }
    bool GetPlayTravelSound() const { return GetSchemaValue<bool>(m_ptr, "ConstraintSoundInfo", "m_bPlayTravelSound"); }
    void SetPlayTravelSound(bool value) { SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_bPlayTravelSound", false, value); }
    bool GetPlayReversalSound() const { return GetSchemaValue<bool>(m_ptr, "ConstraintSoundInfo", "m_bPlayReversalSound"); }
    void SetPlayReversalSound(bool value) { SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_bPlayReversalSound", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif