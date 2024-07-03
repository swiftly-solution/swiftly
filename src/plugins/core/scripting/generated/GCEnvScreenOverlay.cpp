#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvScreenOverlay::GCEnvScreenOverlay(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvScreenOverlay::GCEnvScreenOverlay(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlSymbolLarge> GCEnvScreenOverlay::GetOverlayNames() const {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CEnvScreenOverlay", "m_iszOverlayNames"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCEnvScreenOverlay::SetOverlayNames(std::vector<CUtlSymbolLarge> value) {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CEnvScreenOverlay", "m_iszOverlayNames"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CEnvScreenOverlay", "m_iszOverlayNames", false, outValue);
}
std::vector<float> GCEnvScreenOverlay::GetOverlayTimes() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CEnvScreenOverlay", "m_flOverlayTimes"); std::vector<float> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCEnvScreenOverlay::SetOverlayTimes(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CEnvScreenOverlay", "m_flOverlayTimes"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CEnvScreenOverlay", "m_flOverlayTimes", false, outValue);
}
float GCEnvScreenOverlay::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvScreenOverlay", "m_flStartTime");
}
void GCEnvScreenOverlay::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CEnvScreenOverlay", "m_flStartTime", false, value);
}
int32_t GCEnvScreenOverlay::GetDesiredOverlay() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvScreenOverlay", "m_iDesiredOverlay");
}
void GCEnvScreenOverlay::SetDesiredOverlay(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvScreenOverlay", "m_iDesiredOverlay", false, value);
}
bool GCEnvScreenOverlay::GetIsActive() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvScreenOverlay", "m_bIsActive");
}
void GCEnvScreenOverlay::SetIsActive(bool value) {
    SetSchemaValue(m_ptr, "CEnvScreenOverlay", "m_bIsActive", false, value);
}
std::string GCEnvScreenOverlay::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvScreenOverlay::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvScreenOverlay::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvScreenOverlay::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvScreenOverlay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvScreenOverlay>("CEnvScreenOverlay")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OverlayNames", &GCEnvScreenOverlay::GetOverlayNames, &GCEnvScreenOverlay::SetOverlayNames)
        .addProperty("OverlayTimes", &GCEnvScreenOverlay::GetOverlayTimes, &GCEnvScreenOverlay::SetOverlayTimes)
        .addProperty("StartTime", &GCEnvScreenOverlay::GetStartTime, &GCEnvScreenOverlay::SetStartTime)
        .addProperty("DesiredOverlay", &GCEnvScreenOverlay::GetDesiredOverlay, &GCEnvScreenOverlay::SetDesiredOverlay)
        .addProperty("IsActive", &GCEnvScreenOverlay::GetIsActive, &GCEnvScreenOverlay::SetIsActive)
        .addProperty("Parent", &GCEnvScreenOverlay::GetParent, &GCEnvScreenOverlay::SetParent)
        .addFunction("ToPtr", &GCEnvScreenOverlay::ToPtr)
        .addFunction("IsValid", &GCEnvScreenOverlay::IsValid)
        .endClass();
}