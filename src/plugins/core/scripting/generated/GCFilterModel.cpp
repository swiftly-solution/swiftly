#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterModel::GCFilterModel(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterModel::GCFilterModel(void *ptr) {
    m_ptr = ptr;
}
std::string GCFilterModel::GetFilterModel() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterModel", "m_iFilterModel").String();
}
void GCFilterModel::SetFilterModel(std::string value) {
    SetSchemaValue(m_ptr, "CFilterModel", "m_iFilterModel", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFilterModel::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterModel::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterModel::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterModel::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterModel>("CFilterModel")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FilterModel", &GCFilterModel::GetFilterModel, &GCFilterModel::SetFilterModel)
        .addProperty("Parent", &GCFilterModel::GetParent, &GCFilterModel::SetParent)
        .addFunction("ToPtr", &GCFilterModel::ToPtr)
        .addFunction("IsValid", &GCFilterModel::IsValid)
        .endClass();
}