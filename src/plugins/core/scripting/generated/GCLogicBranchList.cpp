#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicBranchList::GCLogicBranchList(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicBranchList::GCLogicBranchList(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlSymbolLarge> GCLogicBranchList::GetLogicBranchNames() const {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CLogicBranchList", "m_nLogicBranchNames"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 16; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCLogicBranchList::SetLogicBranchNames(std::vector<CUtlSymbolLarge> value) {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CLogicBranchList", "m_nLogicBranchNames"); for(int i = 0; i < 16; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLogicBranchList", "m_nLogicBranchNames", false, outValue);
}
GCLogicBranchList GCLogicBranchList::GetLastState() const {
    GCLogicBranchList value(GetSchemaPtr(m_ptr, "CLogicBranchList", "m_eLastState"));
    return value;
}
void GCLogicBranchList::SetLastState(GCLogicBranchList value) {
    SetSchemaValue(m_ptr, "CLogicBranchList", "m_eLastState", false, value);
}
GCEntityIOOutput GCLogicBranchList::GetOnAllTrue() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicBranchList", "m_OnAllTrue"));
    return value;
}
void GCLogicBranchList::SetOnAllTrue(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicBranchList", "m_OnAllTrue", false, value);
}
GCEntityIOOutput GCLogicBranchList::GetOnAllFalse() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicBranchList", "m_OnAllFalse"));
    return value;
}
void GCLogicBranchList::SetOnAllFalse(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicBranchList", "m_OnAllFalse", false, value);
}
GCEntityIOOutput GCLogicBranchList::GetOnMixed() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicBranchList", "m_OnMixed"));
    return value;
}
void GCLogicBranchList::SetOnMixed(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicBranchList", "m_OnMixed", false, value);
}
std::string GCLogicBranchList::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicBranchList::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicBranchList::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicBranchList::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicBranchList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicBranchList>("CLogicBranchList")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LogicBranchNames", &GCLogicBranchList::GetLogicBranchNames, &GCLogicBranchList::SetLogicBranchNames)
        .addProperty("LastState", &GCLogicBranchList::GetLastState, &GCLogicBranchList::SetLastState)
        .addProperty("OnAllTrue", &GCLogicBranchList::GetOnAllTrue, &GCLogicBranchList::SetOnAllTrue)
        .addProperty("OnAllFalse", &GCLogicBranchList::GetOnAllFalse, &GCLogicBranchList::SetOnAllFalse)
        .addProperty("OnMixed", &GCLogicBranchList::GetOnMixed, &GCLogicBranchList::SetOnMixed)
        .addProperty("Parent", &GCLogicBranchList::GetParent, &GCLogicBranchList::SetParent)
        .addFunction("ToPtr", &GCLogicBranchList::ToPtr)
        .addFunction("IsValid", &GCLogicBranchList::IsValid)
        .endClass();
}