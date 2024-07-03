#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvDetailController::GCEnvDetailController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvDetailController::GCEnvDetailController(void *ptr) {
    m_ptr = ptr;
}
float GCEnvDetailController::GetFadeStartDist() const {
    return GetSchemaValue<float>(m_ptr, "CEnvDetailController", "m_flFadeStartDist");
}
void GCEnvDetailController::SetFadeStartDist(float value) {
    SetSchemaValue(m_ptr, "CEnvDetailController", "m_flFadeStartDist", false, value);
}
float GCEnvDetailController::GetFadeEndDist() const {
    return GetSchemaValue<float>(m_ptr, "CEnvDetailController", "m_flFadeEndDist");
}
void GCEnvDetailController::SetFadeEndDist(float value) {
    SetSchemaValue(m_ptr, "CEnvDetailController", "m_flFadeEndDist", false, value);
}
std::string GCEnvDetailController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvDetailController::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvDetailController::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvDetailController::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvDetailController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvDetailController>("CEnvDetailController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FadeStartDist", &GCEnvDetailController::GetFadeStartDist, &GCEnvDetailController::SetFadeStartDist)
        .addProperty("FadeEndDist", &GCEnvDetailController::GetFadeEndDist, &GCEnvDetailController::SetFadeEndDist)
        .addProperty("Parent", &GCEnvDetailController::GetParent, &GCEnvDetailController::SetParent)
        .addFunction("ToPtr", &GCEnvDetailController::ToPtr)
        .addFunction("IsValid", &GCEnvDetailController::IsValid)
        .endClass();
}