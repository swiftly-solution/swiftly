#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_RandomPick::GCModelConfigElement_RandomPick(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_RandomPick::GCModelConfigElement_RandomPick(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlString> GCModelConfigElement_RandomPick::GetChoices() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CModelConfigElement_RandomPick", "m_Choices"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCModelConfigElement_RandomPick::SetChoices(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CModelConfigElement_RandomPick", "m_Choices", false, value);
}
std::vector<float32> GCModelConfigElement_RandomPick::GetChoiceWeights() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CModelConfigElement_RandomPick", "m_ChoiceWeights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCModelConfigElement_RandomPick::SetChoiceWeights(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CModelConfigElement_RandomPick", "m_ChoiceWeights", false, value);
}
std::string GCModelConfigElement_RandomPick::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_RandomPick::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_RandomPick::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_RandomPick::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_RandomPick(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_RandomPick>("CModelConfigElement_RandomPick")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Choices", &GCModelConfigElement_RandomPick::GetChoices, &GCModelConfigElement_RandomPick::SetChoices)
        .addProperty("ChoiceWeights", &GCModelConfigElement_RandomPick::GetChoiceWeights, &GCModelConfigElement_RandomPick::SetChoiceWeights)
        .addProperty("Parent", &GCModelConfigElement_RandomPick::GetParent, &GCModelConfigElement_RandomPick::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_RandomPick::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_RandomPick::IsValid)
        .endClass();
}