#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoInstructorHintHostageRescueZone::GCInfoInstructorHintHostageRescueZone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoInstructorHintHostageRescueZone::GCInfoInstructorHintHostageRescueZone(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoInstructorHintHostageRescueZone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoInstructorHintHostageRescueZone::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoInstructorHintHostageRescueZone::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoInstructorHintHostageRescueZone::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoInstructorHintHostageRescueZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoInstructorHintHostageRescueZone>("CInfoInstructorHintHostageRescueZone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoInstructorHintHostageRescueZone::GetParent, &GCInfoInstructorHintHostageRescueZone::SetParent)
        .addFunction("ToPtr", &GCInfoInstructorHintHostageRescueZone::ToPtr)
        .addFunction("IsValid", &GCInfoInstructorHintHostageRescueZone::IsValid)
        .endClass();
}