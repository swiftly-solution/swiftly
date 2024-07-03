#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysSurfaceProperties::GCPhysSurfaceProperties(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysSurfaceProperties::GCPhysSurfaceProperties(void *ptr) {
    m_ptr = ptr;
}
std::string GCPhysSurfaceProperties::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfaceProperties", "m_name").Get();
}
void GCPhysSurfaceProperties::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_name", false, CUtlString(value.c_str()));
}
uint32_t GCPhysSurfaceProperties::GetNameHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPhysSurfaceProperties", "m_nameHash");
}
void GCPhysSurfaceProperties::SetNameHash(uint32_t value) {
    SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_nameHash", false, value);
}
uint32_t GCPhysSurfaceProperties::GetBaseNameHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPhysSurfaceProperties", "m_baseNameHash");
}
void GCPhysSurfaceProperties::SetBaseNameHash(uint32_t value) {
    SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_baseNameHash", false, value);
}
bool GCPhysSurfaceProperties::GetHidden() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysSurfaceProperties", "m_bHidden");
}
void GCPhysSurfaceProperties::SetHidden(bool value) {
    SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_bHidden", false, value);
}
std::string GCPhysSurfaceProperties::GetDescription() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPhysSurfaceProperties", "m_description").Get();
}
void GCPhysSurfaceProperties::SetDescription(std::string value) {
    SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_description", false, CUtlString(value.c_str()));
}
GCPhysSurfacePropertiesPhysics GCPhysSurfaceProperties::GetPhysics() const {
    GCPhysSurfacePropertiesPhysics value(GetSchemaPtr(m_ptr, "CPhysSurfaceProperties", "m_physics"));
    return value;
}
void GCPhysSurfaceProperties::SetPhysics(GCPhysSurfacePropertiesPhysics value) {
    SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_physics", false, value);
}
GCPhysSurfacePropertiesSoundNames GCPhysSurfaceProperties::GetAudioSounds() const {
    GCPhysSurfacePropertiesSoundNames value(GetSchemaPtr(m_ptr, "CPhysSurfaceProperties", "m_audioSounds"));
    return value;
}
void GCPhysSurfaceProperties::SetAudioSounds(GCPhysSurfacePropertiesSoundNames value) {
    SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_audioSounds", false, value);
}
GCPhysSurfacePropertiesAudio GCPhysSurfaceProperties::GetAudioParams() const {
    GCPhysSurfacePropertiesAudio value(GetSchemaPtr(m_ptr, "CPhysSurfaceProperties", "m_audioParams"));
    return value;
}
void GCPhysSurfaceProperties::SetAudioParams(GCPhysSurfacePropertiesAudio value) {
    SetSchemaValue(m_ptr, "CPhysSurfaceProperties", "m_audioParams", false, value);
}
std::string GCPhysSurfaceProperties::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysSurfaceProperties::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPhysSurfaceProperties(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSurfaceProperties>("CPhysSurfaceProperties")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCPhysSurfaceProperties::GetName, &GCPhysSurfaceProperties::SetName)
        .addProperty("NameHash", &GCPhysSurfaceProperties::GetNameHash, &GCPhysSurfaceProperties::SetNameHash)
        .addProperty("BaseNameHash", &GCPhysSurfaceProperties::GetBaseNameHash, &GCPhysSurfaceProperties::SetBaseNameHash)
        .addProperty("Hidden", &GCPhysSurfaceProperties::GetHidden, &GCPhysSurfaceProperties::SetHidden)
        .addProperty("Description", &GCPhysSurfaceProperties::GetDescription, &GCPhysSurfaceProperties::SetDescription)
        .addProperty("Physics", &GCPhysSurfaceProperties::GetPhysics, &GCPhysSurfaceProperties::SetPhysics)
        .addProperty("AudioSounds", &GCPhysSurfaceProperties::GetAudioSounds, &GCPhysSurfaceProperties::SetAudioSounds)
        .addProperty("AudioParams", &GCPhysSurfaceProperties::GetAudioParams, &GCPhysSurfaceProperties::SetAudioParams)
        .addFunction("ToPtr", &GCPhysSurfaceProperties::ToPtr)
        .addFunction("IsValid", &GCPhysSurfaceProperties::IsValid)
        .endClass();
}