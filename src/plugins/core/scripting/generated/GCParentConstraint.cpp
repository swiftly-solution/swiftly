#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParentConstraint::GCParentConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParentConstraint::GCParentConstraint(void *ptr) {
    m_ptr = ptr;
}
std::string GCParentConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParentConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseConstraint GCParentConstraint::GetParent() const {
    GCBaseConstraint value(m_ptr);
    return value;
}
void GCParentConstraint::SetParent(GCBaseConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParentConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParentConstraint>("CParentConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCParentConstraint::GetParent, &GCParentConstraint::SetParent)
        .addFunction("ToPtr", &GCParentConstraint::ToPtr)
        .addFunction("IsValid", &GCParentConstraint::IsValid)
        .endClass();
}