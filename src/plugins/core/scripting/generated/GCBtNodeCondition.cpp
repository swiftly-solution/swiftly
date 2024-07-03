#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBtNodeCondition::GCBtNodeCondition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBtNodeCondition::GCBtNodeCondition(void *ptr) {
    m_ptr = ptr;
}
bool GCBtNodeCondition::GetNegated() const {
    return GetSchemaValue<bool>(m_ptr, "CBtNodeCondition", "m_bNegated");
}
void GCBtNodeCondition::SetNegated(bool value) {
    SetSchemaValue(m_ptr, "CBtNodeCondition", "m_bNegated", false, value);
}
std::string GCBtNodeCondition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBtNodeCondition::IsValid() {
    return (m_ptr != nullptr);
}
GCBtNodeDecorator GCBtNodeCondition::GetParent() const {
    GCBtNodeDecorator value(m_ptr);
    return value;
}
void GCBtNodeCondition::SetParent(GCBtNodeDecorator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBtNodeCondition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNodeCondition>("CBtNodeCondition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Negated", &GCBtNodeCondition::GetNegated, &GCBtNodeCondition::SetNegated)
        .addProperty("Parent", &GCBtNodeCondition::GetParent, &GCBtNodeCondition::SetParent)
        .addFunction("ToPtr", &GCBtNodeCondition::ToPtr)
        .addFunction("IsValid", &GCBtNodeCondition::IsValid)
        .endClass();
}