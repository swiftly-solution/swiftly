#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_UserPick::GCModelConfigElement_UserPick(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_UserPick::GCModelConfigElement_UserPick(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlString> GCModelConfigElement_UserPick::GetChoices() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CModelConfigElement_UserPick", "m_Choices"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCModelConfigElement_UserPick::SetChoices(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CModelConfigElement_UserPick", "m_Choices", false, value);
}
std::string GCModelConfigElement_UserPick::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_UserPick::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_UserPick::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_UserPick::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_UserPick(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_UserPick>("CModelConfigElement_UserPick")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Choices", &GCModelConfigElement_UserPick::GetChoices, &GCModelConfigElement_UserPick::SetChoices)
        .addProperty("Parent", &GCModelConfigElement_UserPick::GetParent, &GCModelConfigElement_UserPick::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_UserPick::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_UserPick::IsValid)
        .endClass();
}