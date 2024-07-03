#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDSPPresetMixgroupModifierTable::GCDSPPresetMixgroupModifierTable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDSPPresetMixgroupModifierTable::GCDSPPresetMixgroupModifierTable(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCDspPresetModifierList> GCDSPPresetMixgroupModifierTable::GetTable() const {
    CUtlVector<GCDspPresetModifierList>* vec = GetSchemaValue<CUtlVector<GCDspPresetModifierList>*>(m_ptr, "CDSPPresetMixgroupModifierTable", "m_table"); std::vector<GCDspPresetModifierList> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCDSPPresetMixgroupModifierTable::SetTable(std::vector<GCDspPresetModifierList> value) {
    SetSchemaValueCUtlVector<GCDspPresetModifierList>(m_ptr, "CDSPPresetMixgroupModifierTable", "m_table", false, value);
}
std::string GCDSPPresetMixgroupModifierTable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDSPPresetMixgroupModifierTable::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCDSPPresetMixgroupModifierTable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDSPPresetMixgroupModifierTable>("CDSPPresetMixgroupModifierTable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Table", &GCDSPPresetMixgroupModifierTable::GetTable, &GCDSPPresetMixgroupModifierTable::SetTable)
        .addFunction("ToPtr", &GCDSPPresetMixgroupModifierTable::ToPtr)
        .addFunction("IsValid", &GCDSPPresetMixgroupModifierTable::IsValid)
        .endClass();
}