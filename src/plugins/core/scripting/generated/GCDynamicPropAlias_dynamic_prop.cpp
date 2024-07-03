#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDynamicPropAlias_dynamic_prop::GCDynamicPropAlias_dynamic_prop(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDynamicPropAlias_dynamic_prop::GCDynamicPropAlias_dynamic_prop(void *ptr) {
    m_ptr = ptr;
}
std::string GCDynamicPropAlias_dynamic_prop::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDynamicPropAlias_dynamic_prop::IsValid() {
    return (m_ptr != nullptr);
}
GCDynamicProp GCDynamicPropAlias_dynamic_prop::GetParent() const {
    GCDynamicProp value(m_ptr);
    return value;
}
void GCDynamicPropAlias_dynamic_prop::SetParent(GCDynamicProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDynamicPropAlias_dynamic_prop(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicPropAlias_dynamic_prop>("CDynamicPropAlias_dynamic_prop")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCDynamicPropAlias_dynamic_prop::GetParent, &GCDynamicPropAlias_dynamic_prop::SetParent)
        .addFunction("ToPtr", &GCDynamicPropAlias_dynamic_prop::ToPtr)
        .addFunction("IsValid", &GCDynamicPropAlias_dynamic_prop::IsValid)
        .endClass();
}