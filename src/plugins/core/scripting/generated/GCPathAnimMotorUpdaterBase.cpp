#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathAnimMotorUpdaterBase::GCPathAnimMotorUpdaterBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathAnimMotorUpdaterBase::GCPathAnimMotorUpdaterBase(void *ptr) {
    m_ptr = ptr;
}
bool GCPathAnimMotorUpdaterBase::GetLockToPath() const {
    return GetSchemaValue<bool>(m_ptr, "CPathAnimMotorUpdaterBase", "m_bLockToPath");
}
void GCPathAnimMotorUpdaterBase::SetLockToPath(bool value) {
    SetSchemaValue(m_ptr, "CPathAnimMotorUpdaterBase", "m_bLockToPath", false, value);
}
std::string GCPathAnimMotorUpdaterBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathAnimMotorUpdaterBase::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimMotorUpdaterBase GCPathAnimMotorUpdaterBase::GetParent() const {
    GCAnimMotorUpdaterBase value(m_ptr);
    return value;
}
void GCPathAnimMotorUpdaterBase::SetParent(GCAnimMotorUpdaterBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathAnimMotorUpdaterBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathAnimMotorUpdaterBase>("CPathAnimMotorUpdaterBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LockToPath", &GCPathAnimMotorUpdaterBase::GetLockToPath, &GCPathAnimMotorUpdaterBase::SetLockToPath)
        .addProperty("Parent", &GCPathAnimMotorUpdaterBase::GetParent, &GCPathAnimMotorUpdaterBase::SetParent)
        .addFunction("ToPtr", &GCPathAnimMotorUpdaterBase::ToPtr)
        .addFunction("IsValid", &GCPathAnimMotorUpdaterBase::IsValid)
        .endClass();
}