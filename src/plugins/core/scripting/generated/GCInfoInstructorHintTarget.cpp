#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoInstructorHintTarget::GCInfoInstructorHintTarget(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoInstructorHintTarget::GCInfoInstructorHintTarget(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoInstructorHintTarget::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoInstructorHintTarget::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoInstructorHintTarget::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoInstructorHintTarget::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoInstructorHintTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoInstructorHintTarget>("CInfoInstructorHintTarget")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoInstructorHintTarget::GetParent, &GCInfoInstructorHintTarget::SetParent)
        .addFunction("ToPtr", &GCInfoInstructorHintTarget::ToPtr)
        .addFunction("IsValid", &GCInfoInstructorHintTarget::IsValid)
        .endClass();
}