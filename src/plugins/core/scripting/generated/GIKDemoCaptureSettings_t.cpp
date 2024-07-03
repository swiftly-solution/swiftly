#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIKDemoCaptureSettings_t::GIKDemoCaptureSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIKDemoCaptureSettings_t::GIKDemoCaptureSettings_t(void *ptr) {
    m_ptr = ptr;
}
std::string GIKDemoCaptureSettings_t::GetParentBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "IKDemoCaptureSettings_t", "m_parentBoneName").Get();
}
void GIKDemoCaptureSettings_t::SetParentBoneName(std::string value) {
    SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_parentBoneName", true, CUtlString(value.c_str()));
}
uint64_t GIKDemoCaptureSettings_t::GetMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "IKDemoCaptureSettings_t", "m_eMode");
}
void GIKDemoCaptureSettings_t::SetMode(uint64_t value) {
    SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_eMode", true, value);
}
std::string GIKDemoCaptureSettings_t::GetIkChainName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "IKDemoCaptureSettings_t", "m_ikChainName").Get();
}
void GIKDemoCaptureSettings_t::SetIkChainName(std::string value) {
    SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_ikChainName", true, CUtlString(value.c_str()));
}
std::string GIKDemoCaptureSettings_t::GetOneBoneStart() const {
    return GetSchemaValue<CUtlString>(m_ptr, "IKDemoCaptureSettings_t", "m_oneBoneStart").Get();
}
void GIKDemoCaptureSettings_t::SetOneBoneStart(std::string value) {
    SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_oneBoneStart", true, CUtlString(value.c_str()));
}
std::string GIKDemoCaptureSettings_t::GetOneBoneEnd() const {
    return GetSchemaValue<CUtlString>(m_ptr, "IKDemoCaptureSettings_t", "m_oneBoneEnd").Get();
}
void GIKDemoCaptureSettings_t::SetOneBoneEnd(std::string value) {
    SetSchemaValue(m_ptr, "IKDemoCaptureSettings_t", "m_oneBoneEnd", true, CUtlString(value.c_str()));
}
std::string GIKDemoCaptureSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIKDemoCaptureSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIKDemoCaptureSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIKDemoCaptureSettings_t>("IKDemoCaptureSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParentBoneName", &GIKDemoCaptureSettings_t::GetParentBoneName, &GIKDemoCaptureSettings_t::SetParentBoneName)
        .addProperty("Mode", &GIKDemoCaptureSettings_t::GetMode, &GIKDemoCaptureSettings_t::SetMode)
        .addProperty("IkChainName", &GIKDemoCaptureSettings_t::GetIkChainName, &GIKDemoCaptureSettings_t::SetIkChainName)
        .addProperty("OneBoneStart", &GIKDemoCaptureSettings_t::GetOneBoneStart, &GIKDemoCaptureSettings_t::SetOneBoneStart)
        .addProperty("OneBoneEnd", &GIKDemoCaptureSettings_t::GetOneBoneEnd, &GIKDemoCaptureSettings_t::SetOneBoneEnd)
        .addFunction("ToPtr", &GIKDemoCaptureSettings_t::ToPtr)
        .addFunction("IsValid", &GIKDemoCaptureSettings_t::IsValid)
        .endClass();
}