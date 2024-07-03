#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCOrientConstraint::GCOrientConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCOrientConstraint::GCOrientConstraint(void *ptr) {
    m_ptr = ptr;
}
std::string GCOrientConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCOrientConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseConstraint GCOrientConstraint::GetParent() const {
    GCBaseConstraint value(m_ptr);
    return value;
}
void GCOrientConstraint::SetParent(GCBaseConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCOrientConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCOrientConstraint>("COrientConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCOrientConstraint::GetParent, &GCOrientConstraint::SetParent)
        .addFunction("ToPtr", &GCOrientConstraint::ToPtr)
        .addFunction("IsValid", &GCOrientConstraint::IsValid)
        .endClass();
}