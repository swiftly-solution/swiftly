class GCFish;

#ifndef _gccfish_h
#define _gccfish_h

#include "../../../scripting.h"


#include "GCFishPool.h"
#include "GCFish.h"
#include "GCountdownTimer.h"

class GCFish
{
private:
    void *m_ptr;

public:
    GCFish() {}
    GCFish(void *ptr) : m_ptr(ptr) {}

    GCFishPool* GetPool() const { return GetSchemaValue<GCFishPool*>(m_ptr, "CFish", "m_pool"); }
    void SetPool(GCFishPool* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Pool' is not possible.\n"); }
    uint32_t GetId() const { return GetSchemaValue<uint32_t>(m_ptr, "CFish", "m_id"); }
    void SetId(uint32_t value) { SetSchemaValue(m_ptr, "CFish", "m_id", false, value); }
    float GetX() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_x"); }
    void SetX(float value) { SetSchemaValue(m_ptr, "CFish", "m_x", false, value); }
    float GetY() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_y"); }
    void SetY(float value) { SetSchemaValue(m_ptr, "CFish", "m_y", false, value); }
    float GetZ() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_z"); }
    void SetZ(float value) { SetSchemaValue(m_ptr, "CFish", "m_z", false, value); }
    float GetAngle() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_angle"); }
    void SetAngle(float value) { SetSchemaValue(m_ptr, "CFish", "m_angle", false, value); }
    float GetAngleChange() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_angleChange"); }
    void SetAngleChange(float value) { SetSchemaValue(m_ptr, "CFish", "m_angleChange", false, value); }
    Vector GetForward() const { return GetSchemaValue<Vector>(m_ptr, "CFish", "m_forward"); }
    void SetForward(Vector value) { SetSchemaValue(m_ptr, "CFish", "m_forward", false, value); }
    Vector GetPerp() const { return GetSchemaValue<Vector>(m_ptr, "CFish", "m_perp"); }
    void SetPerp(Vector value) { SetSchemaValue(m_ptr, "CFish", "m_perp", false, value); }
    Vector GetPoolOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CFish", "m_poolOrigin"); }
    void SetPoolOrigin(Vector value) { SetSchemaValue(m_ptr, "CFish", "m_poolOrigin", false, value); }
    float GetWaterLevel() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_waterLevel"); }
    void SetWaterLevel(float value) { SetSchemaValue(m_ptr, "CFish", "m_waterLevel", false, value); }
    float GetSpeed() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_speed"); }
    void SetSpeed(float value) { SetSchemaValue(m_ptr, "CFish", "m_speed", false, value); }
    float GetDesiredSpeed() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_desiredSpeed"); }
    void SetDesiredSpeed(float value) { SetSchemaValue(m_ptr, "CFish", "m_desiredSpeed", false, value); }
    float GetCalmSpeed() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_calmSpeed"); }
    void SetCalmSpeed(float value) { SetSchemaValue(m_ptr, "CFish", "m_calmSpeed", false, value); }
    float GetPanicSpeed() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_panicSpeed"); }
    void SetPanicSpeed(float value) { SetSchemaValue(m_ptr, "CFish", "m_panicSpeed", false, value); }
    float GetAvoidRange() const { return GetSchemaValue<float>(m_ptr, "CFish", "m_avoidRange"); }
    void SetAvoidRange(float value) { SetSchemaValue(m_ptr, "CFish", "m_avoidRange", false, value); }
    GCountdownTimer GetTurnTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CFish", "m_turnTimer"); }
    void SetTurnTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CFish", "m_turnTimer", false, value); }
    bool GetTurnClockwise() const { return GetSchemaValue<bool>(m_ptr, "CFish", "m_turnClockwise"); }
    void SetTurnClockwise(bool value) { SetSchemaValue(m_ptr, "CFish", "m_turnClockwise", false, value); }
    GCountdownTimer GetGoTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CFish", "m_goTimer"); }
    void SetGoTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CFish", "m_goTimer", false, value); }
    GCountdownTimer GetMoveTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CFish", "m_moveTimer"); }
    void SetMoveTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CFish", "m_moveTimer", false, value); }
    GCountdownTimer GetPanicTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CFish", "m_panicTimer"); }
    void SetPanicTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CFish", "m_panicTimer", false, value); }
    GCountdownTimer GetDisperseTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CFish", "m_disperseTimer"); }
    void SetDisperseTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CFish", "m_disperseTimer", false, value); }
    GCountdownTimer GetProximityTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CFish", "m_proximityTimer"); }
    void SetProximityTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CFish", "m_proximityTimer", false, value); }
    std::vector<GCFish*> GetVisible() const { CUtlVector<GCFish*>* vec = GetSchemaValue<CUtlVector<GCFish*>*>(m_ptr, "CFish", "m_visible"); std::vector<GCFish*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVisible(std::vector<GCFish*> value) { SetSchemaValueCUtlVector<GCFish*>(m_ptr, "CFish", "m_visible", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif