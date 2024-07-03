#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDampedValueComponentUpdater::GCDampedValueComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDampedValueComponentUpdater::GCDampedValueComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCDampedValueUpdateItem> GCDampedValueComponentUpdater::GetItems() const {
    CUtlVector<GCDampedValueUpdateItem>* vec = GetSchemaValue<CUtlVector<GCDampedValueUpdateItem>*>(m_ptr, "CDampedValueComponentUpdater", "m_items"); std::vector<GCDampedValueUpdateItem> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCDampedValueComponentUpdater::SetItems(std::vector<GCDampedValueUpdateItem> value) {
    SetSchemaValueCUtlVector<GCDampedValueUpdateItem>(m_ptr, "CDampedValueComponentUpdater", "m_items", false, value);
}
std::string GCDampedValueComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDampedValueComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCDampedValueComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCDampedValueComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDampedValueComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDampedValueComponentUpdater>("CDampedValueComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Items", &GCDampedValueComponentUpdater::GetItems, &GCDampedValueComponentUpdater::SetItems)
        .addProperty("Parent", &GCDampedValueComponentUpdater::GetParent, &GCDampedValueComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCDampedValueComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCDampedValueComponentUpdater::IsValid)
        .endClass();
}