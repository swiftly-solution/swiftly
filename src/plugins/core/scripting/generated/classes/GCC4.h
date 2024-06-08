class GCC4;

#ifndef _gccc4_h
#define _gccc4_h

#include "../../../scripting.h"


#include "GEntitySpottedState_t.h"

class GCC4
{
private:
    void *m_ptr;

public:
    GCC4() {}
    GCC4(void *ptr) : m_ptr(ptr) {}

    Vector GetLastValidPlayerHeldPosition() const { return GetSchemaValue<Vector>(m_ptr, "CC4", "m_vecLastValidPlayerHeldPosition"); }
    void SetLastValidPlayerHeldPosition(Vector value) { SetSchemaValue(m_ptr, "CC4", "m_vecLastValidPlayerHeldPosition", false, value); }
    Vector GetLastValidDroppedPosition() const { return GetSchemaValue<Vector>(m_ptr, "CC4", "m_vecLastValidDroppedPosition"); }
    void SetLastValidDroppedPosition(Vector value) { SetSchemaValue(m_ptr, "CC4", "m_vecLastValidDroppedPosition", false, value); }
    bool GetDoValidDroppedPositionCheck() const { return GetSchemaValue<bool>(m_ptr, "CC4", "m_bDoValidDroppedPositionCheck"); }
    void SetDoValidDroppedPositionCheck(bool value) { SetSchemaValue(m_ptr, "CC4", "m_bDoValidDroppedPositionCheck", false, value); }
    bool GetStartedArming() const { return GetSchemaValue<bool>(m_ptr, "CC4", "m_bStartedArming"); }
    void SetStartedArming(bool value) { SetSchemaValue(m_ptr, "CC4", "m_bStartedArming", false, value); }
    bool GetBombPlacedAnimation() const { return GetSchemaValue<bool>(m_ptr, "CC4", "m_bBombPlacedAnimation"); }
    void SetBombPlacedAnimation(bool value) { SetSchemaValue(m_ptr, "CC4", "m_bBombPlacedAnimation", false, value); }
    bool GetIsPlantingViaUse() const { return GetSchemaValue<bool>(m_ptr, "CC4", "m_bIsPlantingViaUse"); }
    void SetIsPlantingViaUse(bool value) { SetSchemaValue(m_ptr, "CC4", "m_bIsPlantingViaUse", false, value); }
    GEntitySpottedState_t GetEntitySpottedState() const { return GetSchemaValue<GEntitySpottedState_t>(m_ptr, "CC4", "m_entitySpottedState"); }
    void SetEntitySpottedState(GEntitySpottedState_t value) { SetSchemaValue(m_ptr, "CC4", "m_entitySpottedState", false, value); }
    int32_t GetSpotRules() const { return GetSchemaValue<int32_t>(m_ptr, "CC4", "m_nSpotRules"); }
    void SetSpotRules(int32_t value) { SetSchemaValue(m_ptr, "CC4", "m_nSpotRules", false, value); }
    std::vector<bool> GetPlayedArmingBeeps() const { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CC4", "m_bPlayedArmingBeeps"); std::vector<bool> ret; for(int i = 0; i < 7; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetPlayedArmingBeeps(std::vector<bool> value) { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CC4", "m_bPlayedArmingBeeps"); for(int i = 0; i < 7; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CC4", "m_bPlayedArmingBeeps", false, outValue); }
    bool GetBombPlanted() const { return GetSchemaValue<bool>(m_ptr, "CC4", "m_bBombPlanted"); }
    void SetBombPlanted(bool value) { SetSchemaValue(m_ptr, "CC4", "m_bBombPlanted", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif