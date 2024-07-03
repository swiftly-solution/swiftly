#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfig::GCModelConfig(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfig::GCModelConfig(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelConfig::GetConfigName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfig", "m_ConfigName").Get();
}
void GCModelConfig::SetConfigName(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfig", "m_ConfigName", false, CUtlString(value.c_str()));
}
std::vector<GCModelConfigElement*> GCModelConfig::GetElements() const {
    CUtlVector<GCModelConfigElement*>* vec = GetSchemaValue<CUtlVector<GCModelConfigElement*>*>(m_ptr, "CModelConfig", "m_Elements"); std::vector<GCModelConfigElement*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCModelConfig::SetElements(std::vector<GCModelConfigElement*> value) {
    SetSchemaValueCUtlVector<GCModelConfigElement*>(m_ptr, "CModelConfig", "m_Elements", false, value);
}
bool GCModelConfig::GetTopLevel() const {
    return GetSchemaValue<bool>(m_ptr, "CModelConfig", "m_bTopLevel");
}
void GCModelConfig::SetTopLevel(bool value) {
    SetSchemaValue(m_ptr, "CModelConfig", "m_bTopLevel", false, value);
}
std::string GCModelConfig::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfig::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCModelConfig(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfig>("CModelConfig")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ConfigName", &GCModelConfig::GetConfigName, &GCModelConfig::SetConfigName)
        .addProperty("Elements", &GCModelConfig::GetElements, &GCModelConfig::SetElements)
        .addProperty("TopLevel", &GCModelConfig::GetTopLevel, &GCModelConfig::SetTopLevel)
        .addFunction("ToPtr", &GCModelConfig::ToPtr)
        .addFunction("IsValid", &GCModelConfig::IsValid)
        .endClass();
}