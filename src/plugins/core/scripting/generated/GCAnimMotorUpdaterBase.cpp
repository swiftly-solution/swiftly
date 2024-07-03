#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimMotorUpdaterBase::GCAnimMotorUpdaterBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimMotorUpdaterBase::GCAnimMotorUpdaterBase(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimMotorUpdaterBase::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimMotorUpdaterBase", "m_name").Get();
}
void GCAnimMotorUpdaterBase::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CAnimMotorUpdaterBase", "m_name", false, CUtlString(value.c_str()));
}
bool GCAnimMotorUpdaterBase::GetDefault() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimMotorUpdaterBase", "m_bDefault");
}
void GCAnimMotorUpdaterBase::SetDefault(bool value) {
    SetSchemaValue(m_ptr, "CAnimMotorUpdaterBase", "m_bDefault", false, value);
}
std::string GCAnimMotorUpdaterBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimMotorUpdaterBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimMotorUpdaterBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimMotorUpdaterBase>("CAnimMotorUpdaterBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimMotorUpdaterBase::GetName, &GCAnimMotorUpdaterBase::SetName)
        .addProperty("Default", &GCAnimMotorUpdaterBase::GetDefault, &GCAnimMotorUpdaterBase::SetDefault)
        .addFunction("ToPtr", &GCAnimMotorUpdaterBase::ToPtr)
        .addFunction("IsValid", &GCAnimMotorUpdaterBase::IsValid)
        .endClass();
}