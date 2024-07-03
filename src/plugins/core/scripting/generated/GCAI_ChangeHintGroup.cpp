#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAI_ChangeHintGroup::GCAI_ChangeHintGroup(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAI_ChangeHintGroup::GCAI_ChangeHintGroup(void *ptr) {
    m_ptr = ptr;
}
int32_t GCAI_ChangeHintGroup::GetSearchType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAI_ChangeHintGroup", "m_iSearchType");
}
void GCAI_ChangeHintGroup::SetSearchType(int32_t value) {
    SetSchemaValue(m_ptr, "CAI_ChangeHintGroup", "m_iSearchType", false, value);
}
std::string GCAI_ChangeHintGroup::GetStrSearchName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAI_ChangeHintGroup", "m_strSearchName").String();
}
void GCAI_ChangeHintGroup::SetStrSearchName(std::string value) {
    SetSchemaValue(m_ptr, "CAI_ChangeHintGroup", "m_strSearchName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCAI_ChangeHintGroup::GetStrNewHintGroup() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAI_ChangeHintGroup", "m_strNewHintGroup").String();
}
void GCAI_ChangeHintGroup::SetStrNewHintGroup(std::string value) {
    SetSchemaValue(m_ptr, "CAI_ChangeHintGroup", "m_strNewHintGroup", false, CUtlSymbolLarge(value.c_str()));
}
float GCAI_ChangeHintGroup::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CAI_ChangeHintGroup", "m_flRadius");
}
void GCAI_ChangeHintGroup::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CAI_ChangeHintGroup", "m_flRadius", false, value);
}
std::string GCAI_ChangeHintGroup::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAI_ChangeHintGroup::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCAI_ChangeHintGroup::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCAI_ChangeHintGroup::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAI_ChangeHintGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAI_ChangeHintGroup>("CAI_ChangeHintGroup")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SearchType", &GCAI_ChangeHintGroup::GetSearchType, &GCAI_ChangeHintGroup::SetSearchType)
        .addProperty("StrSearchName", &GCAI_ChangeHintGroup::GetStrSearchName, &GCAI_ChangeHintGroup::SetStrSearchName)
        .addProperty("StrNewHintGroup", &GCAI_ChangeHintGroup::GetStrNewHintGroup, &GCAI_ChangeHintGroup::SetStrNewHintGroup)
        .addProperty("Radius", &GCAI_ChangeHintGroup::GetRadius, &GCAI_ChangeHintGroup::SetRadius)
        .addProperty("Parent", &GCAI_ChangeHintGroup::GetParent, &GCAI_ChangeHintGroup::SetParent)
        .addFunction("ToPtr", &GCAI_ChangeHintGroup::ToPtr)
        .addFunction("IsValid", &GCAI_ChangeHintGroup::IsValid)
        .endClass();
}