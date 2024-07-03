#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterName::GCFilterName(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterName::GCFilterName(void *ptr) {
    m_ptr = ptr;
}
std::string GCFilterName::GetFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterName", "m_iFilterName").String();
}
void GCFilterName::SetFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CFilterName", "m_iFilterName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFilterName::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterName::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterName::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterName::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterName(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterName>("CFilterName")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FilterName", &GCFilterName::GetFilterName, &GCFilterName::SetFilterName)
        .addProperty("Parent", &GCFilterName::GetParent, &GCFilterName::SetParent)
        .addFunction("ToPtr", &GCFilterName::ToPtr)
        .addFunction("IsValid", &GCFilterName::IsValid)
        .endClass();
}