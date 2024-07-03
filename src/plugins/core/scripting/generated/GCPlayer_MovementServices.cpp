#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_MovementServices::GCPlayer_MovementServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_MovementServices::GCPlayer_MovementServices(void *ptr) {
    m_ptr = ptr;
}
int32_t GCPlayer_MovementServices::GetImpulse() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlayer_MovementServices", "m_nImpulse");
}
void GCPlayer_MovementServices::SetImpulse(int32_t value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nImpulse", false, value);
}
GCInButtonState GCPlayer_MovementServices::GetButtons() const {
    GCInButtonState value(GetSchemaPtr(m_ptr, "CPlayer_MovementServices", "m_nButtons"));
    return value;
}
void GCPlayer_MovementServices::SetButtons(GCInButtonState value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nButtons", false, value);
}
uint64_t GCPlayer_MovementServices::GetQueuedButtonDownMask() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPlayer_MovementServices", "m_nQueuedButtonDownMask");
}
void GCPlayer_MovementServices::SetQueuedButtonDownMask(uint64_t value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nQueuedButtonDownMask", false, value);
}
uint64_t GCPlayer_MovementServices::GetQueuedButtonChangeMask() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPlayer_MovementServices", "m_nQueuedButtonChangeMask");
}
void GCPlayer_MovementServices::SetQueuedButtonChangeMask(uint64_t value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nQueuedButtonChangeMask", false, value);
}
uint64_t GCPlayer_MovementServices::GetButtonDoublePressed() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPlayer_MovementServices", "m_nButtonDoublePressed");
}
void GCPlayer_MovementServices::SetButtonDoublePressed(uint64_t value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nButtonDoublePressed", false, value);
}
std::vector<uint32_t> GCPlayer_MovementServices::GetButtonPressedCmdNumber() const {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CPlayer_MovementServices", "m_pButtonPressedCmdNumber"); std::vector<uint32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCPlayer_MovementServices::SetButtonPressedCmdNumber(std::vector<uint32_t> value) {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CPlayer_MovementServices", "m_pButtonPressedCmdNumber"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_pButtonPressedCmdNumber", false, outValue);
}
uint32_t GCPlayer_MovementServices::GetLastCommandNumberProcessed() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPlayer_MovementServices", "m_nLastCommandNumberProcessed");
}
void GCPlayer_MovementServices::SetLastCommandNumberProcessed(uint32_t value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nLastCommandNumberProcessed", false, value);
}
uint64_t GCPlayer_MovementServices::GetToggleButtonDownMask() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPlayer_MovementServices", "m_nToggleButtonDownMask");
}
void GCPlayer_MovementServices::SetToggleButtonDownMask(uint64_t value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_nToggleButtonDownMask", false, value);
}
float GCPlayer_MovementServices::GetMaxspeed() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices", "m_flMaxspeed");
}
void GCPlayer_MovementServices::SetMaxspeed(float value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_flMaxspeed", false, value);
}
std::vector<float> GCPlayer_MovementServices::GetForceSubtickMoveWhen() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CPlayer_MovementServices", "m_arrForceSubtickMoveWhen"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCPlayer_MovementServices::SetForceSubtickMoveWhen(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CPlayer_MovementServices", "m_arrForceSubtickMoveWhen"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_arrForceSubtickMoveWhen", false, outValue);
}
float GCPlayer_MovementServices::GetForwardMove() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices", "m_flForwardMove");
}
void GCPlayer_MovementServices::SetForwardMove(float value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_flForwardMove", false, value);
}
float GCPlayer_MovementServices::GetLeftMove() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices", "m_flLeftMove");
}
void GCPlayer_MovementServices::SetLeftMove(float value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_flLeftMove", false, value);
}
float GCPlayer_MovementServices::GetUpMove() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices", "m_flUpMove");
}
void GCPlayer_MovementServices::SetUpMove(float value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_flUpMove", false, value);
}
Vector GCPlayer_MovementServices::GetLastMovementImpulses() const {
    return GetSchemaValue<Vector>(m_ptr, "CPlayer_MovementServices", "m_vecLastMovementImpulses");
}
void GCPlayer_MovementServices::SetLastMovementImpulses(Vector value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_vecLastMovementImpulses", false, value);
}
QAngle GCPlayer_MovementServices::GetOldViewAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPlayer_MovementServices", "m_vecOldViewAngles");
}
void GCPlayer_MovementServices::SetOldViewAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices", "m_vecOldViewAngles", false, value);
}
std::string GCPlayer_MovementServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_MovementServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_MovementServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_MovementServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_MovementServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_MovementServices>("CPlayer_MovementServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Impulse", &GCPlayer_MovementServices::GetImpulse, &GCPlayer_MovementServices::SetImpulse)
        .addProperty("Buttons", &GCPlayer_MovementServices::GetButtons, &GCPlayer_MovementServices::SetButtons)
        .addProperty("QueuedButtonDownMask", &GCPlayer_MovementServices::GetQueuedButtonDownMask, &GCPlayer_MovementServices::SetQueuedButtonDownMask)
        .addProperty("QueuedButtonChangeMask", &GCPlayer_MovementServices::GetQueuedButtonChangeMask, &GCPlayer_MovementServices::SetQueuedButtonChangeMask)
        .addProperty("ButtonDoublePressed", &GCPlayer_MovementServices::GetButtonDoublePressed, &GCPlayer_MovementServices::SetButtonDoublePressed)
        .addProperty("ButtonPressedCmdNumber", &GCPlayer_MovementServices::GetButtonPressedCmdNumber, &GCPlayer_MovementServices::SetButtonPressedCmdNumber)
        .addProperty("LastCommandNumberProcessed", &GCPlayer_MovementServices::GetLastCommandNumberProcessed, &GCPlayer_MovementServices::SetLastCommandNumberProcessed)
        .addProperty("ToggleButtonDownMask", &GCPlayer_MovementServices::GetToggleButtonDownMask, &GCPlayer_MovementServices::SetToggleButtonDownMask)
        .addProperty("Maxspeed", &GCPlayer_MovementServices::GetMaxspeed, &GCPlayer_MovementServices::SetMaxspeed)
        .addProperty("ForceSubtickMoveWhen", &GCPlayer_MovementServices::GetForceSubtickMoveWhen, &GCPlayer_MovementServices::SetForceSubtickMoveWhen)
        .addProperty("ForwardMove", &GCPlayer_MovementServices::GetForwardMove, &GCPlayer_MovementServices::SetForwardMove)
        .addProperty("LeftMove", &GCPlayer_MovementServices::GetLeftMove, &GCPlayer_MovementServices::SetLeftMove)
        .addProperty("UpMove", &GCPlayer_MovementServices::GetUpMove, &GCPlayer_MovementServices::SetUpMove)
        .addProperty("LastMovementImpulses", &GCPlayer_MovementServices::GetLastMovementImpulses, &GCPlayer_MovementServices::SetLastMovementImpulses)
        .addProperty("OldViewAngles", &GCPlayer_MovementServices::GetOldViewAngles, &GCPlayer_MovementServices::SetOldViewAngles)
        .addProperty("Parent", &GCPlayer_MovementServices::GetParent, &GCPlayer_MovementServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_MovementServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_MovementServices::IsValid)
        .endClass();
}