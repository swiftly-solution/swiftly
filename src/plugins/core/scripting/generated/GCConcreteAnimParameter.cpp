#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCConcreteAnimParameter::GCConcreteAnimParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCConcreteAnimParameter::GCConcreteAnimParameter(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCConcreteAnimParameter::GetPreviewButton() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CConcreteAnimParameter", "m_previewButton");
}
void GCConcreteAnimParameter::SetPreviewButton(uint64_t value) {
    SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_previewButton", false, value);
}
uint64_t GCConcreteAnimParameter::GetNetworkSetting() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CConcreteAnimParameter", "m_eNetworkSetting");
}
void GCConcreteAnimParameter::SetNetworkSetting(uint64_t value) {
    SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_eNetworkSetting", false, value);
}
bool GCConcreteAnimParameter::GetUseMostRecentValue() const {
    return GetSchemaValue<bool>(m_ptr, "CConcreteAnimParameter", "m_bUseMostRecentValue");
}
void GCConcreteAnimParameter::SetUseMostRecentValue(bool value) {
    SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_bUseMostRecentValue", false, value);
}
bool GCConcreteAnimParameter::GetAutoReset() const {
    return GetSchemaValue<bool>(m_ptr, "CConcreteAnimParameter", "m_bAutoReset");
}
void GCConcreteAnimParameter::SetAutoReset(bool value) {
    SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_bAutoReset", false, value);
}
bool GCConcreteAnimParameter::GetGameWritable() const {
    return GetSchemaValue<bool>(m_ptr, "CConcreteAnimParameter", "m_bGameWritable");
}
void GCConcreteAnimParameter::SetGameWritable(bool value) {
    SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_bGameWritable", false, value);
}
bool GCConcreteAnimParameter::GetGraphWritable() const {
    return GetSchemaValue<bool>(m_ptr, "CConcreteAnimParameter", "m_bGraphWritable");
}
void GCConcreteAnimParameter::SetGraphWritable(bool value) {
    SetSchemaValue(m_ptr, "CConcreteAnimParameter", "m_bGraphWritable", false, value);
}
std::string GCConcreteAnimParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCConcreteAnimParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimParameterBase GCConcreteAnimParameter::GetParent() const {
    GCAnimParameterBase value(m_ptr);
    return value;
}
void GCConcreteAnimParameter::SetParent(GCAnimParameterBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCConcreteAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConcreteAnimParameter>("CConcreteAnimParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PreviewButton", &GCConcreteAnimParameter::GetPreviewButton, &GCConcreteAnimParameter::SetPreviewButton)
        .addProperty("NetworkSetting", &GCConcreteAnimParameter::GetNetworkSetting, &GCConcreteAnimParameter::SetNetworkSetting)
        .addProperty("UseMostRecentValue", &GCConcreteAnimParameter::GetUseMostRecentValue, &GCConcreteAnimParameter::SetUseMostRecentValue)
        .addProperty("AutoReset", &GCConcreteAnimParameter::GetAutoReset, &GCConcreteAnimParameter::SetAutoReset)
        .addProperty("GameWritable", &GCConcreteAnimParameter::GetGameWritable, &GCConcreteAnimParameter::SetGameWritable)
        .addProperty("GraphWritable", &GCConcreteAnimParameter::GetGraphWritable, &GCConcreteAnimParameter::SetGraphWritable)
        .addProperty("Parent", &GCConcreteAnimParameter::GetParent, &GCConcreteAnimParameter::SetParent)
        .addFunction("ToPtr", &GCConcreteAnimParameter::ToPtr)
        .addFunction("IsValid", &GCConcreteAnimParameter::IsValid)
        .endClass();
}