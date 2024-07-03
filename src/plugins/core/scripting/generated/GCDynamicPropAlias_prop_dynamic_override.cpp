#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDynamicPropAlias_prop_dynamic_override::GCDynamicPropAlias_prop_dynamic_override(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDynamicPropAlias_prop_dynamic_override::GCDynamicPropAlias_prop_dynamic_override(void *ptr) {
    m_ptr = ptr;
}
std::string GCDynamicPropAlias_prop_dynamic_override::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDynamicPropAlias_prop_dynamic_override::IsValid() {
    return (m_ptr != nullptr);
}
GCDynamicProp GCDynamicPropAlias_prop_dynamic_override::GetParent() const {
    GCDynamicProp value(m_ptr);
    return value;
}
void GCDynamicPropAlias_prop_dynamic_override::SetParent(GCDynamicProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDynamicPropAlias_prop_dynamic_override(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicPropAlias_prop_dynamic_override>("CDynamicPropAlias_prop_dynamic_override")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCDynamicPropAlias_prop_dynamic_override::GetParent, &GCDynamicPropAlias_prop_dynamic_override::SetParent)
        .addFunction("ToPtr", &GCDynamicPropAlias_prop_dynamic_override::ToPtr)
        .addFunction("IsValid", &GCDynamicPropAlias_prop_dynamic_override::IsValid)
        .endClass();
}