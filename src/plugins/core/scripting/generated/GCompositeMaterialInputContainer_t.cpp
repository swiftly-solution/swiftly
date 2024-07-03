#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCompositeMaterialInputContainer_t::GCompositeMaterialInputContainer_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCompositeMaterialInputContainer_t::GCompositeMaterialInputContainer_t(void *ptr) {
    m_ptr = ptr;
}
bool GCompositeMaterialInputContainer_t::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputContainer_t", "m_bEnabled");
}
void GCompositeMaterialInputContainer_t::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_bEnabled", true, value);
}
uint64_t GCompositeMaterialInputContainer_t::GetCompositeMaterialInputContainerSourceType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CompositeMaterialInputContainer_t", "m_nCompositeMaterialInputContainerSourceType");
}
void GCompositeMaterialInputContainer_t::SetCompositeMaterialInputContainerSourceType(uint64_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_nCompositeMaterialInputContainerSourceType", true, value);
}
std::string GCompositeMaterialInputContainer_t::GetStrAttrName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputContainer_t", "m_strAttrName").Get();
}
void GCompositeMaterialInputContainer_t::SetStrAttrName(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_strAttrName", true, CUtlString(value.c_str()));
}
std::string GCompositeMaterialInputContainer_t::GetStrAlias() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputContainer_t", "m_strAlias").Get();
}
void GCompositeMaterialInputContainer_t::SetStrAlias(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_strAlias", true, CUtlString(value.c_str()));
}
std::vector<GCompositeMaterialInputLooseVariable_t> GCompositeMaterialInputContainer_t::GetLooseVariables() const {
    CUtlVector<GCompositeMaterialInputLooseVariable_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialInputLooseVariable_t>*>(m_ptr, "CompositeMaterialInputContainer_t", "m_vecLooseVariables"); std::vector<GCompositeMaterialInputLooseVariable_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompositeMaterialInputContainer_t::SetLooseVariables(std::vector<GCompositeMaterialInputLooseVariable_t> value) {
    SetSchemaValueCUtlVector<GCompositeMaterialInputLooseVariable_t>(m_ptr, "CompositeMaterialInputContainer_t", "m_vecLooseVariables", true, value);
}
std::string GCompositeMaterialInputContainer_t::GetStrAttrNameForVar() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputContainer_t", "m_strAttrNameForVar").Get();
}
void GCompositeMaterialInputContainer_t::SetStrAttrNameForVar(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_strAttrNameForVar", true, CUtlString(value.c_str()));
}
bool GCompositeMaterialInputContainer_t::GetExposeExternally() const {
    return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputContainer_t", "m_bExposeExternally");
}
void GCompositeMaterialInputContainer_t::SetExposeExternally(bool value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_bExposeExternally", true, value);
}
std::string GCompositeMaterialInputContainer_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCompositeMaterialInputContainer_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCompositeMaterialInputContainer_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterialInputContainer_t>("CompositeMaterialInputContainer_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GCompositeMaterialInputContainer_t::GetEnabled, &GCompositeMaterialInputContainer_t::SetEnabled)
        .addProperty("CompositeMaterialInputContainerSourceType", &GCompositeMaterialInputContainer_t::GetCompositeMaterialInputContainerSourceType, &GCompositeMaterialInputContainer_t::SetCompositeMaterialInputContainerSourceType)
        .addProperty("StrAttrName", &GCompositeMaterialInputContainer_t::GetStrAttrName, &GCompositeMaterialInputContainer_t::SetStrAttrName)
        .addProperty("StrAlias", &GCompositeMaterialInputContainer_t::GetStrAlias, &GCompositeMaterialInputContainer_t::SetStrAlias)
        .addProperty("LooseVariables", &GCompositeMaterialInputContainer_t::GetLooseVariables, &GCompositeMaterialInputContainer_t::SetLooseVariables)
        .addProperty("StrAttrNameForVar", &GCompositeMaterialInputContainer_t::GetStrAttrNameForVar, &GCompositeMaterialInputContainer_t::SetStrAttrNameForVar)
        .addProperty("ExposeExternally", &GCompositeMaterialInputContainer_t::GetExposeExternally, &GCompositeMaterialInputContainer_t::SetExposeExternally)
        .addFunction("ToPtr", &GCompositeMaterialInputContainer_t::ToPtr)
        .addFunction("IsValid", &GCompositeMaterialInputContainer_t::IsValid)
        .endClass();
}