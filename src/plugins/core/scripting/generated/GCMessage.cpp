#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMessage::GCMessage(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMessage::GCMessage(void *ptr) {
    m_ptr = ptr;
}
std::string GCMessage::GetMessage() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMessage", "m_iszMessage").String();
}
void GCMessage::SetMessage(std::string value) {
    SetSchemaValue(m_ptr, "CMessage", "m_iszMessage", false, CUtlSymbolLarge(value.c_str()));
}
float GCMessage::GetMessageVolume() const {
    return GetSchemaValue<float>(m_ptr, "CMessage", "m_MessageVolume");
}
void GCMessage::SetMessageVolume(float value) {
    SetSchemaValue(m_ptr, "CMessage", "m_MessageVolume", false, value);
}
int32_t GCMessage::GetMessageAttenuation() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMessage", "m_MessageAttenuation");
}
void GCMessage::SetMessageAttenuation(int32_t value) {
    SetSchemaValue(m_ptr, "CMessage", "m_MessageAttenuation", false, value);
}
float GCMessage::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CMessage", "m_Radius");
}
void GCMessage::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CMessage", "m_Radius", false, value);
}
std::string GCMessage::GetNoise() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMessage", "m_sNoise").String();
}
void GCMessage::SetNoise(std::string value) {
    SetSchemaValue(m_ptr, "CMessage", "m_sNoise", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCMessage::GetOnShowMessage() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMessage", "m_OnShowMessage"));
    return value;
}
void GCMessage::SetOnShowMessage(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMessage", "m_OnShowMessage", false, value);
}
std::string GCMessage::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMessage::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCMessage::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCMessage::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMessage(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMessage>("CMessage")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Message", &GCMessage::GetMessage, &GCMessage::SetMessage)
        .addProperty("MessageVolume", &GCMessage::GetMessageVolume, &GCMessage::SetMessageVolume)
        .addProperty("MessageAttenuation", &GCMessage::GetMessageAttenuation, &GCMessage::SetMessageAttenuation)
        .addProperty("Radius", &GCMessage::GetRadius, &GCMessage::SetRadius)
        .addProperty("Noise", &GCMessage::GetNoise, &GCMessage::SetNoise)
        .addProperty("OnShowMessage", &GCMessage::GetOnShowMessage, &GCMessage::SetOnShowMessage)
        .addProperty("Parent", &GCMessage::GetParent, &GCMessage::SetParent)
        .addFunction("ToPtr", &GCMessage::ToPtr)
        .addFunction("IsValid", &GCMessage::IsValid)
        .endClass();
}