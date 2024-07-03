#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAttributeContainer::GCAttributeContainer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAttributeContainer::GCAttributeContainer(void *ptr) {
    m_ptr = ptr;
}
GCEconItemView GCAttributeContainer::GetItem() const {
    GCEconItemView value(GetSchemaPtr(m_ptr, "CAttributeContainer", "m_Item"));
    return value;
}
void GCAttributeContainer::SetItem(GCEconItemView value) {
    SetSchemaValue(m_ptr, "CAttributeContainer", "m_Item", false, value);
}
std::string GCAttributeContainer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAttributeContainer::IsValid() {
    return (m_ptr != nullptr);
}
GCAttributeManager GCAttributeContainer::GetParent() const {
    GCAttributeManager value(m_ptr);
    return value;
}
void GCAttributeContainer::SetParent(GCAttributeManager value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAttributeContainer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttributeContainer>("CAttributeContainer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Item", &GCAttributeContainer::GetItem, &GCAttributeContainer::SetItem)
        .addProperty("Parent", &GCAttributeContainer::GetParent, &GCAttributeContainer::SetParent)
        .addFunction("ToPtr", &GCAttributeContainer::ToPtr)
        .addFunction("IsValid", &GCAttributeContainer::IsValid)
        .endClass();
}