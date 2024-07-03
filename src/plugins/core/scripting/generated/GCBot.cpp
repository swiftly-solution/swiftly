#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBot::GCBot(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBot::GCBot(void *ptr) {
    m_ptr = ptr;
}
GCCSPlayerController GCBot::GetController() const {
    GCCSPlayerController value(*GetSchemaValuePtr<void*>(m_ptr, "CBot", "m_pController"));
    return value;
}
void GCBot::SetController(GCCSPlayerController* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Controller' is not possible.\n");
}
GCCSPlayerPawn GCBot::GetPlayer() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CBot", "m_pPlayer"));
    return value;
}
void GCBot::SetPlayer(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Player' is not possible.\n");
}
bool GCBot::GetHasSpawned() const {
    return GetSchemaValue<bool>(m_ptr, "CBot", "m_bHasSpawned");
}
void GCBot::SetHasSpawned(bool value) {
    SetSchemaValue(m_ptr, "CBot", "m_bHasSpawned", false, value);
}
uint32_t GCBot::GetId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBot", "m_id");
}
void GCBot::SetId(uint32_t value) {
    SetSchemaValue(m_ptr, "CBot", "m_id", false, value);
}
bool GCBot::GetIsRunning() const {
    return GetSchemaValue<bool>(m_ptr, "CBot", "m_isRunning");
}
void GCBot::SetIsRunning(bool value) {
    SetSchemaValue(m_ptr, "CBot", "m_isRunning", false, value);
}
bool GCBot::GetIsCrouching() const {
    return GetSchemaValue<bool>(m_ptr, "CBot", "m_isCrouching");
}
void GCBot::SetIsCrouching(bool value) {
    SetSchemaValue(m_ptr, "CBot", "m_isCrouching", false, value);
}
float GCBot::GetForwardSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CBot", "m_forwardSpeed");
}
void GCBot::SetForwardSpeed(float value) {
    SetSchemaValue(m_ptr, "CBot", "m_forwardSpeed", false, value);
}
float GCBot::GetLeftSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CBot", "m_leftSpeed");
}
void GCBot::SetLeftSpeed(float value) {
    SetSchemaValue(m_ptr, "CBot", "m_leftSpeed", false, value);
}
float GCBot::GetVerticalSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CBot", "m_verticalSpeed");
}
void GCBot::SetVerticalSpeed(float value) {
    SetSchemaValue(m_ptr, "CBot", "m_verticalSpeed", false, value);
}
uint64_t GCBot::GetButtonFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBot", "m_buttonFlags");
}
void GCBot::SetButtonFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "CBot", "m_buttonFlags", false, value);
}
float GCBot::GetJumpTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CBot", "m_jumpTimestamp");
}
void GCBot::SetJumpTimestamp(float value) {
    SetSchemaValue(m_ptr, "CBot", "m_jumpTimestamp", false, value);
}
Vector GCBot::GetViewForward() const {
    return GetSchemaValue<Vector>(m_ptr, "CBot", "m_viewForward");
}
void GCBot::SetViewForward(Vector value) {
    SetSchemaValue(m_ptr, "CBot", "m_viewForward", false, value);
}
int32_t GCBot::GetPostureStackIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBot", "m_postureStackIndex");
}
void GCBot::SetPostureStackIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CBot", "m_postureStackIndex", false, value);
}
std::string GCBot::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBot::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBot>("CBot")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Controller", &GCBot::GetController, &GCBot::SetController)
        .addProperty("Player", &GCBot::GetPlayer, &GCBot::SetPlayer)
        .addProperty("HasSpawned", &GCBot::GetHasSpawned, &GCBot::SetHasSpawned)
        .addProperty("Id", &GCBot::GetId, &GCBot::SetId)
        .addProperty("IsRunning", &GCBot::GetIsRunning, &GCBot::SetIsRunning)
        .addProperty("IsCrouching", &GCBot::GetIsCrouching, &GCBot::SetIsCrouching)
        .addProperty("ForwardSpeed", &GCBot::GetForwardSpeed, &GCBot::SetForwardSpeed)
        .addProperty("LeftSpeed", &GCBot::GetLeftSpeed, &GCBot::SetLeftSpeed)
        .addProperty("VerticalSpeed", &GCBot::GetVerticalSpeed, &GCBot::SetVerticalSpeed)
        .addProperty("ButtonFlags", &GCBot::GetButtonFlags, &GCBot::SetButtonFlags)
        .addProperty("JumpTimestamp", &GCBot::GetJumpTimestamp, &GCBot::SetJumpTimestamp)
        .addProperty("ViewForward", &GCBot::GetViewForward, &GCBot::SetViewForward)
        .addProperty("PostureStackIndex", &GCBot::GetPostureStackIndex, &GCBot::SetPostureStackIndex)
        .addFunction("ToPtr", &GCBot::ToPtr)
        .addFunction("IsValid", &GCBot::IsValid)
        .endClass();
}