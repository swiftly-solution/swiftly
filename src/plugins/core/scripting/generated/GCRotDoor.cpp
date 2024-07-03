#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRotDoor::GCRotDoor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRotDoor::GCRotDoor(void *ptr) {
    m_ptr = ptr;
}
bool GCRotDoor::GetSolidBsp() const {
    return GetSchemaValue<bool>(m_ptr, "CRotDoor", "m_bSolidBsp");
}
void GCRotDoor::SetSolidBsp(bool value) {
    SetSchemaValue(m_ptr, "CRotDoor", "m_bSolidBsp", false, value);
}
std::string GCRotDoor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRotDoor::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseDoor GCRotDoor::GetParent() const {
    GCBaseDoor value(m_ptr);
    return value;
}
void GCRotDoor::SetParent(GCBaseDoor value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRotDoor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRotDoor>("CRotDoor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SolidBsp", &GCRotDoor::GetSolidBsp, &GCRotDoor::SetSolidBsp)
        .addProperty("Parent", &GCRotDoor::GetParent, &GCRotDoor::SetParent)
        .addFunction("ToPtr", &GCRotDoor::ToPtr)
        .addFunction("IsValid", &GCRotDoor::IsValid)
        .endClass();
}