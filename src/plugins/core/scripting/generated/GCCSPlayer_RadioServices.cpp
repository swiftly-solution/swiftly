#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_RadioServices::GCCSPlayer_RadioServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_RadioServices::GCCSPlayer_RadioServices(void *ptr) {
    m_ptr = ptr;
}
float GCCSPlayer_RadioServices::GetGotHostageTalkTimer() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_RadioServices", "m_flGotHostageTalkTimer");
}
void GCCSPlayer_RadioServices::SetGotHostageTalkTimer(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_RadioServices", "m_flGotHostageTalkTimer", false, value);
}
float GCCSPlayer_RadioServices::GetDefusingTalkTimer() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_RadioServices", "m_flDefusingTalkTimer");
}
void GCCSPlayer_RadioServices::SetDefusingTalkTimer(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_RadioServices", "m_flDefusingTalkTimer", false, value);
}
float GCCSPlayer_RadioServices::GetC4PlantTalkTimer() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayer_RadioServices", "m_flC4PlantTalkTimer");
}
void GCCSPlayer_RadioServices::SetC4PlantTalkTimer(float value) {
    SetSchemaValue(m_ptr, "CCSPlayer_RadioServices", "m_flC4PlantTalkTimer", false, value);
}
std::vector<float> GCCSPlayer_RadioServices::GetRadioTokenSlots() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSPlayer_RadioServices", "m_flRadioTokenSlots"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayer_RadioServices::SetRadioTokenSlots(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CCSPlayer_RadioServices", "m_flRadioTokenSlots"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayer_RadioServices", "m_flRadioTokenSlots", false, outValue);
}
bool GCCSPlayer_RadioServices::GetIgnoreRadio() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayer_RadioServices", "m_bIgnoreRadio");
}
void GCCSPlayer_RadioServices::SetIgnoreRadio(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayer_RadioServices", "m_bIgnoreRadio", false, value);
}
std::string GCCSPlayer_RadioServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_RadioServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCCSPlayer_RadioServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCCSPlayer_RadioServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_RadioServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_RadioServices>("CCSPlayer_RadioServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GotHostageTalkTimer", &GCCSPlayer_RadioServices::GetGotHostageTalkTimer, &GCCSPlayer_RadioServices::SetGotHostageTalkTimer)
        .addProperty("DefusingTalkTimer", &GCCSPlayer_RadioServices::GetDefusingTalkTimer, &GCCSPlayer_RadioServices::SetDefusingTalkTimer)
        .addProperty("C4PlantTalkTimer", &GCCSPlayer_RadioServices::GetC4PlantTalkTimer, &GCCSPlayer_RadioServices::SetC4PlantTalkTimer)
        .addProperty("RadioTokenSlots", &GCCSPlayer_RadioServices::GetRadioTokenSlots, &GCCSPlayer_RadioServices::SetRadioTokenSlots)
        .addProperty("IgnoreRadio", &GCCSPlayer_RadioServices::GetIgnoreRadio, &GCCSPlayer_RadioServices::SetIgnoreRadio)
        .addProperty("Parent", &GCCSPlayer_RadioServices::GetParent, &GCCSPlayer_RadioServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_RadioServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_RadioServices::IsValid)
        .endClass();
}