#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMomentaryRotButton::GCMomentaryRotButton(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMomentaryRotButton::GCMomentaryRotButton(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCMomentaryRotButton::GetOnUnpressed() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMomentaryRotButton", "m_OnUnpressed"));
    return value;
}
void GCMomentaryRotButton::SetOnUnpressed(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_OnUnpressed", false, value);
}
GCEntityIOOutput GCMomentaryRotButton::GetOnFullyOpen() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMomentaryRotButton", "m_OnFullyOpen"));
    return value;
}
void GCMomentaryRotButton::SetOnFullyOpen(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_OnFullyOpen", false, value);
}
GCEntityIOOutput GCMomentaryRotButton::GetOnFullyClosed() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMomentaryRotButton", "m_OnFullyClosed"));
    return value;
}
void GCMomentaryRotButton::SetOnFullyClosed(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_OnFullyClosed", false, value);
}
GCEntityIOOutput GCMomentaryRotButton::GetOnReachedPosition() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMomentaryRotButton", "m_OnReachedPosition"));
    return value;
}
void GCMomentaryRotButton::SetOnReachedPosition(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_OnReachedPosition", false, value);
}
int32_t GCMomentaryRotButton::GetLastUsed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMomentaryRotButton", "m_lastUsed");
}
void GCMomentaryRotButton::SetLastUsed(int32_t value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_lastUsed", false, value);
}
QAngle GCMomentaryRotButton::GetStart() const {
    return GetSchemaValue<QAngle>(m_ptr, "CMomentaryRotButton", "m_start");
}
void GCMomentaryRotButton::SetStart(QAngle value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_start", false, value);
}
QAngle GCMomentaryRotButton::GetEnd() const {
    return GetSchemaValue<QAngle>(m_ptr, "CMomentaryRotButton", "m_end");
}
void GCMomentaryRotButton::SetEnd(QAngle value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_end", false, value);
}
float GCMomentaryRotButton::GetIdealYaw() const {
    return GetSchemaValue<float>(m_ptr, "CMomentaryRotButton", "m_IdealYaw");
}
void GCMomentaryRotButton::SetIdealYaw(float value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_IdealYaw", false, value);
}
std::string GCMomentaryRotButton::GetNoise() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMomentaryRotButton", "m_sNoise").String();
}
void GCMomentaryRotButton::SetNoise(std::string value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_sNoise", false, CUtlSymbolLarge(value.c_str()));
}
bool GCMomentaryRotButton::GetUpdateTarget() const {
    return GetSchemaValue<bool>(m_ptr, "CMomentaryRotButton", "m_bUpdateTarget");
}
void GCMomentaryRotButton::SetUpdateTarget(bool value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_bUpdateTarget", false, value);
}
int32_t GCMomentaryRotButton::GetDirection() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMomentaryRotButton", "m_direction");
}
void GCMomentaryRotButton::SetDirection(int32_t value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_direction", false, value);
}
float GCMomentaryRotButton::GetReturnSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CMomentaryRotButton", "m_returnSpeed");
}
void GCMomentaryRotButton::SetReturnSpeed(float value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_returnSpeed", false, value);
}
float GCMomentaryRotButton::GetStartPosition() const {
    return GetSchemaValue<float>(m_ptr, "CMomentaryRotButton", "m_flStartPosition");
}
void GCMomentaryRotButton::SetStartPosition(float value) {
    SetSchemaValue(m_ptr, "CMomentaryRotButton", "m_flStartPosition", false, value);
}
std::string GCMomentaryRotButton::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMomentaryRotButton::IsValid() {
    return (m_ptr != nullptr);
}
GCRotButton GCMomentaryRotButton::GetParent() const {
    GCRotButton value(m_ptr);
    return value;
}
void GCMomentaryRotButton::SetParent(GCRotButton value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMomentaryRotButton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMomentaryRotButton>("CMomentaryRotButton")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnUnpressed", &GCMomentaryRotButton::GetOnUnpressed, &GCMomentaryRotButton::SetOnUnpressed)
        .addProperty("OnFullyOpen", &GCMomentaryRotButton::GetOnFullyOpen, &GCMomentaryRotButton::SetOnFullyOpen)
        .addProperty("OnFullyClosed", &GCMomentaryRotButton::GetOnFullyClosed, &GCMomentaryRotButton::SetOnFullyClosed)
        .addProperty("OnReachedPosition", &GCMomentaryRotButton::GetOnReachedPosition, &GCMomentaryRotButton::SetOnReachedPosition)
        .addProperty("LastUsed", &GCMomentaryRotButton::GetLastUsed, &GCMomentaryRotButton::SetLastUsed)
        .addProperty("Start", &GCMomentaryRotButton::GetStart, &GCMomentaryRotButton::SetStart)
        .addProperty("End", &GCMomentaryRotButton::GetEnd, &GCMomentaryRotButton::SetEnd)
        .addProperty("IdealYaw", &GCMomentaryRotButton::GetIdealYaw, &GCMomentaryRotButton::SetIdealYaw)
        .addProperty("Noise", &GCMomentaryRotButton::GetNoise, &GCMomentaryRotButton::SetNoise)
        .addProperty("UpdateTarget", &GCMomentaryRotButton::GetUpdateTarget, &GCMomentaryRotButton::SetUpdateTarget)
        .addProperty("Direction", &GCMomentaryRotButton::GetDirection, &GCMomentaryRotButton::SetDirection)
        .addProperty("ReturnSpeed", &GCMomentaryRotButton::GetReturnSpeed, &GCMomentaryRotButton::SetReturnSpeed)
        .addProperty("StartPosition", &GCMomentaryRotButton::GetStartPosition, &GCMomentaryRotButton::SetStartPosition)
        .addProperty("Parent", &GCMomentaryRotButton::GetParent, &GCMomentaryRotButton::SetParent)
        .addFunction("ToPtr", &GCMomentaryRotButton::ToPtr)
        .addFunction("IsValid", &GCMomentaryRotButton::IsValid)
        .endClass();
}