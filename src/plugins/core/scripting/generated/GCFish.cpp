#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFish::GCFish(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFish::GCFish(void *ptr) {
    m_ptr = ptr;
}
GCFishPool GCFish::GetPool() const {
    GCFishPool value(*GetSchemaValuePtr<void*>(m_ptr, "CFish", "m_pool"));
    return value;
}
void GCFish::SetPool(GCFishPool* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Pool' is not possible.\n");
}
uint32_t GCFish::GetId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CFish", "m_id");
}
void GCFish::SetId(uint32_t value) {
    SetSchemaValue(m_ptr, "CFish", "m_id", false, value);
}
float GCFish::GetX() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_x");
}
void GCFish::SetX(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_x", false, value);
}
float GCFish::GetY() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_y");
}
void GCFish::SetY(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_y", false, value);
}
float GCFish::GetZ() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_z");
}
void GCFish::SetZ(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_z", false, value);
}
float GCFish::GetAngle() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_angle");
}
void GCFish::SetAngle(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_angle", false, value);
}
float GCFish::GetAngleChange() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_angleChange");
}
void GCFish::SetAngleChange(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_angleChange", false, value);
}
Vector GCFish::GetForward() const {
    return GetSchemaValue<Vector>(m_ptr, "CFish", "m_forward");
}
void GCFish::SetForward(Vector value) {
    SetSchemaValue(m_ptr, "CFish", "m_forward", false, value);
}
Vector GCFish::GetPerp() const {
    return GetSchemaValue<Vector>(m_ptr, "CFish", "m_perp");
}
void GCFish::SetPerp(Vector value) {
    SetSchemaValue(m_ptr, "CFish", "m_perp", false, value);
}
Vector GCFish::GetPoolOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CFish", "m_poolOrigin");
}
void GCFish::SetPoolOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CFish", "m_poolOrigin", false, value);
}
float GCFish::GetWaterLevel() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_waterLevel");
}
void GCFish::SetWaterLevel(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_waterLevel", false, value);
}
float GCFish::GetSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_speed");
}
void GCFish::SetSpeed(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_speed", false, value);
}
float GCFish::GetDesiredSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_desiredSpeed");
}
void GCFish::SetDesiredSpeed(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_desiredSpeed", false, value);
}
float GCFish::GetCalmSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_calmSpeed");
}
void GCFish::SetCalmSpeed(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_calmSpeed", false, value);
}
float GCFish::GetPanicSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_panicSpeed");
}
void GCFish::SetPanicSpeed(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_panicSpeed", false, value);
}
float GCFish::GetAvoidRange() const {
    return GetSchemaValue<float>(m_ptr, "CFish", "m_avoidRange");
}
void GCFish::SetAvoidRange(float value) {
    SetSchemaValue(m_ptr, "CFish", "m_avoidRange", false, value);
}
GCountdownTimer GCFish::GetTurnTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CFish", "m_turnTimer"));
    return value;
}
void GCFish::SetTurnTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CFish", "m_turnTimer", false, value);
}
bool GCFish::GetTurnClockwise() const {
    return GetSchemaValue<bool>(m_ptr, "CFish", "m_turnClockwise");
}
void GCFish::SetTurnClockwise(bool value) {
    SetSchemaValue(m_ptr, "CFish", "m_turnClockwise", false, value);
}
GCountdownTimer GCFish::GetGoTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CFish", "m_goTimer"));
    return value;
}
void GCFish::SetGoTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CFish", "m_goTimer", false, value);
}
GCountdownTimer GCFish::GetMoveTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CFish", "m_moveTimer"));
    return value;
}
void GCFish::SetMoveTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CFish", "m_moveTimer", false, value);
}
GCountdownTimer GCFish::GetPanicTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CFish", "m_panicTimer"));
    return value;
}
void GCFish::SetPanicTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CFish", "m_panicTimer", false, value);
}
GCountdownTimer GCFish::GetDisperseTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CFish", "m_disperseTimer"));
    return value;
}
void GCFish::SetDisperseTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CFish", "m_disperseTimer", false, value);
}
GCountdownTimer GCFish::GetProximityTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CFish", "m_proximityTimer"));
    return value;
}
void GCFish::SetProximityTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CFish", "m_proximityTimer", false, value);
}
std::vector<GCFish*> GCFish::GetVisible() const {
    CUtlVector<GCFish*>* vec = GetSchemaValue<CUtlVector<GCFish*>*>(m_ptr, "CFish", "m_visible"); std::vector<GCFish*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFish::SetVisible(std::vector<GCFish*> value) {
    SetSchemaValueCUtlVector<GCFish*>(m_ptr, "CFish", "m_visible", false, value);
}
std::string GCFish::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFish::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCFish::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCFish::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFish(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFish>("CFish")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Pool", &GCFish::GetPool, &GCFish::SetPool)
        .addProperty("Id", &GCFish::GetId, &GCFish::SetId)
        .addProperty("X", &GCFish::GetX, &GCFish::SetX)
        .addProperty("Y", &GCFish::GetY, &GCFish::SetY)
        .addProperty("Z", &GCFish::GetZ, &GCFish::SetZ)
        .addProperty("Angle", &GCFish::GetAngle, &GCFish::SetAngle)
        .addProperty("AngleChange", &GCFish::GetAngleChange, &GCFish::SetAngleChange)
        .addProperty("Forward", &GCFish::GetForward, &GCFish::SetForward)
        .addProperty("Perp", &GCFish::GetPerp, &GCFish::SetPerp)
        .addProperty("PoolOrigin", &GCFish::GetPoolOrigin, &GCFish::SetPoolOrigin)
        .addProperty("WaterLevel", &GCFish::GetWaterLevel, &GCFish::SetWaterLevel)
        .addProperty("Speed", &GCFish::GetSpeed, &GCFish::SetSpeed)
        .addProperty("DesiredSpeed", &GCFish::GetDesiredSpeed, &GCFish::SetDesiredSpeed)
        .addProperty("CalmSpeed", &GCFish::GetCalmSpeed, &GCFish::SetCalmSpeed)
        .addProperty("PanicSpeed", &GCFish::GetPanicSpeed, &GCFish::SetPanicSpeed)
        .addProperty("AvoidRange", &GCFish::GetAvoidRange, &GCFish::SetAvoidRange)
        .addProperty("TurnTimer", &GCFish::GetTurnTimer, &GCFish::SetTurnTimer)
        .addProperty("TurnClockwise", &GCFish::GetTurnClockwise, &GCFish::SetTurnClockwise)
        .addProperty("GoTimer", &GCFish::GetGoTimer, &GCFish::SetGoTimer)
        .addProperty("MoveTimer", &GCFish::GetMoveTimer, &GCFish::SetMoveTimer)
        .addProperty("PanicTimer", &GCFish::GetPanicTimer, &GCFish::SetPanicTimer)
        .addProperty("DisperseTimer", &GCFish::GetDisperseTimer, &GCFish::SetDisperseTimer)
        .addProperty("ProximityTimer", &GCFish::GetProximityTimer, &GCFish::SetProximityTimer)
        .addProperty("Visible", &GCFish::GetVisible, &GCFish::SetVisible)
        .addProperty("Parent", &GCFish::GetParent, &GCFish::SetParent)
        .addFunction("ToPtr", &GCFish::ToPtr)
        .addFunction("IsValid", &GCFish::IsValid)
        .endClass();
}