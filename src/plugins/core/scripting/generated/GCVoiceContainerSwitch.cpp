#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerSwitch::GCVoiceContainerSwitch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerSwitch::GCVoiceContainerSwitch(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCVoiceContainerBase*> GCVoiceContainerSwitch::GetSoundsToPlay() const {
    CUtlVector<GCVoiceContainerBase*>* vec = GetSchemaValue<CUtlVector<GCVoiceContainerBase*>*>(m_ptr, "CVoiceContainerSwitch", "m_soundsToPlay"); std::vector<GCVoiceContainerBase*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCVoiceContainerSwitch::SetSoundsToPlay(std::vector<GCVoiceContainerBase*> value) {
    SetSchemaValueCUtlVector<GCVoiceContainerBase*>(m_ptr, "CVoiceContainerSwitch", "m_soundsToPlay", false, value);
}
std::string GCVoiceContainerSwitch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerSwitch::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerBase GCVoiceContainerSwitch::GetParent() const {
    GCVoiceContainerBase value(m_ptr);
    return value;
}
void GCVoiceContainerSwitch::SetParent(GCVoiceContainerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerSwitch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerSwitch>("CVoiceContainerSwitch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SoundsToPlay", &GCVoiceContainerSwitch::GetSoundsToPlay, &GCVoiceContainerSwitch::SetSoundsToPlay)
        .addProperty("Parent", &GCVoiceContainerSwitch::GetParent, &GCVoiceContainerSwitch::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerSwitch::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerSwitch::IsValid)
        .endClass();
}