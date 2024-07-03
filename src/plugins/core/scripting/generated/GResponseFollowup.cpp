#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GResponseFollowup::GResponseFollowup(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GResponseFollowup::GResponseFollowup(void *ptr) {
    m_ptr = ptr;
}
std::string GResponseFollowup::GetFollowup_concept() const {
    return GetSchemaValuePtr<char>(m_ptr, "ResponseFollowup", "followup_concept");
}
void GResponseFollowup::SetFollowup_concept(std::string value) {
    WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_concept", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
std::string GResponseFollowup::GetFollowup_contexts() const {
    return GetSchemaValuePtr<char>(m_ptr, "ResponseFollowup", "followup_contexts");
}
void GResponseFollowup::SetFollowup_contexts(std::string value) {
    WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_contexts", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
float GResponseFollowup::GetFollowup_delay() const {
    return GetSchemaValue<float>(m_ptr, "ResponseFollowup", "followup_delay");
}
void GResponseFollowup::SetFollowup_delay(float value) {
    SetSchemaValue(m_ptr, "ResponseFollowup", "followup_delay", false, value);
}
std::string GResponseFollowup::GetFollowup_target() const {
    return GetSchemaValuePtr<char>(m_ptr, "ResponseFollowup", "followup_target");
}
void GResponseFollowup::SetFollowup_target(std::string value) {
    WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_target", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
std::string GResponseFollowup::GetFollowup_entityiotarget() const {
    return GetSchemaValuePtr<char>(m_ptr, "ResponseFollowup", "followup_entityiotarget");
}
void GResponseFollowup::SetFollowup_entityiotarget(std::string value) {
    WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_entityiotarget", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
std::string GResponseFollowup::GetFollowup_entityioinput() const {
    return GetSchemaValuePtr<char>(m_ptr, "ResponseFollowup", "followup_entityioinput");
}
void GResponseFollowup::SetFollowup_entityioinput(std::string value) {
    WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_entityioinput", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
float GResponseFollowup::GetFollowup_entityiodelay() const {
    return GetSchemaValue<float>(m_ptr, "ResponseFollowup", "followup_entityiodelay");
}
void GResponseFollowup::SetFollowup_entityiodelay(float value) {
    SetSchemaValue(m_ptr, "ResponseFollowup", "followup_entityiodelay", false, value);
}
bool GResponseFollowup::GetFired() const {
    return GetSchemaValue<bool>(m_ptr, "ResponseFollowup", "bFired");
}
void GResponseFollowup::SetFired(bool value) {
    SetSchemaValue(m_ptr, "ResponseFollowup", "bFired", false, value);
}
std::string GResponseFollowup::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GResponseFollowup::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassResponseFollowup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GResponseFollowup>("ResponseFollowup")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Followup_concept", &GResponseFollowup::GetFollowup_concept, &GResponseFollowup::SetFollowup_concept)
        .addProperty("Followup_contexts", &GResponseFollowup::GetFollowup_contexts, &GResponseFollowup::SetFollowup_contexts)
        .addProperty("Followup_delay", &GResponseFollowup::GetFollowup_delay, &GResponseFollowup::SetFollowup_delay)
        .addProperty("Followup_target", &GResponseFollowup::GetFollowup_target, &GResponseFollowup::SetFollowup_target)
        .addProperty("Followup_entityiotarget", &GResponseFollowup::GetFollowup_entityiotarget, &GResponseFollowup::SetFollowup_entityiotarget)
        .addProperty("Followup_entityioinput", &GResponseFollowup::GetFollowup_entityioinput, &GResponseFollowup::SetFollowup_entityioinput)
        .addProperty("Followup_entityiodelay", &GResponseFollowup::GetFollowup_entityiodelay, &GResponseFollowup::SetFollowup_entityiodelay)
        .addProperty("Fired", &GResponseFollowup::GetFired, &GResponseFollowup::SetFired)
        .addFunction("ToPtr", &GResponseFollowup::ToPtr)
        .addFunction("IsValid", &GResponseFollowup::IsValid)
        .endClass();
}