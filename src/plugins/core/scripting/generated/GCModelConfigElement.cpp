#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement::GCModelConfigElement(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement::GCModelConfigElement(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelConfigElement::GetElementName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement", "m_ElementName").Get();
}
void GCModelConfigElement::SetElementName(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement", "m_ElementName", false, CUtlString(value.c_str()));
}
std::vector<GCModelConfigElement*> GCModelConfigElement::GetNestedElements() const {
    CUtlVector<GCModelConfigElement*>* vec = GetSchemaValue<CUtlVector<GCModelConfigElement*>*>(m_ptr, "CModelConfigElement", "m_NestedElements"); std::vector<GCModelConfigElement*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCModelConfigElement::SetNestedElements(std::vector<GCModelConfigElement*> value) {
    SetSchemaValueCUtlVector<GCModelConfigElement*>(m_ptr, "CModelConfigElement", "m_NestedElements", false, value);
}
std::string GCModelConfigElement::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCModelConfigElement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement>("CModelConfigElement")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ElementName", &GCModelConfigElement::GetElementName, &GCModelConfigElement::SetElementName)
        .addProperty("NestedElements", &GCModelConfigElement::GetNestedElements, &GCModelConfigElement::SetNestedElements)
        .addFunction("ToPtr", &GCModelConfigElement::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement::IsValid)
        .endClass();
}