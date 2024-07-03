#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCOrnamentProp::GCOrnamentProp(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCOrnamentProp::GCOrnamentProp(void *ptr) {
    m_ptr = ptr;
}
std::string GCOrnamentProp::GetInitialOwner() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "COrnamentProp", "m_initialOwner").String();
}
void GCOrnamentProp::SetInitialOwner(std::string value) {
    SetSchemaValue(m_ptr, "COrnamentProp", "m_initialOwner", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCOrnamentProp::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCOrnamentProp::IsValid() {
    return (m_ptr != nullptr);
}
GCDynamicProp GCOrnamentProp::GetParent() const {
    GCDynamicProp value(m_ptr);
    return value;
}
void GCOrnamentProp::SetParent(GCDynamicProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCOrnamentProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCOrnamentProp>("COrnamentProp")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InitialOwner", &GCOrnamentProp::GetInitialOwner, &GCOrnamentProp::SetInitialOwner)
        .addProperty("Parent", &GCOrnamentProp::GetParent, &GCOrnamentProp::SetParent)
        .addFunction("ToPtr", &GCOrnamentProp::ToPtr)
        .addFunction("IsValid", &GCOrnamentProp::IsValid)
        .endClass();
}