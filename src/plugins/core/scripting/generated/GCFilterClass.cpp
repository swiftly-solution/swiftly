#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterClass::GCFilterClass(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterClass::GCFilterClass(void *ptr) {
    m_ptr = ptr;
}
std::string GCFilterClass::GetFilterClass() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterClass", "m_iFilterClass").String();
}
void GCFilterClass::SetFilterClass(std::string value) {
    SetSchemaValue(m_ptr, "CFilterClass", "m_iFilterClass", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFilterClass::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterClass::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterClass::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterClass::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterClass(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterClass>("CFilterClass")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FilterClass", &GCFilterClass::GetFilterClass, &GCFilterClass::SetFilterClass)
        .addProperty("Parent", &GCFilterClass::GetParent, &GCFilterClass::SetParent)
        .addFunction("ToPtr", &GCFilterClass::ToPtr)
        .addFunction("IsValid", &GCFilterClass::IsValid)
        .endClass();
}