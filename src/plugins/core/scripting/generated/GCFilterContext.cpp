#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterContext::GCFilterContext(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterContext::GCFilterContext(void *ptr) {
    m_ptr = ptr;
}
std::string GCFilterContext::GetFilterContext() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterContext", "m_iFilterContext").String();
}
void GCFilterContext::SetFilterContext(std::string value) {
    SetSchemaValue(m_ptr, "CFilterContext", "m_iFilterContext", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFilterContext::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterContext::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterContext::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterContext::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterContext(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterContext>("CFilterContext")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FilterContext", &GCFilterContext::GetFilterContext, &GCFilterContext::SetFilterContext)
        .addProperty("Parent", &GCFilterContext::GetParent, &GCFilterContext::SetParent)
        .addFunction("ToPtr", &GCFilterContext::ToPtr)
        .addFunction("IsValid", &GCFilterContext::IsValid)
        .endClass();
}