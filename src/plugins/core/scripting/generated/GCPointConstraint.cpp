#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointConstraint::GCPointConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointConstraint::GCPointConstraint(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseConstraint GCPointConstraint::GetParent() const {
    GCBaseConstraint value(m_ptr);
    return value;
}
void GCPointConstraint::SetParent(GCBaseConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointConstraint>("CPointConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPointConstraint::GetParent, &GCPointConstraint::SetParent)
        .addFunction("ToPtr", &GCPointConstraint::ToPtr)
        .addFunction("IsValid", &GCPointConstraint::IsValid)
        .endClass();
}