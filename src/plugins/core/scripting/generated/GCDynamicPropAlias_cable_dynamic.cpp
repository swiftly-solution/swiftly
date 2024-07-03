#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDynamicPropAlias_cable_dynamic::GCDynamicPropAlias_cable_dynamic(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDynamicPropAlias_cable_dynamic::GCDynamicPropAlias_cable_dynamic(void *ptr) {
    m_ptr = ptr;
}
std::string GCDynamicPropAlias_cable_dynamic::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDynamicPropAlias_cable_dynamic::IsValid() {
    return (m_ptr != nullptr);
}
GCDynamicProp GCDynamicPropAlias_cable_dynamic::GetParent() const {
    GCDynamicProp value(m_ptr);
    return value;
}
void GCDynamicPropAlias_cable_dynamic::SetParent(GCDynamicProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDynamicPropAlias_cable_dynamic(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicPropAlias_cable_dynamic>("CDynamicPropAlias_cable_dynamic")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCDynamicPropAlias_cable_dynamic::GetParent, &GCDynamicPropAlias_cable_dynamic::SetParent)
        .addFunction("ToPtr", &GCDynamicPropAlias_cable_dynamic::ToPtr)
        .addFunction("IsValid", &GCDynamicPropAlias_cable_dynamic::IsValid)
        .endClass();
}