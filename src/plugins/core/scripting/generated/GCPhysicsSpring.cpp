#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysicsSpring::GCPhysicsSpring(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysicsSpring::GCPhysicsSpring(void *ptr) {
    m_ptr = ptr;
}
float GCPhysicsSpring::GetFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsSpring", "m_flFrequency");
}
void GCPhysicsSpring::SetFrequency(float value) {
    SetSchemaValue(m_ptr, "CPhysicsSpring", "m_flFrequency", false, value);
}
float GCPhysicsSpring::GetDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsSpring", "m_flDampingRatio");
}
void GCPhysicsSpring::SetDampingRatio(float value) {
    SetSchemaValue(m_ptr, "CPhysicsSpring", "m_flDampingRatio", false, value);
}
float GCPhysicsSpring::GetRestLength() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsSpring", "m_flRestLength");
}
void GCPhysicsSpring::SetRestLength(float value) {
    SetSchemaValue(m_ptr, "CPhysicsSpring", "m_flRestLength", false, value);
}
std::string GCPhysicsSpring::GetNameAttachStart() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysicsSpring", "m_nameAttachStart").String();
}
void GCPhysicsSpring::SetNameAttachStart(std::string value) {
    SetSchemaValue(m_ptr, "CPhysicsSpring", "m_nameAttachStart", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPhysicsSpring::GetNameAttachEnd() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysicsSpring", "m_nameAttachEnd").String();
}
void GCPhysicsSpring::SetNameAttachEnd(std::string value) {
    SetSchemaValue(m_ptr, "CPhysicsSpring", "m_nameAttachEnd", false, CUtlSymbolLarge(value.c_str()));
}
Vector GCPhysicsSpring::GetStart() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysicsSpring", "m_start");
}
void GCPhysicsSpring::SetStart(Vector value) {
    SetSchemaValue(m_ptr, "CPhysicsSpring", "m_start", false, value);
}
Vector GCPhysicsSpring::GetEnd() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysicsSpring", "m_end");
}
void GCPhysicsSpring::SetEnd(Vector value) {
    SetSchemaValue(m_ptr, "CPhysicsSpring", "m_end", false, value);
}
uint32_t GCPhysicsSpring::GetTeleportTick() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPhysicsSpring", "m_teleportTick");
}
void GCPhysicsSpring::SetTeleportTick(uint32_t value) {
    SetSchemaValue(m_ptr, "CPhysicsSpring", "m_teleportTick", false, value);
}
std::string GCPhysicsSpring::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysicsSpring::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPhysicsSpring::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPhysicsSpring::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysicsSpring(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsSpring>("CPhysicsSpring")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Frequency", &GCPhysicsSpring::GetFrequency, &GCPhysicsSpring::SetFrequency)
        .addProperty("DampingRatio", &GCPhysicsSpring::GetDampingRatio, &GCPhysicsSpring::SetDampingRatio)
        .addProperty("RestLength", &GCPhysicsSpring::GetRestLength, &GCPhysicsSpring::SetRestLength)
        .addProperty("NameAttachStart", &GCPhysicsSpring::GetNameAttachStart, &GCPhysicsSpring::SetNameAttachStart)
        .addProperty("NameAttachEnd", &GCPhysicsSpring::GetNameAttachEnd, &GCPhysicsSpring::SetNameAttachEnd)
        .addProperty("Start", &GCPhysicsSpring::GetStart, &GCPhysicsSpring::SetStart)
        .addProperty("End", &GCPhysicsSpring::GetEnd, &GCPhysicsSpring::SetEnd)
        .addProperty("TeleportTick", &GCPhysicsSpring::GetTeleportTick, &GCPhysicsSpring::SetTeleportTick)
        .addProperty("Parent", &GCPhysicsSpring::GetParent, &GCPhysicsSpring::SetParent)
        .addFunction("ToPtr", &GCPhysicsSpring::ToPtr)
        .addFunction("IsValid", &GCPhysicsSpring::IsValid)
        .endClass();
}