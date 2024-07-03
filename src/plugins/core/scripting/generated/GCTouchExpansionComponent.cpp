#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTouchExpansionComponent::GCTouchExpansionComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTouchExpansionComponent::GCTouchExpansionComponent(void *ptr) {
    m_ptr = ptr;
}
std::string GCTouchExpansionComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTouchExpansionComponent::IsValid() {
    return (m_ptr != nullptr);
}
GCEntityComponent GCTouchExpansionComponent::GetParent() const {
    GCEntityComponent value(m_ptr);
    return value;
}
void GCTouchExpansionComponent::SetParent(GCEntityComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTouchExpansionComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTouchExpansionComponent>("CTouchExpansionComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTouchExpansionComponent::GetParent, &GCTouchExpansionComponent::SetParent)
        .addFunction("ToPtr", &GCTouchExpansionComponent::ToPtr)
        .addFunction("IsValid", &GCTouchExpansionComponent::IsValid)
        .endClass();
}